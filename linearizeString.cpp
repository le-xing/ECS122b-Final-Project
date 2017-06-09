#include <string>
#include <iostream>

#include "buildTree.h"
#include "linearizeString.h"

// Linearize circular string
// Input: A circular string that has been cut to be linear
// Output: Lexically smallest representation of the circular string
std::string linearizeString(std::string cutString) {
    std::string repString = cutString;
    repString.append(cutString);
    suffixTree tree = buildTree(repString);
    std::string lexicalString = lexDFS(0, repString, tree, 0);
    return lexicalString;
}

// Lexical DFS 
// Input: Node to start search from, the representative string of the circular
//        string, the tree to search, and the length of the lexically smallest
//        string so far;
// Ouput: Lexically smallest string starting at @curNode      
std::string lexDFS(int curNode, 
    std::string repString, 
    suffixTree tree, 
    int lexStringlength) {
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
        // lexString ends in middle of edge label; append part of edge label
        lexString.append(repString.substr(start, charsToAdd));
        
    }else { 
        // Append the entire edge label
        lexString.append(repString.substr(start, end - start + 1));
        // Recursive call to next node
        lexString.append(lexDFS(nextNode, repString, tree, lexString.length()));
    }
    
    return lexString;
}
