# Algorithm Design and Analysis Final Project
This project builds upon a third-party implementation of Ukkonen's algorithm.
## Part 1
In the Part1 branch, the original code is refactored and Google Test is used to 
run extended random tests to ensure correctness of the algorithm implmentation.
## Part 2
In the Part2 branch, the modified suffix-tree building algorithm is used to
implement algorithms for the linearization of circular strings and the finding
of the least common substring of two strings. Google Test is used again to
test the correctness of these algorithms through extended tests of randomized
inputs.

# Original README
Implementation of Ukkonen's algorithm in C++.
This is very special algorithm. You may have a look at the original paper here:
http://www.cs.helsinki.fi/u/ukkonen/SuffixT1withFigs.pdf.


Do |make| to compile and |make run| to execute.

Output would be all the edges in the suffix tree with the following details:
StartNode Endnode SuffixlinkOfEndNode StartLabelIndex EndLabelIndex String

where:
StartLabelIndex is the starting index of the substring represented by this edge.
EndLabelIndex is the ending index of the substring represented by this edge.
String is the full label represented by this edge.

Alphabet set is unlimited. 

To get the explicit suffix tree you have to end the input string with a unique
character.

You can do a search in the suffix tree for any substring.

This is a linear time algorithm.

Only significant data structure that I've used is a hash table. This
implementaion of hash table has an constant average case complexity.

