
#ifndef CONTAINER_H
#define CONTAINER_H

#include "functionChecker.h"

#include <string>
#include <iostream>
#include <vector>


using namespace std;

#define MAX_LENGTH_LINKED_LIST 200000000000
//200 Billion. Do not go over this, or bad things will happen...

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

bool hasCompare;
bool hasEquivalence;

bool checkForCompare(bool* equalCheck);

linkedListNode <D>* headNode;
linkedListNode <D>* lastNode;//pointer to the last value in the list

linkedListNode <D>* lastNodeUsed;//pointer that was used last in any function. Set null after use.
//I might use this for a function.

linkedListNode <D>* getNodePointer(unsigned int numNode);

bool getNextNodePointer(linkedListNode <D>** inputPointer, linkedListNode <D>** output);
bool getPrevNodePointer(linkedListNode <D>** inputPointer, linkedListNode <D>** output);

void changeLength(int numToChange);


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

int deleteNode(unsigned int nodeNum, unsigned int numNodesToDelete);
int deleteNode(D typeToDelete);
int deleteAllNodes();

bool linkNode(linkedListNode <D>* firstNode, linkedListNode <D>* secondNode);



;
};




#include "Container.cpp"


#endif











