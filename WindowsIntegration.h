
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
std::string directoryPath; //Example "C:/asdf/folder/another/"
bool directorySet;


int findAllFiles(char* fileName, std::vector<WIN32_FIND_DATA>* outputArray);
int findAllFilesInFolder(const char* folderPath, const char* fileName, std::vector<WIN32_FIND_DATA>* outputArray);

std::string getExecutablePath();
bool deleteFile(std::string fileName, bool isInDir);
int deleteFolder(std::string* folderPath, std::string* folderName);

private:

std::vector <WIN32_FIND_DATA> allItemsInformation;
      

      
};






#endif
