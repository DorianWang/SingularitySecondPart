
#ifndef WINDOWS_INT_H
#define WINDOWS_INT_H

#define MAX_FILE_PATH 259
//The above value should be 260, but I'm not sure.

#include <iostream>
#include <string>
#include <vector>

#include <tchar.h> 
//#include <strsafe.h>

#include "Windows.h"


class winCnrl
{
//  http://msdn.microsoft.com/en-us/library/windows/desktop/aa365200%28v=vs.85%29.aspx


public:
std::string directoryPath;
bool directorySet;


bool findAllFiles(char* fileName);
       
private:

std::vector <WIN32_FIND_DATA> allItemsInformation;
      

      
};






#endif
