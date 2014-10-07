#ifndef BINARYLEAFTYPE_H
#define BINARYLEAFTYPE_H




template <class E> class binaryNodeType
{
E dataStored;

binaryNodeType <E>* left;
binaryNodeType <E>* right;

public:

binaryNodeType(E newData);

E* getDataPointer();
E getData();

void setData (E input);

};

#endif // BINARYLEAFTYPE_H_INCLUDED
