#include "buildTree.h"
#include <cassert>

/*
 * Break an edge so as to add new string at a specific point.
 */
int breakEdge(suffixTree &s, Edge &e) {
    // Remove the edge 
    s.removeEdge(e);

    Edge *newEdge = new Edge(s.rootNode, s.noOfNodes++, e.startLabelIndex, 
                             e.startLabelIndex + s.endIndex - s.startIndex);
    s.insertEdge(*newEdge);
    // Add the suffix link for the new node.
    s.nodeArray[newEdge->endNode].suffixNode = s.rootNode;
    e.startLabelIndex += s.endIndex - s.startIndex + 1;
    e.startNode = newEdge->endNode;
    s.insertEdge(e);
    return newEdge->endNode;
}

/*
 * Main function which will carry out all the different phases of the Ukkonen's
 * algorithm. Through suffixTree we'll maintain the current position in the tree
 * and then add the prefix 0 -> lastIndex in the tree created in the previous
 * iteration.
 */
void carryPhase(suffixTree &tree, int lastIndex) {
   // cout << "Phase " << lastIndex << " Adding " << Input.substr(0, lastIndex + 1) << endl;
    int parentNode;
    // to keep track of the last encountered node.
    // Used for creating the suffix link.
    int previousParentNode = -1;
    while (true) {
        // First we try to match an edge for this, if there is one edge and all
        // other subsequent suffixs would already be there.
        Edge e;
        parentNode = tree.rootNode;

        if (tree.endReal() ) {
            e = tree.findEdge(tree.rootNode, tree.input[lastIndex]);
            if (e.startNode != -1)
                break;
        }

        // If previous tree ends in between an edge, then we need to find that
        // edge and match after that. 
        else {
            e = tree.findEdge(tree.rootNode, tree.input[tree.startIndex]);
            int diff = tree.endIndex - tree.startIndex;
            if (tree.input[e.startLabelIndex + diff + 1] == tree.input[lastIndex])
                // We have a match
                break;
            //If match was not found this way, then we need to break this edge
            // and add a node and insert the string.
      //      cout << " breaking edge " << endl; 
            parentNode = breakEdge(tree, e);
        }

        // We have not matchng edge at this point, so we need to create a new
        // one, add it to the tree at parentNode position and then insert it
        // into the hash table.
        //
        // We are creating a new node here, which means we also need to update
        // the suffix link here. Suffix link from the last visited node to the
        // newly created node.
      //  cout << "adding new edge" << endl;
        Edge *newEdge = new Edge(parentNode, tree.noOfNodes++, lastIndex, tree.input.length() - 1);
        tree.insertEdge(*newEdge);
        if (previousParentNode > 0)
            tree.nodeArray[previousParentNode].suffixNode = parentNode;
        previousParentNode = parentNode;

        // Move to next suffix, i.e. next extension.
        if (tree.rootNode == 0)
            tree.startIndex++;
        else {
            tree.rootNode = tree.nodeArray[tree.rootNode].suffixNode;
      //      printf("using suffix link while adding %d %d\n",tree.rootNode, nodeArray[tree.rootNode].suffixNode);
        }
        tree.migrateToClosestParent();
    }

    if (previousParentNode > 0)
        tree.nodeArray[previousParentNode].suffixNode = parentNode;
    tree.endIndex++;
    tree.migrateToClosestParent();
}

bool search(string pattern, suffixTree tree) {
    int len = pattern.length();
    // Starting from 0 we start searching the pattern.
    Edge e = tree.findEdge(0, pattern[0]);
    // index until where we have matched on edge.
    int iter = 0;
    int i = -1;
    if (e.startNode != -1) {
        while(i < len) {
            cout << "Search:\tEdge: " << e.startNode << " " << e.endNode << " : " 
                << tree.input[e.startLabelIndex]  << " " << tree.input[e.endLabelIndex] << " I: " << i << endl;
            // Match the pattern on this edge.
            iter = 0;
            // Match this edge as much as possible.
            while (e.endLabelIndex >= e.startLabelIndex + iter)   
                    {
                        cout << "Search:\tmatching " << tree.input[e.startLabelIndex + iter] << " " 
                             << pattern[i + iter + 1]
                            << " at index: " << e.startLabelIndex + iter << endl;
                        // If character matches we increase the iterator
                        // otherwise we are done. No match.
                        if (tree.input[e.startLabelIndex + iter] == pattern[i + iter + 1]) { 
                            iter++;
                            // If we have a match in the middle then we are done.
                            if (i + iter  + 1 >= len) {
                                cout << "Search:\tWe have a match ending at " 
                                     << e.startLabelIndex + iter  - 1 << endl;
                                return true;
                            }
                        }
                        else {
                            cout << "Search:\tMatch not found, matched only upto index:" << i+iter << endl;
                            return false;     
                        }
                   }
            // We have done all possible matches on this edge. We can proceed
            // only if the entire label matches.
            assert(iter = (e.endLabelIndex - e.startLabelIndex + 1));

            // Now we need to find another edge to match.
            e = tree.findEdge(e.endNode, pattern[i + iter + 1]);
            if (e.startNode == -1) {
                cout << "Search:\tMatch not found, matched only upto " << i + iter  
                     << " " << pattern[i + iter + 1]<< endl;
                return false;    
                }
            i+=(iter);
        }
    }
    cout << "Search:\tMatched :D " << iter << " " << pattern << endl;
    return true;
}

