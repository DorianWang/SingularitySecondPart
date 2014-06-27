

#ifndef KEYS_H
#define KEYS_H 

#include <string>

//Windows virtual keys
#define ZERO_CODE 0x30 
#define LOWER_A_CODE 0x41 


using namespace std;

class Keypress
{
      
public:      
      
int get_code(std::string importantKeys);      
int get_code();      
      
      
};


//http://msdn.microsoft.com/en-us/library/windows/desktop/ms645617%28v=vs.85%29.aspx
//Ideas for control?












#endif
