
#ifndef CONTAINER_H
#define CONTAINER_H 

#include <string>


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
int emptyValue;
int length;

//linkedListString* lastValueStr;
linkedListInt* lastValueInt;

//linkedListString firstLinkStr;
linkedListInt firstLinkInt;

public:
//MyContainer(std::string firstValue);
MyContainer(int firstValueInt);

//int pushBack(std::string addValue);
int pushBack(int addValue);

//int pushFront(std::string addValue);
int pushFront(int addValue);
;
};

#endif











