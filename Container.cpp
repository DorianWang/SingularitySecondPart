

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
   
   length++;
   return 1;
   
}

int MyContainer::popFront()
{
   linkedListInt *P_newFront;
   linkedListInt *P_oldFront;
   linkedListInt *temp;     
   
   if (length<1){
      return -1;//failure; nothing to remove   
   }   
    
   if (length == 1){
      return popBack();
   } 
   
   if (length>1){
      P_oldFront = head.pointerBack;
      P_newFront = P_oldFront -> pointerBack;
      delete P_oldFront;
      P_newFront -> pointerForward = NULL;
      head.pointerBack = P_newFront;
      changeLength(-1);
      return 2;
   }
    
   return -2;
}

bool MyContainer::changeLength(int lengthChange)
{
   if (length+lengthChange>=0){
      length = length + lengthChange;
      head.counter = length;
   }
}

int MyContainer::popBack()
{

   linkedListInt *P_newBack;
   linkedListInt *P_oldBack;
   linkedListInt *temp;
   
   if (length<1){
      return -1;//failure; There is nothing to pop off
   }
   
   if (length == 1){
      P_oldBack = lastValueInt;
      lastValueInt = NULL;
      delete P_oldBack;
      head.pointerBack = NULL;
      changeLength(-1);
      return 1;
   }
   else
   {
      P_oldBack = lastValueInt;
      lastValueInt = P_oldBack -> pointerForward;
      delete P_oldBack;
      lastValueInt ->  pointerBack = NULL;
      changeLength(-1);
      return 2;    
   }
   
return -2;   
    
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
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
    
    
    
    
    
