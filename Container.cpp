

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
   length=EMPTY_NUM; //empty   
   //linkedListInt Null; 
   headInt.counter=length;
   P_Head=&headInt;
   headInt.pointerBack=NULL;

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
   //linkedListInt Null; 
   int newLength=EMPTY_NUM;
   linkedListInt* P_link;
   
   if (headInt.pointerBack!=NULL){                            
   P_link=headInt.pointerBack;
   }
   else
   {
   length=newLength;    
   }
   
   do{
   newLength++;
   P_link = P_link -> pointerBack;            
   }while (P_link!=NULL);  
   length = newLength;
}

bool MyContainer::removeInvalid(int remove)
{
for (int i; i<20;i++){}

}// IC



int MyContainer::pushBack(int addValue)
{
   linkedListInt* newNode = new linkedListInt;
   
   if (length==EMPTY_NUM){
      headInt.pointerBack = newNode;
      newNode -> data = addValue;
      newNode -> pointerForward = NULL;
      newNode -> pointerBack = NULL;
      lastValueInt = newNode;
      changeLength(1);
      
   }
   else
   {
      lastValueInt -> pointerBack = newNode;
      newNode -> data = addValue;
      newNode -> pointerBack = NULL;
      lastValueInt = newNode;
      changeLength(1);
   }
 
   return 1;
}

int MyContainer::pushFront(int addValue)
{
   linkedListInt *P_newFront;
   linkedListInt *P_oldFront;
   linkedListInt *temp;
   
   if (length==EMPTY_NUM){
      return pushBack(addValue);   
   }
   
   P_oldFront = headInt.pointerBack;
   P_newFront = new linkedListInt;
   
   headInt.pointerBack = P_newFront;
   P_newFront -> pointerBack = P_oldFront;
   P_newFront -> pointerForward = NULL;
   
   P_oldFront -> pointerForward = P_newFront;
   
   
   if (headInt.pointerBack = temp){
   return -1;
   }
   
   changeLength(1);
   return 1;
   
}

int MyContainer::popFront()
{
   linkedListInt *P_newFront;
   linkedListInt *P_oldFront;
   linkedListInt *temp;     
   
   if (length<0){
      return -1;//failure; nothing to remove   
   }   
    
   if (length == 0){
      return popBack();
   } 
   
   if (length>0){
      P_oldFront = headInt.pointerBack;
      P_newFront = P_oldFront -> pointerBack;
      delete P_oldFront;
      P_newFront -> pointerForward = NULL;
      headInt.pointerBack = P_newFront;
      changeLength(-1);
      return 2;
   }
    
   return -2;
}

bool MyContainer::changeLength(int lengthChange)
{
   if (length+lengthChange>=EMPTY_NUM){
      length = length + lengthChange;
      headInt.counter = length;
   }
}

int MyContainer::popBack()
{

   linkedListInt *P_newBack;
   linkedListInt *P_oldBack;
   linkedListInt *temp;
   
   if (length<0){
      return -1;//failure; There is nothing to pop off
   }
   
   if (length == 0){
      P_oldBack = lastValueInt;
      lastValueInt = NULL;
      delete P_oldBack;
      headInt.pointerBack = NULL;
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

int MyContainer::giveNode(linkedListInt** output, int numNode)//pointer to pointer
{
int atIndex=0;
linkedListInt *temp;
int i=0;

   if (numNode=>length||numNode<=EMPTY_NUM){
      cout<<"Something broke in giveNode"<<endl;
      return -1;
   }
   else
   {
      temp = headInt.pointerBack;
      while(true){
         if (atIndex==numNode){
            *output = temp;   
            return 1;
         }
         temp = temp -> pointerBack;
         atIndex++;
         if (temp==NULL){
            break;   
         }
      }
   cout<<"Something broke in giveNode"<<endl;
   return -1;
   
   }
return -1;//should never reach here
}

//Gives the value at the node specified. Node 0 is the first node.
int MyContainer::valueAt(int numNode)
{
linkedListInt *temp;

   if (giveNode(temp, numNode)==1){
   return temp -> data;
   }

return -1;//bad stuff...
}

int MyContainer::deleteNode(int nodeNum)
{
   linkedListInt *temp;
   linkedListInt *forward;
   linkedListInt *backward;
   
   if (length == EMPTY_NUM){
      return -1;//nothing to delete...   
   }
   
   if (length == 0){
      return popBack();  
   }
   
   if (giveNode(temp,nodeNum)==1){
      backward = temp -> pointerBack;
      forward = temp -> pointerFront;
      if (forward!=NULL){
         forward -> pointerBack = backward;
      }
      if (backward!=NULL){
         backward -> pointerForward = forward;
      }
      delete temp;
      return 1;
   }
}

   
//int MyContainer::pushBack(std::string addValue)
//{}
//int MyContainer::pushFront(std::string addValue)
//{}
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
    
    
    
    
    
