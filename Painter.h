
#ifndef PAINTER_H
#define PAINTER_H 

#define SCREEN_HEIGHT 24
#define SCREEN_WIDTH 80

#include <string>
#include <cstdlib>
#include <iostream>



using namespace std;

class Painter
{
      
   int stuff;
      
   public:
          
   Painter();
   ~Painter();
   
   void screenWriter(int screenHeight, int screenWidth, char* screenData);
   //void screenRedraw(tile screenTiles[24][80], int screenHeight, int screenWidth);
   
   //tile *screenTiles[24][80]
   
   
};

#endif
