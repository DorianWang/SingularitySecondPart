
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
   bool newFile=false;
   
   while (true){
      fileName = getFileName();
      system("CLS");
      cout<<"I will now try to open the file \""<<fileName<<"\"."<<endl;
      cout<<"Is this right? Enter Y to continue, Q to quit, and anything else to try again."<<endl;
      cout<<"If the file does not exist, please press C instead."<<endl;
      cin>>input;
      if (input=="Y"||input=="y"){
         break;
      }
      if (input=="C"||input=="c"){
         newFile=true;
         break;
      }
      if (input=="Q"||input=="q"){
         return 0;
      }
   }
   
   //fileName = getFileName();
   if (newFile){
      myfile.open(filePath.c_str(), ios::out);//creates the file
      myfile.close();
      myfile.open(filePath.c_str(), ios::out | ios::in);
      isBinary=false;
      fileLength=0;
      return 1;
   }
   
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
   bool newFile=false;
   
   while (true){
      fileName = getFileName();
      system("CLS");
      cout<<"I will now try to open the file \""<<fileName<<"\"."<<endl;
      cout<<"Is this right? Enter Y to continue, Q to quit, and anything else to try again."<<endl;
      cout<<"If the file does not exist, please press C instead."<<endl;
      cin>>input;
      if (input=="Y"||input=="y"){
         break;
      }
      if (input=="C"||input=="c"){
         newFile=true;
         break;
      }
      if (input=="Q"||input=="q"){
         return 0;
      }
      
   }
   
   if (newFile){
      myfile.open(filePath.c_str(), ios::out | ios::binary);//creates the file
      myfile.close();
      myfile.open(filePath.c_str(), ios::out | ios::in | ios::binary);
      isBinary=true;
      fileLength=0;
      return 1;
   }
   
   myfile.open(filePath.c_str(), ios::out | ios::in | ios::binary);
   isBinary=true;
   
   myfile.seekg (0, myfile.end);
   fileLength = myfile.tellg();
   myfile.seekg (0, myfile.beg);
   
   return 1;
}

//For dataType, 
//0 for int, 1 for char, 2 for float, 3 for double, 4 for short, 5 for long long. More may be added later.

//numWanted is the length of the array. (note, a pointer to a single thing is still treated like an array)
//returns 0 for failure, else 1
int FileIO::readData(int dataType, int arrayLength, ...)
{
   //int *asdf;
   char buffer[32];
   void * output;
   int bytesToGet=4;
   
   if (dataType>=5||dataType<=-1){
      return 0;
   }
   
   bytesToGet = 1;
   
   if (dataType==1){ bytesToGet = 1;}
   
   if (dataType==3||dataType==5){ bytesToGet = 8;}
   
   if (dataType==4){ bytesToGet = 2;}
   
   va_list ap;
   //va_start(ap, numWanted);

   output = va_arg(ap, void *);
   
   if (output==NULL) return 0;
   
   //read bytes, chance to fail...
   myfile.read(buffer, bytesToGet);
   if (myfile.eof()&&myfile.fail()) return 0; //hit end of file...
   switch
   //http://www.dreamincode.net/forums/topic/47339-writing-floats-to-a-file/
   //in.read((char *)&f2,sizeof(float));
   //*((int *)output) = qwer;
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


int FileIO::writeData(int dataType, int arrayLength, ...)
{
   //int 
//two floats
//out.write((char *)&f1,sizeof(float));



}

int FileIO::writeData(char* data)
{
    
    
    
    
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











