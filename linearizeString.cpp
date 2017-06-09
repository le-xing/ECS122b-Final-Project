#include <string.h>
#include <iostream>

#include "buildTree.h"
#include "linearizeString.h"

std::sting linearizeString(std::string cutString) {
    std::string repString = cutString;
    repString.append(cutString);
    repString.append("$");
    suffixTree tree = buildTree(repString);
    std::string lexicalString = lexDFS(0, tree, cutString, 0);
    return lexicalString;
}

std::string lexDFS(int curNode, std::string cutString, suffixTree tree, int lexStringlength) {
std::cout << "starting with lex length " << lexStringlength << std::endl;
    std::string lexString = "";
    Edge* curEdge = NULL;
    int charsToAdd = cutString.length() - lexStringlength;

    if(!charsToAdd)
        return lexString;

    // Find the edge from @curNode that starts with the lexically smallest value
    for(auto it = tree.edgeHash.begin(); it != tree.edgeHash.end(); it++) {
        if(it->second.startNode == curNode) {
            if(!curEdge)
                curEdge = it->second;
            else if(cutString[it->second.startIndex] < cutString[curEdge->startIndex])
                curEdge = it->second;
        }
    }

    // Append edge label
    if(curEdge->endIndex - curEdge->startIndex + 1 > charsToAdd) { 
        // End of lexString is in middle of edge label
        lexString.append(cutString.substring(curEdge->startIndex, charsToAdd));
        
    }else { 
        // Append the entire edge label
        lexString.append(cutString.substr(curEdge->startIndex, 
            (curEdge->endIndex - curEdge->startIndex + 1));
        // Recursive call to next node
        lexString.append(DFS(curEdge->endNode, cutString, tree, lexString.length()));
    }

std::cout << "Added from one DFS call " << lexString << std::endl;
    return lexString;
}
