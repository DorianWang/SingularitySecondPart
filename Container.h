
#ifndef CONTAINER_H
#define CONTAINER_H 

#include <string>


using namespace std;
class MyContainer
{

int lastValue;
int emptyValue;

public:
MyContainer(std::string firstValue);
MyContainer(int firstValue);

int pushBack(std::string addValue);
int pushBack(int addValue);


};

#endif
