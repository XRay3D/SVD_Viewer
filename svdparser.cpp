#include "svdparser.h"
#include <QDebug>
#include <QFile>
#include <QtXml/QDomDocument>

SvdParser::SvdParser(const QString& fileName)
{
    QDomDocument doc("mydocument");
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
        return;
    if (!doc.setContent(&file)) {
        file.close();
        return;
    }
    file.close();

    QDomElement docElem = doc.documentElement();
    node_ = new SvdNode({ "Name", "Value", "Attributes" });
    auto domNode = docElem.firstChild();
    nextNode(node_, domNode);
}

void SvdParser::nextNode(SvdNode* svdNode, QDomNode& domNode)
{
    while (!domNode.isNull()) {
        QList<QVariant> list;
        {
            QDomNamedNodeMap attributeMap = domNode.attributes();
            QStringList attributes;
            for (int i = 0; i < attributeMap.count(); ++i) {
                QDomNode attribute = attributeMap.item(i);
                attributes << attribute.nodeName() + R"(=\")" + attribute.nodeValue() + '"';
            }
            attributes.join(' ');
            list = { domNode.nodeName(), domNode.nodeValue(), attributes.join(' ') };
        }
        if (svdNode->parent() && svdNode->parent()->data_[0].toString() == "peripheral") {
            svdNode->parent()->data_[1] = domNode.nodeValue();
        }
        SvdNode* node_ {};
        QDomElement e { domNode.toElement() }; // попытка преобразовать узел в элемент
        if (!e.isNull()) { // узел действительно является элементом
            node_ = new SvdNode { list, svdNode };
            auto domNode_ { domNode.firstChild() };
            nextNode(node_, domNode_);
//            if (svdNode->data_[0] == "peripheral")
//                qDebug() << svdNode->data_ << node_->child(0);
        } else if (domNode.nodeName() == "#text") {
            //svdNode->data_[1] = domNode.nodeValue();
            return;
        }

        if (node_)
            svdNode->appendChild(node_);
        domNode = domNode.nextSibling();
    }
}
