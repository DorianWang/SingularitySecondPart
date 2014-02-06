

#include "Screens.h"


#include <sstream>
#include <iostream>




void SelectScreens::optionsScreen(){

system("CLS");

int input;
cursorMod.cursorControl(5);
cout<<"Press A to make the cursor visible, S to make it invisible"<<endl;
cout<<"D to change the text colour, F to return it to defaults"<<endl;
cout<<"G forces the cursor to toggle visibility"<<endl;
cout<<"Press Q to close the options screen"<<endl;
cursorMod.cursorControl(6);
cout<<"Test line"; // 9 characters
do{
   input = keyIO.get_code("asdfgqASDFGQ");             

      if (input!=-1){             
          
          if (input==0||input==6){
          cursorMod.cursorControl(0);
                                  
          }
          
          if (input==1||input==7){
          cursorMod.cursorControl(1);
          
          }  
          
          if (input==2||input==8){                      
          cursorMod.cursorControl(2);
          
          }                        
          
          if (input==3||input==9){                      
          cursorMod.cursorControl(3);
          
          }
          
          if (input==4||input==10){                       
          cursorMod.cursorControl(4);
          
          }
          
          if (input==5||input==11){
          Sleep(PRESSDELAY);
          break;
          //closer
          }
          
          cout << string(9 ,'\b');
          cout <<"Test line";
          Sleep(PRESSDELAY);
      }
                    
} while(true);     
     
     
     
     
     
}

int SelectScreens::gameStart()
{
int input;
system("CLS");
     
cout<<"Please select your difficulty."<<endl<<endl;

cout<<"Super easy - Z"<<endl;
cout<<"Easy - A"<<endl;
cout<<"Normal - S"<<endl;
cout<<"Hard - D"<<endl;
cout<<"Nintendo Hard - N"<<endl;
     
do{     
   input=keyIO.get_code("zasdnZASDN");

   if (input==-1){
   
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
   
 /*  switch(input){
      case (-1):
                 
      case (1||6):
         return input;
         break;
      case (2||7):
         return input;
         break;
      case (3||8):
         return input;
         break;
      case (4||9):
         return input;
         break;
      case (5||10):
         return input;
         break;
      default:
         return 0;
         break;      
   }
   */
}while(true);     
     
     
     
     
}


int SelectScreens::mainScreen(int versionNum)
{

stringstream ss (stringstream::in | stringstream::out);

ss<<versionNum;          
string out = ss.str();     
int input;
cursorMod.cursorControl(3);


cout<<"Welcome to version " + out + " of singularity."<<endl<<endl;
system("PAUSE");
system("CLS");
cout<<"Press A to start the game, S to change settings and Q to quit"<<endl;

do{
   input = keyIO.get_code("asqASQ");             

      if (input!=-1){             
          
          if (input==0||input==3){
          
          gameStart();
                                  
          }
          
          if (input==1||input==4){
          
          optionsScreen();
          
          system("CLS");
          cout<<"Press A to start the game, S to change settings and Q to quit"<<endl;
          
          }  
          
          if (input==2||input==5){
                                  
          return -1;
          
          }                        
          
      }
                    
} while(true);

cout<<input<<endl;

return -2;
}


int contextMenu(int *locationData[], )
{

















}


