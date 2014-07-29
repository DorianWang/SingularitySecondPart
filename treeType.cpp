
#include "treeType.h"
//Tree container

//http://www.cprogramming.com/tutorial/templates.html
template <class T> treeType<T>::treeType(std::string newName)
{
   label = newName;
   numNodesMaxPer = MAX_NODES_DEFAULT;//Any number of nodes per node, rational limit of 20 or so...
   isGood = true;
}

//Ask for help
template <class T> treeType<T>::treeType(std::string newName, int nodeMaxChild)
{
   label = newName; isGood = true;
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
   for (int i = 0; i<childNodes.size(); i++){
      if (childNodes[i] -> label == name){
         return childNodes[i];
      }
      
   }
}

template <class T> treeType<T>* treeType<T>::findConnectedNode(std::string name)
{
   int a = 0;
   for (int i = 0; i<childNodes.size(); i++){
      if (childNodes[i] -> label == name){
         return childNodes[i];
      }
   }
   return NULL;
}

//Depth first search.
template <class T> leafType<T>* treeType<T>::findLeaf(std::string name)
{
   leafType<T>* returnValue;
   returnValue = NULL;
   returnValue = findConnectedLeaf(name);
   if (returnValue != NULL){
      return returnValue;
   }

   for (int i = 0; i < childNodes.size(); i++){
      returnValue = childNodes[i] -> findLeaf(std::string name);
      if (returnValue != NULL){
         return returnValue;
      }
   }
   return NULL;
}

//keyWords must be placed in order of more to less specific (equipment weapon edge, for example)
//Not complete
template <class T> leafType<T>* treeType<T>::findLeaf(std::string name, std::string keyWords)
{

   leafType<T>* returnValue;
   returnValue = findConnectedLeaf(name);
   
   if (returnValue != NULL){
      return returnValue;
   }

   std::string firstToken = parseFirstToken(keyWords);
   
   returnValue = findConnectedNode(firstToken);
   

   
   std::queue < treeType<T>* > nodeQueue;
   treeType<T>* tempNode;
   nodeQueue.push(this);
   
   while(!nodeQueue.empty()){
      tempNode = myqueue.nodeQueue();
      nodeQueue.pop();
      returnValue = tempNode -> findConnectedNode(firstToken);
      
      if (returnValue != NULL){
         std::string temp = keyWords;
         if (temp != keyWords){
            temp.erase(str.begin(), firstToken.length() + 1);
         }
         return findLeaf(name, temp);
      }
      
      for (int i=0; i < tempNode -> childNodes.size(); i++){
         nodeQueue.push (tempNode -> childNodes[i]);
      }
   }
   
return NULL;
}



template <class T> leafType<T>* treeType<T>::findConnectedLeaf(std::string name)
{
   for (int i = 0; i<childNodes.size(); i++){
      if (childData[i].label == name){
         return &(childData[i]);
      }
   }
   return NULL;
}




template <class T> bool treeType<T>::addNode(std::string name)
{
   if (name == label){
      return false;//Not good. Do not add duplicates   
   }
   
   if (childNodes.size() >= numNodesMaxPer){
      return false;
   }
   
   treeType<T>* temp = new treeType<T>(name);
   childNodes.push_back(temp);
   return true;
}






//Node Deletion ----------------------------------------------------------------

template <class T> bool treeType<T>::deleteNode(std::string name)
{
   treeType<T>* nodeToDelete = findNode(name);
   if (nodeToDelete != NULL){
      nodeToDelete -> cleanThisNode();
      delete nodeToDelete;
      return true;
   }
   else
   {
      return false;
   }
}

template <class T> bool treeType<T>::deleteNode(treeType<T>* nodeToDelete)
{
   if (nodeToDelete != NULL){
      nodeToDelete -> cleanThisNode();
      delete nodeToDelete;
      return true;
   }
   else
   {
      isGood = false;//This is not good. It should never happen
      return false;
   }
}

//Does not actually delete node. Removes all child nodes, preventing memory leaks
template <class T> void treeType<T>::cleanThisNode()
{
   for (int i=0; i<childNodes.size(); i++){
      if (!deleteNode(childNodes[i])){
         isGood = false;//This is not good. It should never happen
      }
   }
   childData.clear();
   childNodes.clear();
}

//End Node Deletion ------------------------------------------------------------













