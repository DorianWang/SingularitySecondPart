
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <sstream>

//MUSIC! http://www.youtube.com/watch?v=nDyzVV_e7WM&list=LL5I3vUh2iNfQ3pCU3sodYRA&shuffle=167714



using namespace std;

struct interactObject
{
   std::string nameObject;     
   int objectType;     
   int objectAlignment; //what it is (hostile, friendly, neutral, etc)
   int numUse;  
   int specialType;//normally 0, different for other things
};

struct tile
{
   char tileSymbol;
   interactObject tileEntities;     
   int xCoord;
   int yCoord;     
};

typedef struct tester
{
int a;
int b;
int c;
int d;
char e;
char f;        
};

#include "Container.h"
#include "Bases.h"
#include "keys.h"
#include "CursorOptions.h"
#include "Screens.h"
#include "WindowsIntegration.h"


#include "Painter.h"
#include "Encrypt.h"
#include "FileIO.h"


// global variables
#define VERSION_NUM 1




//Keypress keyIO;
bool cursorVisibility = false;
bool cursorSmall = true;

int poi(int size, ...)
{
   va_list ap;
   int j=0;
   char* asdf;
   va_start(ap, size); //Requires the last fixed parameter (to get the address)
   asdf=va_arg(ap, char*); //Requires the type to cast to. Increments ap to the next argument.
   va_end(ap);
   cout<<sizeof(asdf)<<"asdfasdf"<<endl;
   int counter=0;
   
   for (int i=0;i<(size/4)-1;i++){
      cout<<(int)((unsigned char)(*(asdf+i*4)))<<"."<<endl; 
      counter=i;
   }
   cout<<(char)((unsigned char)(*(asdf+counter*(4+1)+1)))<<"."<<endl; 
   cout<<(char)((unsigned char)(*(asdf+counter*(4+1)+2)))<<"."<<endl;
   //Yey! I can read/write structures!
   
   //for (int i=3;i>=0;i--){
//      cout<<(int)((unsigned char)(*(asdf+i)))<<"."<<endl; 
//      j = (j*256) + (int)((unsigned char)(*(asdf+i)));
//   }
   
//   
   
   cout<<j<<"qqq"<<endl;
}



void swap(int*a, int*b)
{
int temp = *a;
*a=*b;     
*b = temp;
}


int main(int argc, char *argv[])
{
    srand (time(NULL));
    //cout<<asdfgh<<qwe<<asdfgh<<qwe<<endl;
    //cout<<asdfgh<<asdfgh<<qwe<<asdfgh<<qwe<<endl;
    //219 -> 178 -> 177 -> 176 -> 43
   int poiu = 4321;
   poi(4, &poiu);

   float asdf = 24;
   int asdfs = 564;
   void* temp;
   char buffer[16];
   buffer[0]='0';buffer[1]='1';buffer[2]='5';buffer[3]='h';//buffer[4]='c';buffer[5]='d';buffer[6]='q';buffer[7]='h';
   buffer[8]='Q';buffer[9]=0;

   FileIO myFile;//FileIO has been tested, and appears to work...
   //However, there is more testing to be done!

//   myFile.textOpenFile("Data/Aso.txt", false);
//   std::string asos;
//   std::vector <std::string> fileBuffer;
//  
//   while(myFile.readLine(&asos)){
//      fileBuffer.push_back(asos);                              
//   }
//   
//   for (int i=0; i<fileBuffer.size();i++){
//      cout<<fileBuffer[i]<<"!"<<endl;;
//   }
   
//   myFile.closeFile();
   
   myFile.dataOpenFile("Data/Aso.bin", true);
   int intArray[5] = {65, 66, 67, 68, 69};
   char strings[23] = "This is another test!!";//22
   char inputString[23];//
   int newArray[5];
   cout<<myFile.writeData(sizeof(int), 5, intArray)<<endl;
   cout<<myFile.writeData(sizeof(char), 23, strings)<<endl;
   cout<<myFile.goStart(1)<<endl;
   int otherStuff = 0;
   int* stuff = &otherStuff;
   myFile.readData(sizeof(int), 5, stuff, newArray);
   cout<<otherStuff<<" Debug!"<<endl;
   
   myFile.readData(sizeof(char), 23, stuff, inputString);
   cout<<otherStuff<<endl;
   
   for (int i=0; i<5; i++){
      cout<<newArray[i]<<" ";    
   }
   cout<<endl;
   cout<<inputString;
   cout<<endl;
   myFile.closeFile();
   
   myFile.dataOpenFile("Data/Bromo.bin", true);
   int otherArray[4] = {4, 5, 6, 7};
   cout<<myFile.writeData(sizeof(int), 4, otherArray)<<endl;
   char strings2[23] = "Tihs is another tset??";//22
   cout<<myFile.writeData(sizeof(char), 23, strings2)<<endl;
   cout<<myFile.goStart(1)<<endl;   
   int otherStuff2 = 0;
   int* stuff2 = &otherStuff2;
   
   myFile.readData(sizeof(int), 4, stuff, newArray);
   cout<<otherStuff<<" Debug!"<<endl;
   
   myFile.readData(sizeof(char), 23, stuff, inputString);
   cout<<otherStuff<<endl;

   winCnrl Dempo;
   Encrypter Bromo;
   bool cipherType[5];
//   Bromo.keygenInts(cipherType, 4, std::string("MyFirstCipher"));
//   Bromo.createAllCiphers(cipherType, 6, NULL, "Data\\A", 26);
//   Bromo.createAllCiphers(cipherType, 6, NULL, "Data\\B", 26);
//   Bromo.createAllCiphers(cipherType, 6, NULL, "Data\\C", 26);
//   Bromo.createAllCiphers(cipherType, 6, NULL, "Data\\D", 26);
//   Bromo.createAllCiphers(cipherType, 6, NULL, "Data\\E", 26);
//   Bromo.createAllCiphers(cipherType, 6, NULL, "Data\\F", 26);
   std::string tempst = "ABCDEFAAA";
   //intRotor intsStuff[50];
   //cout<<Bromo.readCiphersFromFiles(tempst, intsStuff, "")<<"!!!"<<endl;
   //cout<<(char)248<<endl;

//   intRotor rotorArray[16]; bool sdfg[5];
//   FileIO newFile; newFile.textOpenFile("Data\\A\\FirstCipher0.acp", false);
//   int ciphersTaken = Bromo.getCiphersFromFile(rotorArray, sdfg, &newFile, 16);
   
//   for (int i=0; i<ciphersTaken; i++){
//      for (int j=0; j<(rotorArray[i].rotorLength);j++){
//          cout<<rotorArray[i].mapping[j]<<" ";
//      }
//      cout<<endl;
//   }

std::string folderStuff = "Stuff\\";
std::string folderStuffs = "asdfasdf";

std::string tempNameFolder = "asdfasdf";
//Dempo.directoryPath = "D:\\Test\\";
//Dempo.deleteFolder("asdfasdf", NULL);
//cout<<Dempo.deleteFolder(&folderStuff, &tempNameFolder)<<endl;


//std::string something = "D:/Test/Stuff/";
//std::string something2 = "D:/Test/";
//std::string something3 = "Stuff/";
//wchar_t stuffs[512];


//int lengthWString = Dempo.charPToWCharP(something.c_str(), stuffs, 512);
//stuffs

//Returns one is true, else 0;
//cout<<RemoveDirectory(something.c_str())<<endl;

std::vector<WIN32_FIND_DATA> uaehr;


//cout<<Dempo.findAllFilesInFolder(something.c_str(), NULL, &uaehr)<<" asdf"<<endl;
//^ Yey! It works now!
//cout<<Dempo.deleteFolder(NULL, &something3)<<endl;
//cout<<RemoveDirectory("D:\\Test\\Stuff\\qwer\\qwerqwer")<<" aukshfiuh "<<"D:\\Test\\Stuff\\qwer\\qwerqwer"<<endl;
//uaehr.clear();



//cout<<Dempo.findAllFilesInFolder(something.c_str(), NULL, &uaehr)<<" asdf"<<endl;

//cout<<Dempo.getExecutablePath()<<endl;

//std::string ijn = "Testing stuff";



//Dempo.charPToWCharP(ijn.c_str(), stuffs, 512);

int counters = 0;

//wchar_t newLine = '\n';

//while(stuffs[counters]!=newLine){
//printf ("%lc",stuffs[counters]);
////std::wcout<<stuffs[counters]<<endl;
//counters++;
//}


//printf ("%lc", newLine);

//cout<<endl;

   MyContainer Aso;
   SelectScreens ScreenControl;
   //cout<<Dempo.deleteFile(Dempo.getExecutablePath(), false)<<endl;

   // int asdf = 0;
    
   // for (int i =1; i<17;i++){
   // asdf=toggleColour(consoleHandle);
   // cout<<"hello"<<asdf<<endl;
   // Sleep(750);
   // }
    
   //ScreenControl.mainScreen(VERSION_NUM);
   //^Important for code n' stuff
    
   //I don't want to reach this, should I remove it?
   
   
   cout<<"I'm done!"<<endl;
   system("PAUSE");
   
   return EXIT_SUCCESS;
}



