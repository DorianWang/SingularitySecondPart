

#include "Container.h"

//MyContainer::MyContainer(std::string firstValue)
//{
//       
//   length=1;     
//   linkedListString Null;
//   P_Head=&headNodeInt;
//   firstLinkStr.pointerForward = &Null;
//   firstLinkStr.data = firstValue;
//   linkedListString* lastValueStr = &firstLinkStr;                        
//                          
//}




MyContainer::MyContainer()//int firstValueInt)
{
   length=0;    
   //linkedListInt Null; 
   headNodeInt.counter=length;
   P_Head=&headNodeInt;
   headNodeInt.pointerBack=NULL;

   //firstLinkInt.pointerForward=P_Head;
   //firstLinkInt.data = firstValueInt;
   //lastValueInt = &firstLinkInt;
   //firstLinkInt.pointerBack=NULL;
}


int MyContainer::width()
{
return length;
}

void MyContainer::recount()
{
   linkedListInt Null; 
   linkedListInt* P_link;
   while (P_link!=&Null){  
         }
}

bool MyContainer::removeInvalid(int remove)
{
for (int i; i<20;i++){}

}// IC



int MyContainer::pushBack(int addValue)
{
   linkedListInt* newNode = new linkedListInt;
   if (length==0){
      headNodeInt.pointerBack=newNode;
      newNode -> data = addValue;
      newNode -> pointerForward = NULL;
      newNode -> pointerBack = NULL;
      lastValueInt = newNode;
      
   }
   else
   {
      lastValueInt -> pointerBack = newNode;
      newNode -> data = addValue;
      lastValueInt = newNode;
   }
 
   return 1;
}

int MyContainer::pushFront(int addValue)
{
   linkedListInt *P_newFront;
   linkedListInt *P_oldFront;
   linkedListInt *temp;
   
   P_oldFront = headNodeInt.pointerBack;
   P_newFront = P_oldFront -> pointerBack;
   temp = P_oldFront;
   delete P_oldFront;
   headNodeInt.pointerBack = P_newFront;
   P_newFront -> pointerForward = NULL;
   
   if (headNodeInt.pointerBack = temp){
   return -1;
   
   }
   return 1;
   
}

int MyContainer::popFront()
{
    
    
}

int MyContainer::popBack()
{
   
    
}

int MyContainer::valueAt(int numNode)
{

if (numNode>length||numNode<0){
   cout<<"something broke in valueAt"<<endl;
   return 0;//assume the value is 0. This is not good.
}




}
   
//int MyContainer::pushBack(std::string addValue)
//{}
//int MyContainer::pushFront(std::string addValue)
//{}
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
    
    
    
    
    
