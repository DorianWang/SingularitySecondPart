#include "binaryTree.h"



template <class T> binaryTreeType<T>::binaryTreeType()
{

   currentSize = 0; //empty
   headNode = NULL;
   selectedNode = NULL;

   hasCompare = false; hasEquivalence = false; userSetCompare = false;

   hasCompare = checkForCompare(&hasEquivalence);
}


template <class T> void binaryTreeType<T>::addNode(binaryNodeType <T>* parent, binaryNodeType <T>* child, bool childSmaller)
{
   child -> up = parent;

   if (childSmaller){
      //Left
      parent -> left = child;
   }
   else
   {
      parent -> right = child;
   }


}


template <class T> int binaryTreeType<T>::addNode(T input)
{
   binaryNodeType <T>* newNode = new binaryNodeType<T>(input);

   //If there is no head node, set new node as head.
   if (headNode == NULL){
      headNode = newNode;
      return 1;
   }

   //If there is a head node, starts recursion at the head.
   selectedNode = headNode;

   //Uses the user set function first.
   if (userSetCompare){
      while(true){
         if (userCompare(newNode -> getData(), selectedNode -> getData())){
            if (selectedNode -> right != NULL){
               selectedNode = selectedNode -> right;
            }
            else
            {
               selectedNode -> right = newNode;
               return 1;
            }
         }
         else
         {
            if (selectedNode -> left != NULL){
               selectedNode = selectedNode -> left;
            }
            else
            {
               selectedNode -> left = newNode;
               return 1;
            }
         }
      }
   }

   //Directly compares pointers
   if (!hasCompare){
      while (true){

      if (selectedNode > newNode){
         if (selectedNode -> right != NULL){
            selectedNode = selectedNode -> right;
         }
         else
         {
            selectedNode -> right = newNode;
            return 1;
         }
      }
      else
      {
         if (selectedNode -> left != NULL){
            selectedNode = selectedNode -> left;
         }
         else
         {
            selectedNode -> left = newNode;
            return 1;
         }
      }


   }
   }
   else
   {
      while (true){

         if (selectedNode -> getData() < newNode -> getData()){
            if (selectedNode -> right != NULL){
               selectedNode = selectedNode -> right;
            }
            else
            {
               selectedNode -> right = newNode;
               return 1;
            }
         }
         else
         {
            if (selectedNode -> left != NULL){
               selectedNode = selectedNode -> left;
            }
            else
            {
               selectedNode -> left = newNode;
               return 1;
            }
         }

      }
   }



}



template <class T> void binaryTreeType<T>::enterCompareFunction(bool (*input)(T first, T second))
{
userCompare = input;

userSetCompare = true;
}


//Returns true for equality compare.
//compareCheck must be an array of size two, the first for greater than, and the second
//for lesser than.
template <class T> bool binaryTreeType<T>::checkForCompare(bool* compareCheck)
{

//Basic data type. Must have compare, or I'll eat my hat.
   if (is_class<T>::value == false){
      compareCheck[0] = true; compareCheck[1] = true;
      return true;
   }

   if (CHECK::opGreaterExists <T>::value){
      compareCheck[0] = true;
   }

   if (CHECK::opLesserExists <T>::value){
      compareCheck[1] = true;
   }

   if (CHECK::opEqualExists<T>::value){
      return true;
   }

return false;
}



template <class T> std::vector<T> binaryTreeType<T>::outputAll()
{
   selectedNode = headNode;
   std::vector <T> output;
   if (selectedNode == NULL){
      return output;
   }
   output = outputTreeSegment(selectedNode);

   return output;
}


//http://stackoverflow.com/questions/4226606/inserting-into-a-vector-at-the-front
//Change into a queue?
//TODO: change things
template <class T> void binaryTreeType<T>::outputTreeSegment(std::vector<T> output, binaryNodeType <T>* tempHead)
{
   std::vector <T> outputArray;
   if (tempHead -> left == NULL){
      if (tempHead -> right == NULL){
         outputArray.push_back(tempHead -> getData());
         //return outputArray;
      }
      outputArray = outputTreeSegment(tempHead -> right);
      outputArray.push_front(tempHead -> getData());
      //return outputArray;
   }

   outputArray = outputTreeSegment(tempHead -> left);
   outputArray.push_back(tempHead -> getData());
   if (tempHead -> right == NULL){
      //return outputArray;
   }

   std::vector <T> tempArray = outputTreeSegment(tempHead -> right);
   outputArray.reserve(outputArray.size() + tempArray.size() + 1);
   outputArray.insert( outputArray.end(), tempArray.begin(), tempArray.end() );

   //return outputArray;
}


























