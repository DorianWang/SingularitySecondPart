
#include <cstdlib>
#include <iostream>


#include "Bases.h"
#include "keys.h"
#include "CursorOptions.h"
#include "Screens.h"

using namespace std;

// global variables
#define VERSION_NUM 1


Keypress keyIO;
bool cursorVisibility = false;
bool cursorSmall = true;





int main(int argc, char *argv[])
{
    
    SelectScreens ScreenControl;
   // int asdf = 0;
    
   // for (int i =1; i<17;i++){
   // asdf=toggleColour(consoleHandle);
   // cout<<"hello"<<asdf<<endl;
   // Sleep(750);
   // }
    
   ScreenControl.mainScreen(VERSION_NUM);
    
    
    
    //I don't want to reach this
    system("PAUSE");
    return EXIT_SUCCESS;
}



