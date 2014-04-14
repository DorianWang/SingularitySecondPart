
#ifndef FILEIO_H
#define FILEIO_H 

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

class FileIO
{

public:
//Variables
ofstream myfile;//input and output
std::string filePath;
bool isBinary;
bool isOpen;

//Functions
FileIO();
~FileIO();

std::string getFileName();
int returnStart();

bool getProfile(std::string name);
bool makeProfile(std::string name);
bool writeDwarf();

int textOpenFile();
int dataOpenFile();

int readLine(std::string *output);

std::string getFileName(bool isBinary);
int deleteFile(std::string *fileName);



};

#endif
