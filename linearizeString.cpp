#include <string>
#include <iostream>

#include "buildTree.h"
#include "linearizeString.h"

std::string linearizeString(std::string cutString) {
    std::string repString = cutString;
    repString.append(cutString);
    //repString.append("$");
    suffixTree tree = buildTree(repString);
    std::string lexicalString = lexDFS(0, repString, tree, 0);
    return lexicalString;
}

std::string lexDFS(int curNode, std::string repString, suffixTree tree, int lexStringlength) {
    std::string lexString = "";
    int nextNode = 0;
    int start, end;
    int charsToAdd = repString.length()/2 - lexStringlength;

    if(!charsToAdd)
        return lexString;

    // Find the edge from @curNode that starts with the lexically smallest value
    for(auto it = tree.edgeHash.begin(); it != tree.edgeHash.end(); it++) {
        if(it->second.startNode == curNode) {
            if(!nextNode) {
                nextNode = it->second.endNode;
                start = it->second.startLabelIndex;
                end = it->second.endLabelIndex;
            }
            else if(repString[it->second.startLabelIndex] < repString[start]) {
                nextNode = it->second.endNode;
                start = it->second.startLabelIndex;
                end = it->second.endLabelIndex;
            }
        }
    }
    
    // Append edge label
    if(end - start + 1 > charsToAdd) {
        // End of lexString is in middle of edge label
        std::cout << start << std::endl;
        std::cout << repString.substr(start, charsToAdd) << std::endl;
        lexString.append(repString.substr(start, charsToAdd));
        
    }else { 
        // Append the entire edge label
        lexString.append(repString.substr(start, end - start + 1));
        // Recursive call to next node
        lexString.append(lexDFS(nextNode, repString, tree, lexString.length()));
    }
    
    return lexString;
}
