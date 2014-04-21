
#include "FileIO.h"

FileIO::FileIO()
{
   isOpen=false;   
};
                 
FileIO::~FileIO()
{
   myfile.close();    
};

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


bool writeDwarf()
{
   int asdf;  

}

std::string FileIO::getFileName()
{
   char badChars[]={'/', '1', '0', '*', '?', '0', '<', '>', '|'}; 
   stringstream ss;
   badChars[1]=92; badChars[2]=54; badChars[5]=34;
   //54 = :, 34 = "
   std::string fileName; std::string input;
   int inputLength;
   bool charGood = false;
   int i;int j;
   
   while (true){
      system("CLS");
      cout<<"Please type in the name of the file. It should be located in the Data folder."<<endl;
      cout<<"If it does not currently exist, it will be created."<<endl;
      getline(cin, input);//Includes spaces - http://cboard.cprogramming.com/cplusplus-programming/122401-how-do-i-allow-spaces-cin.html
      //cin>>input;
      inputLength = input.length();
       
      if (inputLength<=0||inputLength>=255){                                
         cout<<"The string is not the correct length."<<endl;
         system("PAUSE");
         continue;
      }
      break;
   }
   
   //i=0; 
   j=0;
   while(true){//for (int i=0; i<inputLength;i++){
      charGood = true;
                     
      for (int k=0;k<9;k++){
         if (input.at(j)==badChars[k]){
            charGood=false;
         }
      }
      if (charGood){
         ss << input.at(j);//fileName.at(i) = input.at(j);
         //i++;
      }
      j++;
      charGood = false;
   }
   fileName = ss.str();
   ss.str(std::string());//clears the stringstream
   
   if (fileName.at(inputLength-1)=='.'){
      fileName.erase(inputLength - 1);
   }
   ss<<"/Data/"<<fileName;
   filePath = ss.str();
   
return fileName;
}

int FileIO::deleteFile(std::string *fileName)
{

   if( remove( (*fileName).c_str() ) != 0 ){
      perror( "Error deleting file" );
   }
   else
   {
      cout<<"File successfully deleted"<<endl;
   }
   return 1;
}

int FileIO::textOpenFile()
{
   std::string fileName;
   std::string input;
   
   while (true){
      fileName = getFileName();
      system("CLS");
      cout<<"I will now try to open the file \""<<fileName<<"\"."<<endl;
      cout<<"Is this right? Enter Y to continue, Q to quit, and anything else to try again."<<endl;
      cin>>input;
      if (input=="Y"||input=="y"){
         break;
      }
      if (input=="Q"||input=="q"){
         return 0;
      }
   }
   
   //fileName = getFileName();
   
   myfile.open(filePath.c_str(), ios::out | ios::in);
   if (myfile.is_open()){
      isBinary=false;
      return 1;
   }
}

//http://courses.cs.vt.edu/cs2604/fall02/binio.html
//Binary files
int FileIO::dataOpenFile()
{
   std::string fileName;// = getFileName();
   std::string input;
   
   while (true){
      fileName = getFileName();
      system("CLS");
      cout<<"I will now try to open the file \""<<fileName<<"\"."<<endl;
      cout<<"Is this right? Enter Y to continue, Q to quit, and anything else to try again."<<endl;
      cin>>input;
      if (input=="Y"||input=="y"){
         break;
      }
      if (input=="Q"||input=="q"){
         return 0;
      }
      
   }
   
   
   myfile.open(filePath.c_str(), ios::out | ios::in | ios::binary);
   isBinary=true;
   
   myfile.seekg (0, myfile.end);
   fileLength = myfile.tellg();
   myfile.seekg (0, myfile.beg);
   
   return 1;
}

//For outputType, 
//0 for int, 1 for char, 2 for float, 3 for double, 4 for short. More may be added later.

//numWanted is the length of the array. (note, a pointer to a single thing is still treated like an array)
//returns 0 for failure, else 1
int FileIO::readData(int outputType, int arrayLength, ...)
{
   //int *asdf;
   char buffer[32];
   void * output;
   int bytesToGet=4;
   
   if (outputType>=5||outputType<=-1){
      return 0;
   }
   
   bytesToGet = 1;
   
   if (outputType==1){ bytesToGet = 1;}
   
   if (outputType==3){ bytesToGet = 8;}
   
   if (outputType==4){ bytesToGet = 2;}
   
   va_list ap;
   //va_start(ap, numWanted);

   output = va_arg(ap, void *);
   
   if (output==NULL) return 0;
   
   //read bytes, chance to fail...
   myfile.read(buffer, 4);
   int qwer;
   
   *((int *)output) = qwer;
   return 1;
    
}//Unfinished


int FileIO::readLine(std::string *output)
{
   if (myfile.good()){
      return 0;
   }
   
   std::string input;
   
   getline( myfile, input );
   *output = input;
   return 1;
}



//When isRead is 1 or higher, moves the get position. If it is 0, moves the put pointer. Else, returns 0.
int FileIO::goStart(int isRead)
{
   myfile.clear();
   if (isRead > 0){
      myfile.seekg(0, ios::beg);
      return 1;
   }
   if (isRead == 0){
      myfile.seekp(0, ios::beg);   
      return 1;
   }
   
   return 0;
}

int FileIO::goEnd(int isRead)
{
   myfile.clear();
   if (isRead > 0){
      myfile.seekg(0, ios::end);
      return 1;
   }
   if (isRead == 0){
      myfile.seekp(0, ios::end);   
      return 1;
   }
   
   return 0;
}

int FileIO::goPos(int isRead, int position)
{

   if (position<0||position>fileLength){
      return 0;   
   }
   
   if (isRead > 0){
      myfile.seekg(0, ios_base::beg);
      myfile.seekg(position); 
      return 1;
   }
   if (isRead == 0){
      myfile.seekp(0, ios_base::beg);
      myfile.seekp(position);   
      return 1;
   }
   
   return 0;
    
    
}

int FileIO::closeFile()
{
   if (isOpen){
      myfile.close(); 
      isOpen = false; 
      return 1;
   }  
   return 0;
   
}

void FileIO::closeFile(bool asdf)
{
   myfile.close(); 
}











