
#include "FileIO.h"

bool getProfile(std::string name)
{

ifstream myfile;
std::string fileName;
fileName= "saves/"+name+".dat";
myfile.open (fileName.c_str());
 	
if (myfile.is_open()) {

   cout<<"yey!";

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

std::string FileIO::getFileName(bool isBinary)
{
   char badChars[]={'/', '1', '0', '*', '?', '0', '<', '>', '|'}; 
   badChars[1]=92; badChars[2]=54; badChars[5]=34;
   //54 = :, 34 = "
   std::string fileName; std::string input;
   int inputLength;
   while (true){
      system("CLS");
      cout<<"Please type in the name of the file."<<endl;
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
   
   
   for (int i=0; i<inputLength;i++){
      for (int j=0;j<9;j++){
         if (input.at(i)==badChars[j]){
                          
         }
      }
   }
   
   if (input.at(inputLength-1)=='.'){
      input.erase(inputLength - 1);
   }
   
   //myfile.open("example.bin", ios::out | ios::in);
   //myfile.open("example.bin", ios::out | ios::in | ios::binary);
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
 
int textFile()
{
    
    
}

int dataFile()
{
    
}













