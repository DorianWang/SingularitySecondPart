
#ifndef TREE_TYPE_H
#define TREE_TYPE_H 


#define MAX_NODES_DEFAULT 32
//^ no real reason, just logic. Can be overriden by the caller.

#include <iostream>
#include <queue>
#include <vector>
#include <string>

#include "leafType.h"

template <class T> class treeType 
{
T tempVar;
int numNodesMaxPer;

std::string label;

treeType<T>* parent;

std::vector < treeType<T>* > childNodes;
std::vector < leafType<T> > childData;

public:

bool isGood;//Variable should always be true.
//If not, use may cause undefined behaviour.

treeType(std::string newName);
treeType(std::string newName, int nodeMaxChild);


treeType<T>* findNode(std::string name);//Finds a node with the name of "name";
treeType<T>* findNode(std::string name, treeType<T>*);

treeType<T>* findChildNode(std::string name);
treeType<T>* findChildNode(std::string name, treeType<T>*);

bool addNode(std::string name);

leafType<T>* findConnectedLeaf(std::string name);


bool deleteNode(std::string name);
void cleanThisNode();


};




#endif






