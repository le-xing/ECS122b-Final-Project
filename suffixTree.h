#ifndef SUFFIXTREE_H
#define SUFFIXTREE_H 

#include "node.h"
#include "edge.h"
#include <iostream>
#include <unordered_map>

class suffixTree {
    public:
        int rootNode;   // Origin of the suffix tree
        int startIndex; // Starting index of the string represented.
        int endIndex;   // End index of the string represented.
        int noOfNodes; //private?
        Node* nodeArray;
        unordered_map <long, Edge> edgeHash; //private?
        string input; //private?
        // Constructor
        suffixTree() :
            rootNode(0), 
            startIndex(-1),
            endIndex(-1),
            noOfNodes(1){};
        suffixTree(int root, int start, int end) :
            rootNode(root),
            startIndex(start),
            endIndex(end),
            noOfNodes(1) {};
        // Real means that the suffix string ends at a node and thus the
        // remaining string on that edge would be an empty string.
        bool endReal() {return startIndex > endIndex;} 
        // Img means that the suffixTree of current string ends on an imaginary
        // node, which means in between an edge. 
        bool endImg() {return endIndex >= startIndex;} 
        void migrateToClosestParent();
        void insertEdge(Edge);
        void removeEdge(Edge);
        Edge findEdge(int node, int asciiChar);
        void printAllEdges();
};

#endif                                                                             
