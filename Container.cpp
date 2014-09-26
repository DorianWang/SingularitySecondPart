

#include "Container.h"


template <class D> linkedList<D>::linkedList()//int firstValueInt)
{
   length = 0; //empty
   headNode = NULL;
   lastNode = NULL;
}

template <class D> linkedList<D>::~linkedList()
{
   //Add recursive deletion code here.
   //TODO
}

//Refactored
template <class D> int linkedList<D>::size()
{
   return length;
}

//Refactored
template <class D> void linkedList<D>::pushBack(D inputData)
{
   linkedListNode <D>* newNode = new linkedListNode <D>;

   //Empty list
   if (length == 0){
      headNode = newNode;
      lastNode = newNode;
      newNode -> data = inputData;
      newNode -> P_Prev = NULL;
      newNode -> P_Next = NULL;
      changeLength(1);
   }
   else
   {
      lastNode -> P_Next = newNode;
      newNode -> data = addValue;

      newNode -> P_Next = NULL;
      newNode -> P_Prev = lastNode;

      lastNode = newNode;
      changeLength(1);
   }
}

//Refactored
template <class D> void linkedList<D>::pushFront(D inputData)
{
   linkedListNode <D>* newNode = new linkedListNode;
   linkedListNode <D>* P_oldFront;//Temporary storage.

   if (length == 0){
      return pushBack(inputData);
   }

   P_oldFront = headNode;

   headNode = newNode;
   newNode -> data = inputData;
   newNode -> P_Next = P_oldFront;
   newNode -> P_Prev = NULL;

   P_oldFront -> P_Prev = newNode;

   changeLength(1);
}

//This function returns the value of the first node, before deleting it.
//If this function succeeds, the errorBool will be set false.
//Refactored
template <class D> D linkedList<D>::popFront(bool* errorBool)
{

   if (length == 0){
      errorBool* = true;//Failure
      return 0;//failure; nothing to remove
   }

   D tempData = headNode -> data; //Temporary data storage.

   deleteNode(headNode);
   errorBool* = false;//No error.
   return tempData;

}

//Almost the same as the above.
//Refactored
template <class D> D linkedList<D>::popBack(bool* errorBool)
{

   if (length == 0){
      errorBool* = true;
      return 0;//failure; There is nothing to pop off
   }

   D tempData = lastNode -> data; //Temporary data storage.

   errorBool* = false;//No error.
   deleteNode(lastNode);
   return tempData;

}


//Gives the value at the node specified. Node 0 is the first node.
template <class D> int linkedList<D>::valueAt(unsigned int numNode, bool* errorBool)
{
   if (numNode > length){
      errorBool* = true;//Error, selected node does not exist.
      return 0;
   }

   unsigned int halfTest = length / 2;

   if ()

   linkedListNode* currentNode = headNode;

   for (int i = 0; i < numNode; i++){
      asdf

   }


}

template <class D> int linkedList::deleteNode(int nodeNum)
{
   linkedListInt *temp;
   linkedListInt *forward;
   linkedListInt *backward;

   if (length == 0){
      return -1;//nothing to delete...
   }

   if (length == 0){
      return popBack();
   }

   if (giveNode(&temp,nodeNum)==1){
      backward = temp -> pointerBack;
      forward = temp -> pointerForward;
      if (forward!=NULL){
         forward -> pointerBack = backward;
      }
      if (backward!=NULL){
         backward -> pointerForward = forward;
      }
      delete temp;
      return 1;
   }
}


























