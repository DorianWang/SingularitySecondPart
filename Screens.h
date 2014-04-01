
#ifndef SCREENS_H
#define SCREENS_H 

#include <fstream>
#include <vector>
#include <map>

#include "Keys.h"
#include "CursorOptions.h"
#include "Painter.h"

#define PRESSDELAY 5
#define SUCCESS_NUM 1
#define FAILURE_NUM -1
#define FAILURE_NUM_OTHER -2

#define MAX_LINE_LENGTH 510

#define SCREEN_HEIGHT 24
#define SCREEN_WIDTH 80

using namespace std;


//typedef struct screenGraphicData //user defined datatype
//{
//};

typedef struct treeNodeBinary
{
        
int intData;
int metaData;
char moreMetaData;

treeNodeBinary* parent;
treeNodeBinary* left;
treeNodeBinary* right;

};

class SelectScreens
{

COptions cursorMod;
Keypress keyIO;
Painter screenPaint;
;;
std::string studentDrive;
;;
public:
;;

//SelectScreens();
//~SelectScreens();

int mainScreen(int versionNum);
void optionsScreen();
int gameStart();
int contextMenu(struct tile graphicData[SCREEN_HEIGHT][SCREEN_WIDTH]);
int dwarfGame(int difficulty);
void programRun(int programNum);

void findMyDocsWindows(char* myDocsPath);

int treeSort();
int helloWorld();
int futurePlans();

;;
private:
        
int stringThing(int inputNum, int outputNum, int stringLength);        
        

};

#endif





