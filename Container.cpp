

#include "Container.h"

MyContainer::MyContainer(std::string firstValue)
{
       
   length=1;     
   linkedListString Null;
   
   firstLinkStr.pointerForward = &Null;
   firstLinkStr.data = firstValue;
   linkedListString* lastValueStr = &firstLinkStr;                        
                          
}




MyContainer::MyContainer(int firstValueInt)
{
   length=1;    
   linkedListInt Null; 
                

   firstLinkInt.pointerForward=&Null;
   firstLinkInt.data = firstValueInt;
   linkedListInt* lastValueInt = &firstLinkInt;
   
}

int MyContainer::pushFront(int addValue)
{
   
    
    
}

//int MyContainer::pushFront(std::string addValue)
//{}

int MyContainer::pushBack(int addValue)
{
   
 
 
   
}
   
//int MyContainer::pushBack(std::string addValue)
//{}
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
    
    
    
    
    
