
#include "WindowsIntegration.h"









//void DisplayErrorBox(LPTSTR lpszFunction) 
//{ 
//    // Retrieve the system error message for the last-error code
//
//    LPVOID lpMsgBuf;
//    LPVOID lpDisplayBuf;
//    DWORD dw = GetLastError(); 
//
//    FormatMessage(
//        FORMAT_MESSAGE_ALLOCATE_BUFFER | 
//        FORMAT_MESSAGE_FROM_SYSTEM |
//        FORMAT_MESSAGE_IGNORE_INSERTS,
//        NULL,
//        dw,
//        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
//        (LPTSTR) &lpMsgBuf,
//        0, NULL );
//
//    // Display the error message and clean up
//
//    lpDisplayBuf = (LPVOID)LocalAlloc(LMEM_ZEROINIT, 
//        (lstrlen((LPCTSTR)lpMsgBuf)+lstrlen((LPCTSTR)lpszFunction)+40)*sizeof(TCHAR)); 
//    StringCchPrintf((LPTSTR)lpDisplayBuf, 
//        LocalSize(lpDisplayBuf) / sizeof(TCHAR),
//        TEXT("%s failed with error %d: %s"), 
//        lpszFunction, dw, lpMsgBuf); 
//    MessageBox(NULL, (LPCTSTR)lpDisplayBuf, TEXT("Error"), MB_OK); 
//
//    LocalFree(lpMsgBuf);
//    LocalFree(lpDisplayBuf);
//}

// http://www.cplusplus.com/reference/cstdlib/mbtowc/
int winCnrl::charPToWCharP(const char* input, wchar_t* output, int bufferSize)
{
         std::cout<<"qwer"<<std::endl;
   if ((strlen(input) + 1)>bufferSize){
      return 0;//Buffer is not large enough.
   }
         std::cout<<"qwer"<<std::endl;
   size_t newsize = strlen(input) + 1;
   wchar_t wcstring[newsize];
   size_t max = strlen(input); int length = 0;
   int counter = 0;
   
   mbtowc (NULL, NULL, 0);  /* reset mbtowc */
   //std::cout<<"qwer"<<std::endl;
   //std::cout<<max<<" "<<bufferSize<<std::endl;
   while (max>0&&bufferSize>counter) {
      length = mbtowc(&(wcstring[counter]), (input + counter), max);
      if (length<1){ 
               std::cout<<"qwers"<<std::endl;
         break;
      }
      //std::cout<<"qwer"<<std::endl;
      printf ("[%lc]",wcstring[counter]);
      output[counter] = wcstring[counter];
      std::cout<<wcstring[counter]<<std::endl;
      counter+=length; max-=length;
   }
   wchar_t newLine = '\n';
   output[counter] = newLine;
   return counter;

      //mbtowc
   
   
   //mbstowcs_s(&convertedChars, wcstring, newsize, input, _TRUNCATE);
   // Display the result and indicate the type of string that it is.
   //wcout << wcstring << _T(" (wchar_t *)") << endl;    
}








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

      filePath = directoryPath;
      if (filePath.at(filePath.length() - 1) != '/' || filePath.at(filePath.length() - 1) != '\\'){
         filePath +='/';//Appends a slash if there is not one already.   
      } 
      filePath += "*";//Search for all files and folders.
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
      std::cout<<tempFile.cFileName<<std::endl;
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
      if (!(filePath.at(filePath.length() - 1) != '/' || filePath.at(filePath.length() - 1) != '\\')){
         filePath +='/';//Appends a slash if there is not one already.   
      }
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
      //std::cout<<"afejbhku"<<std::endl;
      return 0;   
   }
   
   int counter = 0;
   
   do{
      counter++;
      (*outputArray).push_back(tempFile);
      //std::cout<<tempFile.cFileName<<std::endl;
   } while (FindNextFile(hFind, &tempFile) != 0);
   
   if (counter <= 2){
      //std::cout<<"iuqwehfiuheb"<<std::endl;
      return 0;   
   }
   
   dwError = GetLastError();
   if (dwError != ERROR_NO_MORE_FILES){
      FindClose(hFind);
      std::cout<<dwError<<std::endl;
      //DisplayErrorBox(TEXT("FindFirstFile"));
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

if (!!(completePath[completePath.length() - 1] !='\\' && completePath[completePath.length() - 1] != '/')){
   completePath += "\\";
}

int findFilesReturnNum = findAllFilesInFolder(completePath.c_str(), NULL, &allItems);

//std::cout<<findFilesReturnNum<<" asdf"<<std::endl;
//system("PAUSE");


if (findFilesReturnNum == -1 || findFilesReturnNum == -2){
   return 0;//Fatal error!
}

if (findFilesReturnNum == 0){
   completePath = completePath.substr(0, completePath.size()-1);
   std::cout<<completePath<<std::endl;
   //completePath.pop_back(); C++ 11...
   //std::cout<<findFilesReturnNum<<" aso"<<std::endl;
   
   //if (PathIsDirectoryEmpty(completePath.c_str()) != false){
      //return RemoveDirectory(completePath.c_str());
   //}
   
}

int numItemsInFolder = allItems.size(); bool returnValue = true;

std::string tempPath = completePath;

for (int i=2; i<numItemsInFolder; i++){

std::cout<<allItems[i].cFileName<<std::endl;

   if (allItems[i].dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY){
      
      if (allItems[i].cFileName == ".." || allItems[i].cFileName == "."){
         std::cout<<"???"<<std::endl;
      }
      
      tempPath = tempPath + allItems[i].cFileName;
      std::cout<<tempPath<<std::endl;
      returnValue = deleteFolder(&tempPath, NULL);
      tempPath = completePath;
   }
   else
   {
      tempPath += allItems[i].cFileName;
      std::cout<<tempPath<<std::endl;
      returnValue = DeleteFile(tempPath.c_str());
      
      tempPath = completePath;
   }
   
   if (returnValue<0){
      std::cout<<returnValue<<" BAD"<<std::endl;
      //return returnValue;   
   }
   
   if (returnValue>=0){
      std::cout<<returnValue<<std::endl;
      //return returnValue;
   }
   
}

return RemoveDirectory(completePath.c_str());
}































