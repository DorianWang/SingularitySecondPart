
#include "WindowsIntegration.h"

//Finds all files in the directory
//The user is required to append or prepend wildcards, etc.
int winCnrl::findAllFiles(char* fileName, std::vector<WIN32_FIND_DATA>* outputArray)
{

directorySet = true;//Temporary thing

if (directorySet == false){
   return -1;//Directory is not set   
}
     
//bool allFiles = false;
int stringLength;
std::string filePath; std::string temp;

LARGE_INTEGER filesize; //long long 64 bit

WIN32_FIND_DATA tempFile;
HANDLE hFind = INVALID_HANDLE_VALUE;
DWORD dwError=0;
TCHAR szDir[MAX_FILE_PATH];

   if (fileName == NULL){
      filePath = directoryPath + "\\*";//Search for all files and folders.
   }
   else
   {
      stringLength = strlen(fileName);
      
      if ((stringLength + 3)>MAX_FILE_PATH){
         return -1;//String is too long...
      }
      filePath = directoryPath + fileName;
   }    

   hFind = FindFirstFile(filePath.c_str(), &tempFile);

   if (INVALID_HANDLE_VALUE == hFind) 
   {
      return 0;//Did not get anything...
   } 
   
   do
   {
      (*outputArray).push_back(tempFile);
   } while (FindNextFile(hFind, &tempFile) != 0);
    
   dwError = GetLastError();
   if (dwError != ERROR_NO_MORE_FILES){
      return -1;//Failure due to some problem...
   }
   
   FindClose(hFind);
   return 1;
}

//Incomplete
//fodlerPath must be appended with a slash.
int winCnrl::findAllFilesInFolder(const char* folderPath, const char* fileName, std::vector<WIN32_FIND_DATA>* outputArray)
{
   if (folderPath == NULL  || outputArray == NULL){
      return -1;//Pointers cannot be null  
   }
   std::string filePath = folderPath;
   
   if (fileName != NULL){
      filePath += fileName;   
   }
   else
   {
      filePath+="*";
   }
   
   std::cout<<filePath<<std::endl;
   
   if ((filePath.length() + 3)>MAX_FILE_PATH){
      return -1;//String is too long...
   }
   
   DWORD dwError=0;
   WIN32_FIND_DATA tempFile; HANDLE hFind = INVALID_HANDLE_VALUE;
   hFind = FindFirstFile(filePath.c_str(), &tempFile);
   
   if (hFind == INVALID_HANDLE_VALUE){
      return 0;   
   }
   
   do{
      (*outputArray).push_back(tempFile);
   } while (FindNextFile(hFind, &tempFile) != 0);
   
   if (dwError != ERROR_NO_MORE_FILES){
      FindClose(hFind);
      return -2;//Failure due to some problem...
   }
   
   FindClose(hFind);
   return 1;
}

std::string winCnrl::getExecutablePath()
{
char pathName[MAX_FILE_PATH + 4];
   int charsGotten = GetModuleFileName(NULL, pathName, MAX_FILE_PATH + 4);
   pathName[charsGotten] = 0;//Null termination of string
   std::string output (pathName);
   return output;
}

bool winCnrl::deleteFile(std::string fileName, bool isInDir)
{    
std::string filePath;
if (isInDir){
   filePath = directoryPath + fileName;    
}
if (filePath.length()+1>MAX_FILE_PATH){
   return false;   
}

int successNum = DeleteFile(filePath.c_str());
return successNum;
}

//Folder names should be appended with a backslash
int winCnrl::deleteFolder(std::string* folderPath, std::string* folderName)
{
std::string completePath;

if (folderPath == NULL){
   completePath = directoryPath + *folderName;
}
else
{
   if (folderName != NULL){
      completePath = *folderPath + *folderName;       
   }
   else
   {
      completePath = *folderPath;   
   }

}

std::vector<WIN32_FIND_DATA> allItems;

if (completePath.length() + 3 > MAX_FILE_PATH){
   return -1;//Uh oh...   
}

if (completePath[completePath.length() - 1] !='\\'){
   completePath += "\\";
}

int findFilesReturnNum = findAllFilesInFolder(completePath.c_str(), NULL, &allItems);

std::cout<<findFilesReturnNum<<" asdf"<<std::endl;
std::cout<<completePath<<" asdf"<<std::endl;

if (findFilesReturnNum == -1 || findFilesReturnNum == -2){
   return 0;//Fatal error!
}

if (findFilesReturnNum == 0){
   return RemoveDirectory(completePath.c_str());
}

int numItemsInFolder = allItems.size(); bool returnValue = true;

std::string tempPath = completePath;

for (int i=0; i<numItemsInFolder; i++){
    
   if (allItems[i].dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY){
      tempPath = tempPath + allItems[i].cFileName;
      returnValue = deleteFolder(&tempPath, NULL);
      tempPath = completePath;
   }
   else
   {
      returnValue = deleteFile(completePath + allItems[i].cFileName, false);
   }
   
   if (!returnValue){
      return returnValue;   
   }
   
}

return RemoveDirectory(completePath.c_str());
}































