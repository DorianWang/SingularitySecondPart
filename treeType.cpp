
#include "treeType.h"
//Tree container

//http://www.cprogramming.com/tutorial/templates.html
template <class T> treeType<T>::treeType()
{
   std::string name;
   numNodesMaxPer = -1;//Any number of nodes per node, rational limit of 20 or so...
}

//Ask for help
template <class T> treeType<T>::treeType(int nodeMaxChild)
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


template <class T> treeType<T>* treeType<T>::findNode(std::string name)
{
   int a = 0;
}


template <class T> bool treeType<T>::addNode(std::string name)
{
   
}

template <class T> bool treeType<T>::deleteNode(std::string name)
{
   treeType<T>* nodeToDelete = findNode(name);
   if (nodeToDelete != NULL){
      nodeToDelete -> deleteThisNode();
      return true;
   }
   else
   {
      return false;
   }
}

template <class T> treeType<T>::deleteThisNode()
{
   //Recursive
}










