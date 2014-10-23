#ifndef BINARYLEAFTYPE_H
#define BINARYLEAFTYPE_H

#include <cstdlib>



template <class E> class binaryNodeType
{
E dataStored;



public:

binaryNodeType <E>* up;

binaryNodeType <E>* left;
binaryNodeType <E>* right;


binaryNodeType(E newData);

E* getDataPointer();
E getData();

void setData (E input);
//Be careful with changing the data stored. It could cause problems with sorting.
//Basically, use at your own risk.



};

#endif // BINARYLEAFTYPE_H_INCLUDED
