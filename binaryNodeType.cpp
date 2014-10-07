
#include "binaryNodeType.h"

//Leaf type?


template <class E> binaryNodeType<E>::binaryNodeType(E newData)
{
   dataStored = newData;
}

template <class E> E* binaryNodeType<E>::getDataPointer()
{
   return &dataStored;
}

template <class E> E binaryNodeType<E>::getData()
{
   return dataStored;
}
