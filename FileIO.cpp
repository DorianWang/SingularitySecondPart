


void getProfile(std::string name)
{

ifstream myfile;
myfile.open ("saves/"+name+".txt");
 	
if (myfile.is_open()) {

   cout<<"yey!";

}

}

void makeProfile(std::string name)
{

ofstream myfile;     
myfile.open("saves/"+name+".txt");     
     
if (myfile.is_open()){
                      
   cout<<"yey!";                   
   myfile << "Writing this to a file.\n";                        
}     
     
     
}
