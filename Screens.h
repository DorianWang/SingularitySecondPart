
#ifndef SCREENS_H
#define SCREENS_H 

#include "Keys.h"
#include "CursorOptions.h"

#define PRESSDELAY 5

#define SCREEN_HEIGHT 24
#define SCREEN_WIDTH 80

using namespace std;

typedef struct interactObject
{
   std::string nameObject;     
   int objectType;     
   int objectAlignment; //what it is (hostile, friendly, neutral, etc)
   int numUse;  
   int specialType;//normally 0, different for other things
};

typedef struct tile
{
   char tileSymbol;
   interactObject tileEntities;     
   int xCoord;
   int yCoord;     
};


//typedef struct screenGraphicData //user defined datatype
//{
//};

class SelectScreens
{

COptions cursorMod;
Keypress keyIO;

;;
public:
;;

int mainScreen(int versionNum);
void optionsScreen();
int gameStart();
int contextMenu(tile graphicData[SCREEN_HEIGHT][SCREEN_WIDTH]);
int dwarfGame();

;;

};

#endif
