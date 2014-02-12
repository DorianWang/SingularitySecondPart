
#include "Painter.h"
          
//   screenFill();      
      
Painter::Painter()
{
                  
                  
                  
}    

Painter::~Painter()
{
                  
                
                  
}      
      
      
      
void Painter::screenWriter(int screenHeight, int screenWidth, char* screenData)//use of C string for class
{
   for (int j=1;j<screenHeight;j++){  
     
      for (int i=1;i<screenWidth;i++){
           cout<<screenData[((j-1)*80)+i];
      }    
        //cout<<"hello";
   }     
        
      
}
   
//void Painter::screenRedraw(screenGraphicData *screenData, int screenHeight, int screenWidth); 
//{}    
      
      
      
      
      

