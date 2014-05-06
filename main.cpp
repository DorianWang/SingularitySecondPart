
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
#include "FileIO.h"

#include "Painter.h"
#include "Encrypt.h"



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

int powerTo(int base, int exponential){
   unsigned int output = 1;
   if (exponential<=0){
      return 1;//No fractions!   
   }
   
   for (int i=0; i<exponential; i++){
      output = output * exponential;
   }
   
   return output;
}

std::vector <std::string> createTestCases(int testCaseSize)
{
   cout<<testCaseSize<<endl;
   std::string temp;
   std::vector <std::string> output;
   std::vector <std::string> inputOutput;
   output.reserve(powerTo(52, testCaseSize) + powerTo(52, testCaseSize/2));
   int counter=0;
   char allChars[52];//All the chars I want. Only letters for now.
   //65 - 90, 97 - 122
   //cout<<"Stuff!"<<endl;
   for (int i='a';i<='z';i++){
      allChars[i-'a']=i;    
   }
   for (int i='A'; i<='Z';i++){
      allChars[i + 'z' - 'a' - 'A' + 1] = i;  
   }
   
   //cout<<"End stuff!"<<endl;
   //cout<<"Why you so sad!"<<" "<<testCaseSize<<endl;
   int currentInt[testCaseSize];//={65};
   
   for (int i=0; i<testCaseSize;i++){
      currentInt[i] = allChars[0] - 'a';    
   }

   while(true){
               
      for (int i=testCaseSize-1; i>=0;i--){
         cout<<"One loop done!"<<endl;
         if (currentInt[i]>=52){
            if (i==(0)){
               if (testCaseSize>1){
                  inputOutput = createTestCases(testCaseSize - 1);
                  output.insert(output.end(), inputOutput.begin(), inputOutput.end());
               }
               
               return output;
            }
            currentInt[i-1]+=1; currentInt[i] = 0;
            
         }
      }
      
      for (int i = 0; i<testCaseSize; i++){
         temp += allChars[currentInt[i]];
      }
      output.push_back(temp);
      temp.clear();
      counter++;
      
   currentInt[testCaseSize-1]+=1;
   }
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
   //cout<<sizeof(asdf)<<endl;
   //*((float*)(buffer)) = asdf;
//   *((int*)(buffer+sizeof(float))) = asdfs;
//   cout<< *((float*)buffer)<<endl;
//   cout<< *((int*)(buffer+sizeof(float)))<<endl;
   
   
//   char buffer2[5];
//   buffer2[4]=0;
//   void* test;
//   test = (char*)asdfs;
//   
//   unsigned char bytes[4];
//unsigned long n = 175;
//
//
//for (int i=0;i<sizeof(int);i++){
//   bytes[0] = (n >> 24) & 0xFF;
//   bytes[1] = (n >> 16) & 0xFF;
//   bytes[2] = (n >> 8) & 0xFF;
//   bytes[3] = n & 0xFF;
//}
//   cout<<buffer2<<endl;
   
//   std::string empty;
//   std::string ijn = "zxcv";
//   cout<<empty<<endl;
//   empty+="asdf";
//   cout<<empty<<" "<<empty.length()<<endl;
//   empty+="qwer";
//   cout<<empty<<" "<<empty.length()<<endl;
//   empty+=ijn;
//   cout<<empty<<" "<<empty.length()<<endl;
   
   //fstream myfile;
   //myfile.open("D:/Asdf.bin",  ios::out | ios::in | ios::binary);
   //myfile.open("Data/Asdfg.bin",  ios::out | ios::binary);//creates the file if it doesn't exist yet
   //myfile.write(buffer, 2);
   //myfile.close();
   
   FileIO myFile;//FileIO has been tested, and appears to work...
   
   myFile.textOpenFile("Data/PasswordTest.txt", false);
   
   
   Encryter Bromo;
   //system("PAUSE");
   std::string password = "TESING STUFF";
   std::string newPass;
   std::vector<std::string> testCases ;
   std::vector<unsigned int> testAnswers;
   unsigned int tempInt;
   stringstream ss;
   int numCollisions = 0;
   //std::getline (std::cin, password);//Unlimited size of passwords
   //std::cin.getline(password, 64);//Passwords are up to 64 chars in size
   //Bromo.passwordToInt(password);
   
   int k=0;
   testCases = createTestCases(4);//(testCaseSize)
   int vectorSize = testCases.size();
   cout<<vectorSize<<endl;
   //system("PAUSE");

   for (int i=0; i<vectorSize;i++){
      cout<<i<<endl;
      newPass.clear();
      newPass = testCases[i];
      if (newPass.empty()){
         break;
      }
      cout<<newPass<<endl;
      tempInt = Bromo.passwordToHashInt(newPass);
      //cout<<tempInt<<" Hash things!"<<endl;
      testAnswers.push_back(tempInt);
      //system("PAUSE");
   }


   
   cout<<"Is this bad?"<<vectorSize<<endl;
   std::sort (testAnswers.begin(), testAnswers.end());
   //system("PAUSE");
   int numMult=0; unsigned int currentNumFound = testAnswers[0];
   for (int i=0; i<20;i++){
      cout<<testAnswers[i]<<endl;
   }
   
   for(int i=0; i<vectorSize;i++){
           cout<<i<<endl;
      while(true){
         if (i==(vectorSize-1)){
            cout<<"The END!"<<endl;
            break;
         }
         
         if (currentNumFound!=testAnswers[i]){
            i--;
            currentNumFound = testAnswers[i+1];
            if (numMult>2){
               cout<<"There are "<<numMult<<" of the number "
               <<testAnswers[i+1]<<endl;
               ss<<"There are "<<numMult<<" of the number "
               <<testAnswers[i+1]<<endl;
               numCollisions +=numMult;
               myFile.bufferLines(ss.str());
               ss.str( std::string() );
               ss.clear();
            }
            numMult = 0;
            break;
         }
         numMult++;
         i++;
         cout<<i<<" "<<numMult<<" "<<testAnswers[i]<<endl;
         //system("PAUSE");
      }
   }
   ss.str( std::string() );
   ss.clear();
   ss<<numCollisions<<" "<<vectorSize<<endl;
   myFile.bufferLines(ss.str());
   ss.str( std::string() );
   ss.clear();
   float percentError=0.000;
   percentError = (float)numCollisions / (float)vectorSize;
   percentError = percentError*100.000;
   ss<<"The percent collision was "<<percentError<<"% !"<<endl;
   myFile.bufferLines(ss.str());
   myFile.writeBuffer();


//   for(int i=0; i<vectorSize;i++){
//      while(true){
//         if (i!=vectorSize-1){
//            break;
//         }
//         
//         if (currentNumFound!=testAnswers[i]){
//            i--;
//            currentNumFound = testAnswers[i];
//            newPass.clear();
//            newPass += "There are ";
//            neewPass += numMult;
//            cout<<"There are "<<numMult<<" of the number "
//            <<testAnswers[i]<<endl;
//            numMult = 1;
//            break;
//         }
//         numMult++;
//         i++;
//      }
//   }
   
   //Bromo.keygenChars();
//   char qwer[16]="asd";
//   char* keyName=qwer;
//   std::string fileName = "Data/";
//   fileName += keyName;
//   cout<<fileName<<endl;;
   
   MyContainer Aso;
   SelectScreens ScreenControl;
   


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



