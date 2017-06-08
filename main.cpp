#include "buildTree.h"

int main () {
    suffixTree tree(0, 0, -1);
    cout << "Enter String" << endl;
    getline(cin, tree.input);

    // Allocating memory to the array of nodes.
    tree.nodeArray = (Node *)malloc(2*(tree.input.length() - 1)*(sizeof (Node)));

    for (int i = 0; i < (int)tree.input.length(); i++) {
        carryPhase(tree, i);
        tree.printAllEdges();
    }

    cout << "Enter patterns or enter \"exit\" to exit." << endl;
    string pattern;
    getline(cin, pattern);
    while (pattern.compare("exit")) {
        search(pattern, tree);
        cout << "----------------------------------------------------" << endl;
        cout << "Enter pattern or enter \"exit\" to exit." << endl;
        getline(cin, pattern);
    }
    cout << "Wait for some more time to see the tree." << endl;
    cout << "Seeds are being imported right now." << endl;
    cout << "Adios!" << endl;
    return 0;
}
