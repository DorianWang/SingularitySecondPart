
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
fstream myfile;//input and output
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

//opening files
int textOpenFile();
int dataOpenFile();

//reading data
int readLine(std::string *output);
int readIntData(int *output);
int readData(int output, ...);

//moving the read/write
int returnStart(int isRead);
int goEnd(int isRead);

std::string getFileName(bool isBinary);
int deleteFile(std::string *fileName);

int closeFile(); void closeFile(bool asdf);

};

#endif







