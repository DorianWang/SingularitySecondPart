
#include "Painter.h"
          
//   screenFill();      
      
Painter::Painter()
{
                  
                  
                  
}    

Painter::~Painter()
{
                  
                
                  
}      
      

bool Painter::screenWriter(int screenHeight, int screenWidth, char*screenData, int startX, int startY, int overwriteNum, HANDLE cHandle)
{
   COORD cursorStart;
   if (startX<=screenWidth&&startX>0){
   cursorStart.X=startX;   
   }
   
   if (startY<=screenHeight&&startY>0){
   cursorStart.Y=startY;   
   }
   SetConsoleCursorPosition(cHandle,cursorStart);
      
   return false;
}      

void Painter::screenWriter(int screenHeight, int screenWidth, char* screenData)//use of C string for class
{
     
   for (int j=1;j<screenHeight;)
        cout<<screenData<<endl;
        cout<<"hello";
        
        
        
        
        
        
}
   
//void Painter::screenRedraw(screenGraphicData *screenData, int screenHeight, int screenWidth); 
//{}    
      
      
      
      
      

