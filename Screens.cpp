

#include "Screens.h"


#include <sstream>
#include <iostream>

int stringThing(int inputNum, int outputNum, int stringLength)
{
//An easier implementaion would involve returning true false, instead of numbers.

   if (inputNum==outputNum){
      return outputNum;                      
   }

   if ((inputNum-(stringLength/2))==outputNum){
      return outputNum;
   }

return FAILURE_NUM;
}


void SelectScreens::optionsScreen(){

system("CLS");

int input;
int stringTest;

int stringLength;
std::string inCharString;

inCharString="asdfgqASDFGQ";
stringLength= inCharString.length();

cursorMod.cursorControl(7);
cout<<"Press A to make the cursor visible, S to make it invisible"<<endl;
cout<<"D to change the text colour, F to return it to defaults"<<endl;
cout<<"G forces the cursor to toggle visibility"<<endl;
cout<<"Press Q to close the options screen"<<endl;
cursorMod.cursorControl(8);
cout<<"Test line"; // 9 characters
do{
   input = keyIO.get_code(inCharString);             

   //stringTest = stringThing

      if (input!=FAILURE_NUM){             
          
          if (stringThing(input, 0, stringLength)==0){//input==0||input==6){
          cursorMod.cursorControl(0);                   
          }
          
          if (stringThing(input, 1, stringLength)==1){//input==1||input==7){
          cursorMod.cursorControl(1);
          }  
          
          if (stringThing(input, 2, stringLength)==2){//input==2||input==8){                      
          cursorMod.cursorControl(2);
          }                        
          
          if (stringThing(input, 3, stringLength)==3){//input==3||input==9){                      
          cursorMod.cursorControl(3);
          }
          
          if (stringThing(input, 4, stringLength)==4){//input==4||input==10){                       
          cursorMod.cursorControl(4);
          }
          
          if (stringThing(input, 5, stringLength)==5){//input==5||input==11){
          Sleep(PRESSDELAY);
          break;
          //closer
          }
          
          cout << string(9 ,'\b');
          cout <<"Test line";
          Sleep(PRESSDELAY);
      }
                    
} while(true);     
      
}//options screen

int SelectScreens::gameStart()
{
int input;

int stringLength;
std::string inCharString;

inCharString="dswpqDSWPQ";
stringLength= inCharString.length();

bool isGame;
isGame=false;
int whichGame;//if it is a game, chooses which one and returns the value that corresponds to the game
whichGame=-1;
//returns a single digit number if it is a program. Games go in the format of 2 digit numbers. 12 would be 1 - (super easy), 2 - (game 3)


system("CLS");

cout<<"Please select your function"<<endl<<endl;

cout<<"Dwarf game - D"<<endl;
cout<<"Tree sort - S"<<endl;
cout<<"Hello World - W"<<endl;
cout<<"Plans for future stuff - P"<<endl;
cout<<"Quit - Q"<<endl;

do{
   input=keyIO.get_code(inCharString);            
   if (input!=FAILURE_NUM){
                  
      if (stringThing(input, 0, stringLength)==0){ 
         whichGame=0;
         isGame=true;
         break;
      }
      
      if (stringThing(input, 1, stringLength)==1){ 
         return 1;
         break;
      }
      
      if (stringThing(input, 2, stringLength)==2){ 
         return 2;
         break;
      }
      
      if (stringThing(input, 3, stringLength)==3){ 
         return 3;
         break;
      }
      
      if (stringThing(input, 4, stringLength)==4){
         return 4;
         break;
      }//current quit key

      if (stringThing(input, 9, stringLength)==9){
         return 9;
         break;
      }//maximum amount it can go for programs. 
      //If there are too many functions for this screen to control, I will make pressing 9 show additional options.
      
   }
}while(true);

if (isGame){
   cout<<"Please select your difficulty."<<endl<<endl;

   cout<<"Super easy - Z"<<endl;
   cout<<"Easy - A"<<endl;
   cout<<"Normal - S"<<endl;
   cout<<"Hard - D"<<endl;
   cout<<"Nintendo Hard - N"<<endl;
     
   do{   
         
      input=keyIO.get_code("zasdnZASDN");

      if (input!=FAILURE_NUM){
   
         continue;
                  
      }

      if (input>4){
   
         return (input-5);             
                
      }
      else if (input<4&&input>-1){
   
         return input;
        
      }
      else
      {
   
         //???    
       
      }
   
   }while(true);   
  
}//end isGame if statement
       
}//end function


int SelectScreens::mainScreen(int versionNum)
{

stringstream ss (stringstream::in | stringstream::out);

ss<<versionNum;          
string out = ss.str();     
int input;

int programFunction;
programFunction=FAILURE_NUM;
cursorMod.cursorControl(3);

char chars[]="abcdefghijklmnop"; // c string

cout<<"Welcome to version " + out + " of singularity."<<endl<<endl;
system("PAUSE");
system("CLS");
cout<<"Press A to start the game, S to change settings and Q to quit"<<endl;
//screenPaint.screenWriter(24,80, &chars[2]);

do{
   input = keyIO.get_code("asqASQ");             

      if (input!=FAILURE_NUM){             
          
          if (input==0||input==3){
          programFunction=gameStart();  
          system("CLS");
             if (programFunction!=FAILURE_NUM){
                programRun(programFunction);
             }      
          }
          
          if (input==1||input==4){
          
          optionsScreen();
          
          system("CLS");
          cout<<"Press A to start the game, S to change settings and Q to quit"<<endl;
          screenPaint.screenWriter(24,80, &chars[2]);
          }  
          
          if (input==2||input==5){
                                  
          return FAILURE_NUM;
          
          }                        
          
      }
                    
} while(true);

cout<<input<<endl;

return FAILURE_NUM_OTHER;
}


int SelectScreens::contextMenu(tile graphicData[SCREEN_HEIGHT][SCREEN_WIDTH])
{





return 0;
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
   functionRan=treeSort();
   break;

   case 2:
   functionRan=helloWorld();
   break;
   
   case 3:
   functionRan=futurePlans();     
   break;
   
   case 4:
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
   functionRun=dwarfGame(1);
   break;
   //more things to be added later
   
}

if (functionRun==FAILURE_NUM){
   cout<<"Failure to do stuff"<<endl;
}

}//end programRun

int treeSort()
{



return 1;
}

int SelectScreens::dwarfGame(int difficulty)
{
//struct tile graphicDataDwarf[SCREEN_WIDTH*SCREEN_HEIGHT];  



return 1;
}




