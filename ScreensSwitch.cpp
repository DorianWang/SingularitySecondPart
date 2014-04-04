
#include "Screens.h"

//move some of the switch statements over to here.

int SelectScreens::gameStart()
{
input = keyIO.get_code("asqASQ");             

   if (input!=FAILURE_NUM){      
         
   }   
return -1;
}

void SelectScreens::programRun(int programNum)
{
int functionRan; 
functionRan=-1;

switch(programNum)
{
   case 0:
   break;//not supposed to get here  
   
   case 1:
   functionRan=treeSort(0);
   break;

   case 2:
   functionRan=helloWorld(0);
   break;
   
   case 3:
   functionRan=futurePlans(0);     
   break;
   
   case 4:
   functionRan=helloWorld(0);
   break;
   //nothing   
   case 5:
   break;
   //nothing      
   case 6:
   break;
   //nothing as well
   case 9:
   break;
   //could be used later     
   case 10:
   functionRan=dwarfGame(1);
   break;
   //more things to be added later
   
}


if (functionRan==FAILURE_NUM){
   cout<<"Failure to do stuff"<<endl;
}

}//end programRun

int SelectScreens::helloWorld(int nothing, ...)
{
char s1[254]="Hello worl";
char s2[254];
int counter=0;
int counter2=0;

s2[0]='d';
s2[1]='!';
s2[2]=0; 

//cout<<s1<<endl;
//system("PAUSE");

do{
   if (s1[counter]!=0){
      counter++;
   }
   if (s1[counter]==0){
      do{
         s1[counter]=s2[counter2];
         counter++;
         counter2++; 
      }while(s2[counter2]!=0);
      break;
   }
         
      
}while(true);

cout<<s1<<endl<<endl;
system("PAUSE");   

//char asdfasdf[] ="1 2 3 4 5 6 7 8 9 asdf";
//char* pch;
//std::string asdfasdfa="0";
//pch = strtok (asdfasdf," ,.-");
//
//while(pch!=NULL){
//   cout<<pch<<endl;    
//   asdfasdfa+=pch;             
//   pch=strtok (NULL," ,.-");
//   
//}
//cout<<asdfasdfa<<endl;
//system("PAUSE");

return 1; 
}
