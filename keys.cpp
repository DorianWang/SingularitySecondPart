
#include <iostream>
#include <cstdlib>
#include "conio.h"
#include "keys.h"
#include "windows.h"

int Keypress::get_code(std::string importantKeys){
int ch = getch();
int i;

for(i=0;i<importantKeys.length();i++){
        if(ch==importantKeys[i]){
            return i;                     
                                 }
        }
        return -1;
}// get_code

//returns 1 for enter, 2 for escape,3 for TAB etc.
//http://msdn.microsoft.com/en-us/library/windows/desktop/ms646293%28v=vs.85%29.aspx
//Please do not use.
int Keypress::get_code(){
   if (GetAsyncKeyState(VK_RETURN)){                                
      return 1;                                
   }
   else if (GetAsyncKeyState(VK_ESCAPE)){                              
      return 2;                              
   }
   else if (GetAsyncKeyState(VK_TAB)){                              
      return 3;                               
   }
   else if (GetAsyncKeyState(VK_SPACE)){
      return 4;                                
   }
   else if (GetAsyncKeyState(VK_BACK)){
      return 5;     
   }
   if (GetAsyncKeyState(VK_LBUTTON)||GetAsyncKeyState(VK_RBUTTON)){
      return 6;   
   }

    return -1;//No keys found
}

//Windows specific
bool Keypress::get_code(int keyCode)
{
   switch (keyCode):
          
      case 1:
         return GetAsyncKeyState(VK_RETURN);//Enter key
         break;
      case 2:
         return GetAsyncKeyState(VK_ESCAPE);//Escape key
         break;
      case 3:
         return GetAsyncKeyState(VK_TAB);//TAB key
         break;
      case 4:
         return GetAsyncKeyState(VK_SPACE);//Spacebar
         break;
      case 5:
         return GetAsyncKeyState(VK_BACK);//Backspace key
         break;
      case 6:    
         return (GetAsyncKeyState(VK_LBUTTON)||GetAsyncKeyState(VK_RBUTTON))//Any mouse button
         break;
      case 7:
         return (GetAsyncKeyState(VK_LBUTTON))//Left mouse button
         break;
      case 8:
         return GetAsyncKeyState(VK_RBUTTON);
         break;
      case 9:
}
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
    
    
    
    
    
    
    
    
    
    
    
    
    




