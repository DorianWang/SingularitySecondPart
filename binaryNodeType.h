#ifndef BINARYLEAFTYPE_H
#define BINARYLEAFTYPE_H




template <class E> class binaryNodeType
{
E dataStored;

binaryNodeType <E>* up;

binaryNodeType <E>* left;
binaryNodeType <E>* right;

public:

binaryNodeType(E newData);

E* getDataPointer();
E getData();

void setData (E input);
//Be careful with changing the data stored. It could cause problems with sorting.
//Basically, use at your own risk.

};

#endif // BINARYLEAFTYPE_H_INCLUDED
