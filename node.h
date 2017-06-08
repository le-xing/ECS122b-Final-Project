#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

class Node {
public:
    int suffixNode;
    
    Node () : 
        suffixNode(-1) {};
    
    ~Node() {
    }
};
#endif
