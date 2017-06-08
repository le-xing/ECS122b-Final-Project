#include "suffixTree.h"
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <chrono>
using namespace std;

long returnHashKey(int nodeID, int c) {
    return (long)(nodeID + (((long)c) << 56));
}
/*
 * Insert an edge into the suffix tree
 */
void suffixTree::insertEdge(Edge edge) {
    long key = returnHashKey(edge.startNode, input[edge.startLabelIndex]);
    edgeHash[key] = edge;
}

/*
 * Remove an edge from the suffix tree
 */
void suffixTree::removeEdge(Edge edge) {
     long key = returnHashKey(edge.startNode, input[edge.startLabelIndex]);
     edgeHash.erase(key);
}

/*
 * Find an edge in the hash table corresponding to NODE & ASCIICHAR
 */
Edge suffixTree::findEdge(int node, int asciiChar) {
    long key = returnHashKey(node, asciiChar);
    unordered_map<long, Edge>::const_iterator search = edgeHash.find(key);
    if (search != edgeHash.end()) {
        return edgeHash.at(key);
    }
    
    return Edge();
}

 // rootNode should be equal to the closest node to the end of the tree so
 // tht this can be used in the next iteration.
void suffixTree::migrateToClosestParent() {
    // If the current suffix tree is ending on a node, this condition is already
    // met.
    if (endReal()) {
   //     cout << "Nothing needs to be done for migrating" << endl;
    }
    else {
        Edge e = findEdge(rootNode, input[startIndex]);
        // Above will always return a valid edge as we call this method after
        // adding above.
        if(e.startNode == -1) {
            cout <<  rootNode << " " << startIndex << " " << input[startIndex] << endl;
        }
        assert(e.startNode != -1);
        int labelLength = e.endLabelIndex - e.startLabelIndex;

        // Go down
        while (labelLength <= (endIndex - startIndex)) {
            startIndex += labelLength + 1;
            rootNode = e.endNode;
            if (startIndex <= endIndex) {
                e = findEdge(e.endNode, input[startIndex]);
          if(e.startNode == -1) {
            cout <<  rootNode << " " << startIndex << " " << input[startIndex] << endl;
        }
               assert(e.startNode != -1);
                labelLength = e.endLabelIndex - e.startLabelIndex;
            }
        }
        
    }
}

/*
 * This function prints all the edges in the suffix tree.
 */
void suffixTree::printAllEdges() {
    int count = 0;
    cout << "StartNode\tEndNode\tSuffixLink\tFirstIndex\tlastIndex\tString" << endl;
    for (auto it = edgeHash.begin(); it != edgeHash.end(); it++) {
        cout << it -> second.startNode << "\t\t" << it -> second.endNode 
            << "\t\t" << nodeArray[it -> second.endNode].suffixNode
            << "\t\t" << it -> second.startLabelIndex 
            << "\t\t" << it -> second.endLabelIndex
            << "\t\t";
        count++;
        int head;
        if ((int)input.length() - 1 > it -> second.endLabelIndex)
            head = it -> second.endLabelIndex;
        else 
            head = input.length() - 1;
        for (int i = it -> second.startLabelIndex; i < head + 1; i++)
            cout << input[i];
        cout << endl;
    }
    cout << "Total edges: " << count << endl;
}


