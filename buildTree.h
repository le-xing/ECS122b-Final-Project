#ifndef BUILDTREE_H
#define BUILDTREE_H

#include "suffixTree.h"
#include "edge.h"
#include "node.h"

int breakEdge(suffixTree &s, Edge &e);
void carryPhase(suffixTree &tree, int lastIndex);
bool search(string pattern, suffixTree tree);
void buildTree(const std::string& S, suffixTree* tree);

#endif
