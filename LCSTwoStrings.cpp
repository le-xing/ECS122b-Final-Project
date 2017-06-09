#include <string>

#include "buildTree.h"

std::string LCSTwoStrings(std::string S1, std::string S2) {
    std::string S = "";
    S.append(S1);
    S.append("$");
    S.append(S2);
    S.append("#");
    suffixTree generalTree = buildTree(S);
    generalTree.printAllEdges();
}
//TODO Unfinished logic
/*
std::string DFS(int curNode, suffixTree tree) {
    std::string LCS;
    int childNode = 0;
    int start, add;
    for(auto it = tree.edgeHash.begin(); it != tree.edgeHash.end(); it++) {
        if(it->second.startNode == curNode) {
            if(!childNode)
                childNode = it->second.endNode;
            //if edge had childNode that has edges from each string, CS found
            
        }
    }
    return S;
}

*/