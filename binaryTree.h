#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "functionChecker.h"
#include "binaryNodeType.h"

template <typename T> class binaryTreeType
{

private:
binaryNodeType <T>* headNode;
binaryNodeType <T>* selectedNode;

int currentSize;

bool hasCompare; bool hasEquivalence;


public:


//http://web.eecs.umich.edu/~qstout/abs/CACM86.html
//http://penguin.ewu.edu/~trolfe/DSWpaper/
void rebalance();

int addNode(T input);


};

#endif // BINARYTREE_H
