#ifndef BUILDTREE_H
#define BUILDTREE_H

#include "suffixTree.h"
#include <string>

int breakEdge(suffixTree &s, Edge &e);
void carryPhase(suffixTree &tree, int lastIndex);
bool search(std::string pattern, suffixTree tree);
void buildTree(const std::string& S, suffixTree* tree);

#endif
