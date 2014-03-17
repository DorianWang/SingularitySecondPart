

#include "Container.h"

MyContainer::MyContainer(std::string firstValue)
{
       
   length=1;     
   linkedListString Null;
   P_Head=&headNodeInt;
   firstLinkStr.pointerForward = &Null;
   firstLinkStr.data = firstValue;
   linkedListString* lastValueStr = &firstLinkStr;                        
                          
}




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


int MyContainer::length()
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
for (int i; ){}

}// IC



int MyContainer::pushBack(int addValue)
{
   linkedListInt* newNode = new linkedListInt;
   if (length==0){
      headNodeInt.pointerBack=newNode;
   }
   else
   {
       
   }
 
   
}

int MyContainer::pushFront(int addValue)
{
   
    
    
}

int MyContainer::popFront()
{
    
    
}

int MyContainer::popBack()
{
    
    
}

int MyContainer::valueAt(int numNode)
{
if (numNode>length){
return -1;
}


}
   
//int MyContainer::pushBack(std::string addValue)
//{}
//int MyContainer::pushFront(std::string addValue)
//{}
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
    
    
    
    
    
