
#define MAX_NODES_DEFAULT 32
//^ no real reason, just logic. Can be overriden by the caller.

#include <vector>
#include <string>

#include "leafType.h"

template <class T> class treeType 
{
T tempVar;
int numNodesMaxPer;
std::vector <treeType<T>*> childNodes;
//std::vector <leafType<T>> childData;

public:

treeType();
treeType(int nodeMaxChild);

treeType<T>* findNode(std::string name);//Finds a node with the name of "name";

bool addNode(std::string name);


bool deleteNode(std::string name);



};





