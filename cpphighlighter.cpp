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

using namespace Qt::Literals;

inline QRegularExpression operator""_re(const char16_t* str, size_t size) noexcept {
    return QRegularExpression(QString(QStringPrivate(nullptr, const_cast<char16_t*>(str), qsizetype(size))));
}

CppHighlighter::CppHighlighter(QTextDocument* parent)
    : QSyntaxHighlighter(parent) {
    QStringList keywordPatterns{
        uR"(\bchar\b)"_s,
        uR"(\bclass\b)"_s,
        uR"(\bconst\b)"_s,
        uR"(\bdouble\b)"_s,
        uR"(\benum\b)"_s,
        uR"(\bexplicit\b)"_s,
        uR"(\bfriend\b)"_s,
        uR"(\binline\b)"_s,
        uR"(\bint\b)"_s,
        uR"(\blong\b)"_s,
        uR"(\bnamespace\b)"_s,
        uR"(\boperator\b)"_s,
        uR"(\bprivate\b)"_s,
        uR"(\bprotected\b)"_s,
        uR"(\bpublic\b)"_s,
        uR"(\bshort\b)"_s,
        uR"(\bsignals\b)"_s,
        uR"(\bsigned\b)"_s,
        uR"(\bslots\b)"_s,
        uR"(\bstatic\b)"_s,
        uR"(\bstruct\b)"_s,
        uR"(\btemplate\b)"_s,
        uR"(\btypedef\b)"_s,
        uR"(\btypename\b)"_s,
        uR"(\bunion\b)"_s,
        uR"(\bunsigned\b)"_s,
        uR"(\bvirtual\b)"_s,
        uR"(\bvoid\b)"_s,
        uR"(\bvolatile\b)"_s,
        uR"(\bbool\b)"_s,
    };

    using RE = QRegularExpression;
    keywordFormat.setForeground(Qt::darkBlue);
    for(const auto& pattern: keywordPatterns) {
        highlightingRules.emplace_back(RE(pattern), keywordFormat);
    }
    {
        classFormat.setForeground(Qt::darkMagenta);
        highlightingRules.emplace_back(uR"(\bQ[A-Za-z]+\b)"_re, classFormat);
    }
    {
        singleLineCommentFormat.setForeground(Qt::red);
        highlightingRules.emplace_back(uR"(//[^\n]*)"_re, singleLineCommentFormat);
    }
    {
        multiLineCommentFormat.setForeground(Qt::red);
        quotationFormat.setForeground(Qt::darkGreen);
        highlightingRules.emplace_back(uR"(\".*\")"_re, quotationFormat);
    }
    {
        functionFormat.setForeground(Qt::blue);
        highlightingRules.emplace_back(uR"(\b[A-Za-z0-9_]+(?=\())"_re, functionFormat);
    }
    {
        commentStartExpression = uR"(/\*)"_re;
        commentEndExpression = uR"(\*/)"_re;
    }
}

void CppHighlighter::highlightBlock(const QString& text) {
    for(auto&& rule: highlightingRules) {
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while(matchIterator.hasNext()) {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }

    setCurrentBlockState(0);

    int startIndex = 0;
    if(previousBlockState() != 1)
        startIndex = text.indexOf(commentStartExpression);

    while(startIndex >= 0) {
        QRegularExpressionMatch match = commentEndExpression.match(text, startIndex);
        int endIndex = match.capturedStart();
        int commentLength = 0;
        if(endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex + match.capturedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = text.indexOf(commentStartExpression, startIndex + commentLength);
    }
}
