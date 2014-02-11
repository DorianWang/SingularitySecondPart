
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
     






