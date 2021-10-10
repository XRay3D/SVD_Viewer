#pragma once

#include "svdnode.h"

class QDomNode;

class SvdParser {
    SvdNode* node_ {};
    void nextNode(SvdNode* svdNode, QDomNode &domNode);

public:
    SvdParser(const QString& fileName);
    operator SvdNode*() const { return node_; }
};
