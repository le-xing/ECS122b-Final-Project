#ifndef BUILDTREE_H
#define BUILDTREE_H

#include <string>

#include "suffixTree.h"

int breakEdge(suffixTree &s, Edge &e);
void carryPhase(suffixTree &tree, int lastIndex);
bool search(std::string pattern, suffixTree tree);
suffixTree buildTree(const std::string& S);
suffixTree addTree(suffixTree tree, const std::string& S);

#endif
