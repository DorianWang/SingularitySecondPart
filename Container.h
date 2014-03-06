
#ifndef CONTAINER_H
#define CONTAINER_H 

#include <string>


using namespace std;

struct linkedListInt{
int data;

linkedListInt* pointerForward;
linkedListInt* pointerBack;
}

struct linkedListString{//please do not use
std::string data;

linkedListString* pointerforward;
linkedListString* pointerBack;

}

class MyContainer
{

//int lastValue;
int emptyValue;
int length;

public:
MyContainer(std::string firstValue);
MyContainer(int firstValue);

int pushBack(std::string addValue);
int pushBack(int addValue);


};

#endif











