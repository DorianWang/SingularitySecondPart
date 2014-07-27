
#include "treeType.h"
//Tree container

//http://www.cprogramming.com/tutorial/templates.html
template <class T> treeType<T>::treeType()
{
   std::string name;
   numNodesMaxPer = -1;//Any number of nodes per node, rational limit of 20 or so...
}

//Ask for help
template <class T> treeType<T>::treeType(T input, int nodeMaxChild)
{
   std::string name; 
   if (nodeMaxChild>1){
      numNodesMaxPer = nodeMaxChild;
   }
   else
   {
      numNodesMaxPer = -1;    
   }
}

template <class T> treeType<T>::addNode(std::string name)
{
   
}

template <class T> treeType<T>::deleteNode(std::string name)
{
   
}

template <class T> treeType<T>::deleteThisNode()
{
   //Recursive
}










