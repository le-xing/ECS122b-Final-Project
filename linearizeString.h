#ifndef LINEARIZE_STRING_H
#define LINEARIZE_STRING_H

#include <string>
#include "buildTree.h"
#include "suffixTree.h"

std::string linearizeString(std::string cutString);
std::string lexDFS(
    int curNode, 
    std::string cutString, 
    suffixTree tree, 
    int lexStringlength);

#endif


