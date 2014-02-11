
#ifndef SCREENS_H
#define SCREENS_H 

#include "Keys.h"
#include "CursorOptions.h"
#include "Painter.h"

#define PRESSDELAY 5

#define SCREEN_HEIGHT 24
#define SCREEN_WIDTH 80

using namespace std;


//typedef struct screenGraphicData //user defined datatype
//{
//};

class SelectScreens
{

COptions cursorMod;
Keypress keyIO;
Painter screenPaint;

;;
public:
;;

int mainScreen(int versionNum);
void optionsScreen();
int gameStart();
int contextMenu(struct tile graphicData[SCREEN_HEIGHT][SCREEN_WIDTH]);
int dwarfGame();

;;

};

#endif
