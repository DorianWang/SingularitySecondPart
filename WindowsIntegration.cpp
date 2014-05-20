
#include "WindowsIntegration.h"

//Finds all files in the directory
bool winCnrl::findAllFiles(char* fileName)
{

if (directorySet == false){
   return false;//Directory is not set   
}
     
bool allFiles = false;
int stringLength;
std::string filePath; std::string temp;

LARGE_INTEGER filesize; //long long 64 bit

WIN32_FIND_DATA tempFile;
HANDLE hFind = INVALID_HANDLE_VALUE;
DWORD dwError=0;
TCHAR szDir[MAX_FILE_PATH];

if (fileName == NULL){
   allFiles = true;
}
else
{
   stringLength = strlen(fileName);
   
   if ((stringLength + 3)>MAX_FILE_PATH){
      return false;//String is too long...
   }
}

   
   if (allFiles){
      filePath = directoryPath + "\\*";//Search for all files and folders.
      
      
   
      hFind = FindFirstFile(szDir, &tempFile);
   
      if (INVALID_HANDLE_VALUE == hFind) 
      {
         return 0;//Did not get anything...
      } 
         do
         {
            allItemsInformation.push_back(tempFile);
         }while (FindNextFile(hFind, &tempFile) != 0);
       
         dwError = GetLastError();
         if (dwError != ERROR_NO_MORE_FILES){
            return 0;//Failure due to some problem...
         }
      
         FindClose(hFind);
      
   
   }
}





