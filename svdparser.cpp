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

QRegularExpression re(R"(\s+)");

void SvdParser::nextNode(SvdNode* const svdNodeParent, QDomNode& domNode)
{
    while (!domNode.isNull()) {
        QStringList list;
        {
            QDomNamedNodeMap attributeMap = domNode.attributes();
            QStringList attributes;
            for (int i = 0; i < attributeMap.count(); ++i) {
                QDomNode attribute = attributeMap.item(i);
                attributes << attribute.nodeName() + R"( = ")" + attribute.nodeValue() + '"';
            }
            attributes.join(' ');
            list = QStringList { domNode.nodeName(), domNode.nodeValue().replace(re, " "), attributes.join(' ') };
        }

        SvdNode* svdNodeCurrent {};
        if (QDomElement e { domNode.toElement() } /*попытка преобразовать узел в элемент*/; !e.isNull()) { // узел действительно является элементом
            svdNodeCurrent = new SvdNode { list, svdNodeParent };
            auto domNode_ { domNode.firstChild() };
            nextNode(svdNodeCurrent, domNode_);
        } else if (domNode.nodeName() == "#text") {
            svdNodeParent->data_[1] = domNode.nodeValue().replace(re, " ");
            if (svdNodeParent->data_[0] == "name" && svdNodeParent->parent_->parent_)
                svdNodeParent->parent_->data_[1] = list[1];
            return;
        }
        if (svdNodeCurrent) {
            svdNodeParent->appendChild(svdNodeCurrent);
            if (svdNodeParent->childs_.size()) {
                static SvdNode* var;
                var = svdNodeParent->childs_.back();
                auto assign = [](auto& field) { field = var->data_[1].toLocal8Bit(); };
                if (svdNodeParent->data_[0] == "peripheral") {
                    auto& pls = peripherals.peripherals;
                    pls.reserve(1000);
                    if (var->data_[0] == "name") {
                        pls.push_back({});
                        assign(pls.back().name);
                        static QRegularExpression re { "derivedFrom = \"(\\S+)\"" };
                        if (svdNodeParent->data_[2].isEmpty())
                            peripherals.peripheralsMap[var->data_[1]] = &pls.back();
                        else if (auto match { re.match(svdNodeParent->data_[2]) }; match.hasMatch())
                            pls.back().peripheral = peripherals.peripheralsMap[match.captured(1)];
                    } else if (var->data_[0] == "description")
                        assign(pls.back().description);
                    else if (var->data_[0] == "groupName") {
                        assign(pls.back().groupName);
                        if (!peripherals.groupMap.contains(var->data_[1])) {
                            peripherals.groupMap[var->data_[1]].reserve(20);
                            peripherals.groupMap[var->data_[1]].emplace_back(&pls.back());
                        }
                    } else if (var->data_[0] == "baseAddress")
                        assign(pls.back().baseAddress);
                } else if (svdNodeParent->data_[0] == "register") {
                    auto& registers = peripherals.current().registers;
                    registers.reserve(100);
                    if /**/ (var->data_[0] == "name")
                        registers.push_back({}), assign(registers.back().name);
                    else if (var->data_[0] == "displayName")
                        assign(registers.back().displayName);
                    else if (var->data_[0] == "description")
                        assign(registers.back().description);
                    else if (var->data_[0] == "addressOffset")
                        assign(registers.back().addressOffset);
                    else if (var->data_[0] == "size")
                        assign(registers.back().size);
                    else if (var->data_[0] == "access")
                        assign(registers.back().access);
                    else if (var->data_[0] == "resetValue")
                        assign(registers.back().resetValue);
                } else if (svdNodeParent->data_[0] == "field") {
                    auto& fields = peripherals.current().registers.back().fields;
                    fields.reserve(32);
                    if /**/ (var->data_[0] == "name")
                        fields.push_back({}), assign(fields.back().name);
                    else if (var->data_[0] == "description")
                        assign(fields.back().description);
                    else if (var->data_[0] == "bitOffset")
                        assign(fields.back().bitOffset);
                    else if (var->data_[0] == "bitWidth")
                        assign(fields.back().bitWidth);
                } else if (svdNodeParent->data_[0] == "interrupt") {
                    auto& interrupt = peripherals.current().interrupts;
                    interrupt.reserve(32);
                    if /**/ (var->data_[0] == "name")
                        interrupt.push_back({}), assign(interrupt.back().name);
                    else if (var->data_[0] == "description")
                        assign(interrupt.back().description);
                    else if (var->data_[0] == "value")
                        assign(interrupt.back().value);
                }
            }
        }
        domNode = domNode.nextSibling();
    }
}
