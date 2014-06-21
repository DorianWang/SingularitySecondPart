
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






