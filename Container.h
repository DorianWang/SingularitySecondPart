
#ifndef CONTAINER_H
#define CONTAINER_H

#include <string>
#include <iostream>


using namespace std;



template <typename E> class linkedListNode
{
   public:
   linkedListNode <E>* P_Prev;//Pointer to the parent node of this one.
   linkedListNode <E>* P_Next;//Pointer to the node next in the list.

   E data;
};



template <typename D> class linkedList
{
unsigned int length;//Current length of the linked list


linkedListNode <D>* headNode;
linkedListNode <D>* lastNode;//pointer to the last value in the list

linkedListNode <D>* getNodePointer(unsigned int numNode);

public:

linkedList();
~linkedList();

void pushBack(D addValue);
void pushFront(D addValue);

unsigned int size();

D popFront(bool* errorBool);
D popBack(bool* errorBool);

D valueAt(unsigned int numNode, bool* errorBool);

int deleteNode(unsigned int nodeNum);
void changeLength(int numToChange);


;
};







#endif











