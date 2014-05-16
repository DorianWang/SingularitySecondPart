
#ifndef WINDOWS_INT_H
#define WINDOWS_INT_H

#include <iostream>
#include <string>
#include <vector>

#include "Windows.h"

class winCnrl
{

public:
std::string directoryPath;



bool findAllFiles(char* fileName);
       
private:

std::vector <WIN32_FIND_DATA> allItemsInformation;
      

      
}






#endif
