
#include <cstdarg>
#include <iostream>
#include <fstream>

using namespace std;
//For dataType, 
//0 for int, 1 for char, 2 for float, 3 for double, 4 for short, 5 for long long, 6 for unsigned int...
//7 for unsigned short,  More may be added later.

//numWanted is the length of the array. (note, a pointer to a single thing is still treated like an array)
//returns 0 for failure, else 1
int readData(int dataType, int arrayLength, ...)
{
   //int *asdf;
   char buffer[256];
   void * output;
   //void * temp;
   int bytesToGet=4;
   int j = 0;
   if (dataType>=5||dataType<=-1){
      return 0;
   }
   
   if (arrayLength<0) return 0;
   
   bytesToGet = 1;
   
   if (dataType==1){ bytesToGet = 1;}
   
   if (dataType==3||dataType==5){ bytesToGet = 8;}
   
   if (dataType==4){ bytesToGet = 2;}
   
   va_list ap;
   //va_start(ap, numWanted);

   output = va_arg(ap, void *);
   
   if (output==0) return 0;
   
   for (j=0;j<arrayLength;j++){
      //read bytes, chance to fail...
      //myfile.read(buffer, bytesToGet);
      //if (myfile.eof()&&myfile.fail()) return 0; //hit end of file...
      //switch (dataType) {
//         case 0:
//            *((int*)output) = cToI(buffer);
//            break;
//         case 1:
//            *((char*)output) = buffer[j];
//            break;
//         case 2:
//            *((float*)output) = *((float*)((buffer)));
//            break;
//         case 3:
//            *((double*)output) = *((double*)((buffer)));
//            break;
//         case 4:
//            *((short*)output) = cToS(buffer);
//            break;
//         case 5:
//            *((long long*)output) = *((long long*)((buffer)));
//            break;
//         case 6:
//            *((unsigned int*)output) = cToUI(buffer);
//            break;
//         case 7:
//            *((unsigned short*)output) = cToUS(buffer);
//            break;
//         case 8:
//            //*((long long*)output) = *((long long*)((buffer)));
//            break;
//           
//      }

   }
   //http://www.dreamincode.net/forums/topic/47339-writing-floats-to-a-file/
   //in.read((char *)&f2,sizeof(float));
   //*((int *)output) = qwer;
return 1;
}//Unfinished

bool getProfile(std::string name)
{

ifstream myfile;
std::string fileName;
fileName= "saves/"+name+".dat";
myfile.open (fileName.c_str());
 	
   if (myfile.is_open()) {
      cout<<"yey!";
      return true;
   }

}

bool makeProfile(std::string name)
{

ofstream myfile;  
std::string fileName;  
fileName = "saves/"+name+".dat"; 
myfile.open(fileName.c_str());     
     
if (myfile.is_open()){
   cout<<"yey!";                   
   myfile << "Writing this to a file.\n";                        
}     
         
}

   
//   switch (dataType) {
//      case 0:
//         *((int*)output) = cToI(buffer);
//         break;
//      case 1:
//         *((char*)output) = buffer[j];
//         break;
//      case 2:
//         *((float*)output) = *((float*)((buffer)));
//         break;
//      case 3:
//         *((double*)output) = *((double*)((buffer)));
//         break;
//      case 4:
//         *((short*)output) = cToS(buffer);
//         break;
//      case 5:
//         *((long long*)output) = *((long long*)((buffer)));
//         break;
//      case 6:
//         *((unsigned int*)output) = cToUI(buffer);
//         break;
//      case 7:
//         *((unsigned short*)output) = cToUS(buffer);
//         break;
//      case 8:
//         //*((long long*)output) = *((long long*)((buffer)));
//         break;
// }
   //http://www.dreamincode.net/forums/topic/47339-writing-floats-to-a-file/
   //in.read((char *)&f2,sizeof(float));
   //*((int *)output) = qwer;



   //int asos[512];
//   for (int i=0;i<512;i++){
//      asos[i]=i%26+65;cout<<asos[i]<<" "<<i<<endl;
//   }
//   testingSize.a = 1;testingSize.b = 2; testingSize.c = 3; testingSize.d = 4;
//   testingSize.e = 'q'; testingSize.f = 'w';
//   
//   //poi(sizeof(testingSize), &testingSize);
//   cout<<"..."<<endl;
//   myFile.goStart(0);
//   myFile.writeData(sizeof(asos[0]), 512, asos);
//   
//   for (int i=0;i<512;i++){
//      asos[i]=0;
//   }
//   
//   cout<<myFile.readData(0, 512, asos);
//   system("PAUSE");
//   
//   for (int i=0;i<(512/2);i++){//Sort of works... Why?
//   //   asos[i]=i*2;
//   cout<<asos[i*2]<<" "<<asos[i*2+1]<<": "<<i<<endl;
//   }


//   cout<<"???1"<<endl;
//   myFile.textOpenFile("Data/test.txt", true);//Putting true there overwrites the original data.
//   cout<<"???2"<<endl;
//   myFile.bufferLines("Hello!");
//   cout<<"???3"<<endl;
//   myFile.bufferLines("Can you hear me?");
//   cout<<"???4"<<endl;
//   myFile.bufferLines("Now for other stuff!");
//   cout<<"???5";
//   myFile.writeBuffer();
//   system("PAUSE");
//   myFile.bufferLines("Hello!X2");
//   system("PAUSE");
//   myFile.writeBuffer();
//   myFile.bufferAddition("Adding to buffer...");myFile.bufferAddition("\nAdding to buffer...");
//   myFile.writeBuffer(true);
//   system("PAUSE");
//   myFile.bufferAddition(" Does this work? ...");//This doesn't work...
//   system("PAUSE");
//   myFile.bufferLines(" Done buffering!");
//   system("PAUSE");
//   myFile.writeBuffer();

//
//   
//   cout<<"Is this bad?"<<vectorSize<<endl;
//   std::sort (testAnswers.begin(), testAnswers.end());
//   system("PAUSE");
//   int numMult=0; unsigned int currentNumFound = testAnswers[0];
//   for (int i=0; i<20;i++){
//      cout<<testAnswers[i]<<endl;
//   }
//   
//   for(int i=0; i<vectorSize;i++){
//           cout<<i<<endl;
//      while(true){
//         if (i==(vectorSize-1)){
//            cout<<"The END!"<<endl;
//            break;
//         }
//         
//         if (currentNumFound!=testAnswers[i]){
//            i--;
//            currentNumFound = testAnswers[i+1];
//            if (numMult>2){
//               cout<<"There are "<<numMult<<" of the number "
//               <<testAnswers[i+1]<<endl;
//            }
//            numMult = 0;
//            break;
//         }
//         numMult++;
//         i++;
//         cout<<i<<" "<<numMult<<" "<<testAnswers[i]<<endl;
//         //system("PAUSE");
//      }
//   }
//   




