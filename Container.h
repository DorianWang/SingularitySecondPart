
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

public:

linkedList();
~linkedList();

//int pushBack(std::string addValue);
int pushBack(D addValue);

int size();
void recount();
bool removeInvalid(int remove);

int popFront();
int popBack();
int valueAt(int numNode);

int deleteNode(unsigned int nodeNum);

int pushFront(D addValue);
;
};







#endif











