
#include <cstdlib>
#include <iostream>

using namespace std;

struct interactObject
{
   std::string nameObject;     
   int objectType;     
   int objectAlignment; //what it is (hostile, friendly, neutral, etc)
   int numUse;  
   int specialType;//normally 0, different for other things
};

struct tile
{
   char tileSymbol;
   interactObject tileEntities;     
   int xCoord;
   int yCoord;     
};

#include "Container.h"
#include "Bases.h"
#include "keys.h"
#include "CursorOptions.h"
#include "Screens.h"
#include "FileIO.h"

#include "Painter.h"
#include "Encrypt.h"



// global variables
#define VERSION_NUM 1




//Keypress keyIO;
bool cursorVisibility = false;
bool cursorSmall = true;





int main(int argc, char *argv[])
{
    //char asdf=176;
    //char asdfg=177;
    //char asdfgh=178;
    //char qwe = 43;
    //cout<<asdfgh<<qwe<<asdfgh<<qwe<<endl;
    //cout<<asdfgh<<asdfgh<<qwe<<asdfgh<<qwe<<endl;
    //219 -> 178 -> 177 -> 176 -> 43
   Encryter Bromo;
   Bromo.keygen();
   MyContainer Aso;
   SelectScreens ScreenControl;
   // int asdf = 0;
    
   // for (int i =1; i<17;i++){
   // asdf=toggleColour(consoleHandle);
   // cout<<"hello"<<asdf<<endl;
   // Sleep(750);
   // }
    
   //ScreenControl.mainScreen(VERSION_NUM);
   //^Important for code n' stuff
    
   //I don't want to reach this, should I remove it?
   //system("PAUSE");
   
   return EXIT_SUCCESS;
}



