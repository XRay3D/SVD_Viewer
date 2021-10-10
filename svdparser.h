#pragma once

#include "svdnode.h"

class Peripherals;
class QDomNode;

class SvdParser {
    SvdNode* node_ {};
    void nextNode(SvdNode* svdNode, QDomNode& domNode);
    Peripherals& peripherals;
    bool isPeripheral {};

public:
    SvdParser(const QString& fileName, Peripherals& peripherals);
    operator SvdNode*() const { return node_; }
};
