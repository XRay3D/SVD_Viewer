#include "svdparser.h"
#include "peripherals.h"
#include <QDebug>
#include <QFile>
#include <QtXml/QDomDocument>

SvdParser::SvdParser(const QString& fileName, Peripherals& peripherals)
    : peripherals { peripherals }
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

        SvdNode* node_ {};
        if (QDomElement e { domNode.toElement() } /*попытка преобразовать узел в элемент*/; !e.isNull()) { // узел действительно является элементом
            node_ = new SvdNode { list, svdNode };
            auto domNode_ { domNode.firstChild() };
            nextNode(node_, domNode_);
            if (svdNode->data_[0] == "peripheral" && svdNode->child(0)) {
                svdNode->data_[1] = svdNode->child(0)->data(1);
                peripherals.add(svdNode->data_[1].toString());
            }
        } else if (domNode.nodeName() == "#text") {
            svdNode->data_[1] = domNode.nodeValue();
            if (peripherals) {
                /*  */ if (svdNode->data_[0].toString() == "description") {
                    peripherals.current().description = domNode.nodeValue();
                } else if (svdNode->data_[0].toString() == "groupName") {
                    peripherals.current().groupName = domNode.nodeValue();
                } else if (svdNode->data_[0].toString() == "baseAddress") {
                    peripherals.current().baseAddress = domNode.nodeValue();
                } else if (svdNode->data_[0].toString() == "") {
                }
            }
            return;
        }

        if (node_)
            svdNode->appendChild(node_);
        domNode = domNode.nextSibling();
    }
}
