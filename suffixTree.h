#ifndef SUFFIXTREE_H
#define SUFFIXTREE_H 

#include <iostream>
#include <unordered_map>

class Node {
public:
    int suffixNode;
    
    Node () : 
        suffixNode(-1) {};
    
    ~Node() {
    }
};

class Edge {
public:
    // Edges are hash-searched on the basis of startNode.
    // startNode = -1 means that this edge is not valid yet.
    int startNode;
    int endNode;
    int startLabelIndex;
    int endLabelIndex;
    
    // Constructors.
    Edge () : startNode(-1) {};
    // everytime a new edge is created, a new node is also created and thus the
    // endNode is declared as below.
    Edge (int start, int end, int first, int last) :
        startNode (start),
        endNode (end),
        startLabelIndex (first),
        endLabelIndex (last) {};
    // Destructor
    ~Edge() {
      //  cout << "destroying edge " << startNode << " " << endNode << endl;
    }        

};        

class suffixTree {
    public:
        int rootNode;   // Origin of the suffix tree
        int startIndex; // Starting index of the string represented.
        int endIndex;   // End index of the string represented.
        int noOfNodes; //private?
        Node* nodeArray;
        std::unordered_map <long, Edge> edgeHash; //private?
        std::string input; //private?
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
