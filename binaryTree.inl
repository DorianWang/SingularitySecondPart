#include "binaryTree.h"



template <class T> binaryTreeType<T>::binaryTreeType()
{

   currentSize = 0; //empty
   headNode = NULL;
   selectedNode = NULL;

   hasCompare = false; hasEquivalence = false; userSetCompare = false;

   hasCompare = checkForCompare(&hasEquivalence);
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
         if (userCompare(newNode, selectedNode)){
            if (selectedNode.right != NULL){
               selectedNode = selectedNode.right;
            }
            else
            {
               selectedNode.right = newNode;
               return 1;
            }
         }
         else
         {
            if (selectedNode.left != NULL){
               selectedNode = selectedNode.left;
            }
            else
            {
               selectedNode.left = newNode;
               return 1;
            }
         }
      }
   }

   //Directly compares pointers
   if (!hasCompare){
      while (true){

      if (selectedNode > newNode){
         if (selectedNode.right != NULL){
            selectedNode = selectedNode.right;
         }
         else
         {
            selectedNode.right = newNode;
            return 1;
         }
      }
      else
      {
         if (selectedNode.left != NULL){
            selectedNode = selectedNode.left;
         }
         else
         {
            selectedNode.left = newNode;
            return 1;
         }
      }


   }
   }
   else
   {
      while (true){

         if (selectedNode.dataStored < newNode.dataStored){
            if (selectedNode.right != NULL){
               selectedNode = selectedNode.right;
            }
            else
            {
               selectedNode.right = newNode;
               return 1;
            }
         }
         else
         {
            if (selectedNode.left != NULL){
               selectedNode = selectedNode.left;
            }
            else
            {
               selectedNode.left = newNode;
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


template <class T> bool binaryTreeType<T>::checkForCompare(bool* equalCheck)
{

   if (IsPrimitiveType<T>::VALUE == 0){
      if (has_greater_than_compare <T, bool (T::*)(T)>::VALUE){
         if (has_less_than_compare <T, bool (T::*)(T)>::VALUE){
            if (has_equal_compare<T, bool (T::*)(T)>::VALUE){
               *equalCheck = true;
            }
            else
            {
               *equalCheck = false;
            }
             return true;
          }
      }

      if (has_equal_compare<T, bool (T::*)(T)>::VALUE){
         *equalCheck = true;
      }
      else
      {
         *equalCheck = false;
      }
      return false;
   }
*equalCheck = true;
return true;//Basic data type. Must have compare, or I'll eat my hat.
}



template <class T> std::vector<T> binaryTreeType<T>::outputAll(bool* equalCheck)
{

   int asdf;
}


























