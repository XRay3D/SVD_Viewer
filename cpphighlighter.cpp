/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "cpphighlighter.h"

CppHighlighter::CppHighlighter(QTextDocument* parent)
    : QSyntaxHighlighter(parent)
{

    QStringList keywordPatterns {
        R"(\bchar\b)",
        R"(\bclass\b)",
        R"(\bconst\b)",
        R"(\bdouble\b)",
        R"(\benum\b)",
        R"(\bexplicit\b)",
        R"(\bfriend\b)",
        R"(\binline\b)",
        R"(\bint\b)",
        R"(\blong\b)",
        R"(\bnamespace\b)",
        R"(\boperator\b)",
        R"(\bprivate\b)",
        R"(\bprotected\b)",
        R"(\bpublic\b)",
        R"(\bshort\b)",
        R"(\bsignals\b)",
        R"(\bsigned\b)",
        R"(\bslots\b)",
        R"(\bstatic\b)",
        R"(\bstruct\b)",
        R"(\btemplate\b)",
        R"(\btypedef\b)",
        R"(\btypename\b)",
        R"(\bunion\b)",
        R"(\bunsigned\b)",
        R"(\bvirtual\b)",
        R"(\bvoid\b)",
        R"(\bvolatile\b)",
        R"(\bbool\b)",
    };

    using RE = QRegularExpression;
    keywordFormat.setForeground(Qt::darkBlue);
    for (const auto& pattern : keywordPatterns) {
        highlightingRules.emplace_back(RE(pattern), keywordFormat);
    }
    {
        classFormat.setForeground(Qt::darkMagenta);
        highlightingRules.emplace_back(RE(R"(\bQ[A-Za-z]+\b)"), classFormat);
    }
    {
        singleLineCommentFormat.setForeground(Qt::red);
        highlightingRules.emplace_back(RE(R"(//[^\n]*)"), singleLineCommentFormat);
    }
    {
        multiLineCommentFormat.setForeground(Qt::red);
        quotationFormat.setForeground(Qt::darkGreen);
        highlightingRules.emplace_back(RE(R"(\".*\")"), quotationFormat);
    }
    {
        functionFormat.setForeground(Qt::blue);
        highlightingRules.emplace_back(RE(R"(\b[A-Za-z0-9_]+(?=\())"), functionFormat);
    }
    {
        commentStartExpression = RE(R"(/\*)");
        commentEndExpression = RE(R"(\*/)");
    }
}

void CppHighlighter::highlightBlock(const QString& text)
{
    for (auto&& rule : highlightingRules) {
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext()) {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }

    setCurrentBlockState(0);

    int startIndex = 0;
    if (previousBlockState() != 1)
        startIndex = text.indexOf(commentStartExpression);

    while (startIndex >= 0) {

        QRegularExpressionMatch match = commentEndExpression.match(text, startIndex);
        int endIndex = match.capturedStart();
        int commentLength = 0;
        if (endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex
                + match.capturedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = text.indexOf(commentStartExpression, startIndex + commentLength);
    }
}
