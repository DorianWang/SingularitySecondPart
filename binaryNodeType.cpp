
#include "binaryNodeType.h"

//Leaf type?


template <class E> binaryNodeType<E>::binaryNodeType(E newData)
{
   dataStored = newData;
}

//This may also be dangerous...
template <class E> E* binaryNodeType<E>::getDataPointer()
{
   return &dataStored;
}

template <class E> E binaryNodeType<E>::getData()
{
   return dataStored;
}


//Dangerous function. Please just delete this node, and add a new
//one instead.
template <class E> void binaryNodeType<E>::setData (E input)
{
   dataStored = input;
}
