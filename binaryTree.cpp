#include "binaryTree.h"



template <class T> binaryTreeType<T>::binaryTreeType()
{

   currentSize = 0; //empty
   headNode = NULL;
   selectedNode = NULL;
   hasCompare = checkForCompare(&hasEquivalence);
}
