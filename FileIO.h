
#ifndef FILEIO_H
#define FILEIO_H 

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class FileIO
{

public:
//Variables
ofstream myfile;//input and output
std::string filePath;

//Functions
std::string getFileName();

bool getProfile(std::string name);
bool makeProfile(std::string name);
bool writeDwarf();

int dataFile();
std::string getFileName(bool isBinary);
int deleteFile(std::string *fileName);



};

#endif
