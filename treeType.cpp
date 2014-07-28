
#include "treeType.h"
//Tree container

//http://www.cprogramming.com/tutorial/templates.html
template <class T> treeType<T>::treeType(std::string newName)
{
   label = newName;
   numNodesMaxPer = MAX_NODES_DEFAULT;//Any number of nodes per node, rational limit of 20 or so...
}

//Ask for help
template <class T> treeType<T>::treeType(std::string newName, int nodeMaxChild)
{
   label = newName;
   if (nodeMaxChild>1){
      numNodesMaxPer = nodeMaxChild;
   }
   else
   {
      numNodesMaxPer = MAX_NODES_DEFAULT;    
   }
}


template <class T> treeType<T>* treeType<T>::findNode(std::string name)
{
   int a = 0;
   for (int i = 0; i<childNodes.length(); i++){
      if (childNodes[i].label == name){
         
      }
   }
}

template <class T> leafType<T>* treeType<T>::findLeaf(std::string name)
{
   leafType<T>* returnValue;
   returnValue = NULL;
   returnValue = findConnectedLeaf(name);
   if (returnValue != NULL){
      return returnValue;
   }

   for (int i = 0; i < childNodes.length(); i++){
      returnValue = childNodes[i] -> findLeaf(std::string name);
      if (returnValue != NULL){
         return returnValue;
      }
   }
   return NULL;
}

//keyWords must be placed in order of more to less specific (equipment weapon edge, for example)
template <class T> leafType<T>* treeType<T>::findLeaf(std::string name, std::string keyWords)
{
   


}



template <class T> leafType<T>* treeType<T>::findConnectedLeaf(std::string name)
{
   for (int i = 0; i<childNodes.length(); i++){
      if (childNodes[i].label == name){
         return &(childNodes[i]);
      }
   }
   return NULL;
}


template <class T> bool treeType<T>::addNode(std::string name)
{
   if (name == label){
      return false;//Not good. Do not add duplicates   
   }
   if (childNodes.length() >= numNodesMaxPer){
      return false;
   }
   treeType<T>* temp = new treeType<T>(name);
   childNodes.push_back(temp);
   return true;
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

//Does not actually delete node. Removes all child nodes, preventing memory leaks
template <class T> void treeType<T>::cleanThisNode()
{
   for (int i=0; i<childNodes.length(); i++){
      childNodes[i] -> cleanThisNode();//Recursive
      delete [] childNodes[i];
   }
   childData.clear();
   childNodes.clear();
}










