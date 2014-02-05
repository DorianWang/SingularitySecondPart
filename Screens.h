
#ifndef SCREENS_H
#define SCREENS_H 

#include "Keys.h"
#include "CursorOptions.h"

#define PRESSDELAY 5

using namespace std;



class SelectScreens
{

COptions cursorMod;
Keypress keyIO;

public:

int mainScreen(int versionNum);
void optionsScreen();
int gameStart();


;;

};

#endif
