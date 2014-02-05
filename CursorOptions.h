
#ifndef COPTIONS_H
#define COPTIONS_H 

#include "windows.h"



using namespace std;

class COptions
{
      
bool cursorVisibility;
bool cursorSmall;
HANDLE consoleHandle;

int currentColour;

public:
             
COptions();
~COptions();

int toggleColour(HANDLE cHandle);      

void returnDefault(HANDLE cHandle);     
void toggleCursorSize(HANDLE cHandle);
void toggleCursor(HANDLE cHandle);
void tempColourChange(bool isDiff, HANDLE cHandle, int targetColour);


void cursorControl(int optionNum);//Controls all other functions. 0 for cursor visible. 1 for opposite, 2 for colour change, 5 for defaults, etc.

};

#endif
