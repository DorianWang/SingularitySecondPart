
#ifndef CONTAINER_H
#define CONTAINER_H 

#include <string>
#include <iostream>

#define EMPTY_NUM -1

using namespace std;

struct linkedListInt{
int data;

linkedListInt* pointerForward;
linkedListInt* pointerBack;
};

//struct linkedListString{//please do not use
//std::string data;
//
//linkedListString* pointerForward;
//linkedListString* pointerBack;
//};

struct listHeadInt{
int counter;//length of list       
       
linkedListInt* pointerBack;
};

//struct listHeadString{
//int counter;//length of list       
//       
//linkedListString* pointerBack;
//};

class MyContainer
{

//int lastValue;
//int emptyValue;
int length;

//linkedListString* lastValueStr;
//linkedListString firstLinkStr;




//linkedListInt firstLinkInt;

listHeadInt headInt;//first node, holds counter and pointer to next node
listHeadInt* P_Head;//pointer to head node

linkedListInt* lastValueInt;//pointer to the last value in the list

public:
//MyContainer(std::string firstValue);
MyContainer();//int firstValueInt);

//int pushBack(std::string addValue);
int pushBack(int addValue);

int width();
void recount();
bool removeInvalid(int remove);

int popFront();
int popBack();
int valueAt(int numNode);

bool changeLength(int lengthChange);

int giveNode(linkedListInt** output, int numNode);//pointer to pointer
int deleteNode(int nodeNum);

//int pushFront(std::string addValue);
int pushFront(int addValue);
;
};

#endif











