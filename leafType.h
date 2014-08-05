
#ifndef LEAF_TYPE_H
#define LEAF_TYPE_H 

#include <vector>
#include <string>

template <class E> class leafType 
{
E dataStored;
std::string label;

public:

leafType(std::string name, E dataIn);
E* getDataPointer();
E getData();


};


//Leaf type declaration?






#endif
