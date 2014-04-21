
#ifndef FILEIO_H
#define FILEIO_H 

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdarg>

using namespace std;

class FileIO
{

public:
//Variables
fstream myfile;//input and output
std::string filePath;
bool isBinary;
bool isOpen;
int fileLength;

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

//http://stackoverflow.com/questions/1579719/variable-number-of-parameters-in-function-in-c
int readData(int dataType, int arrayLength, ...);

//moving the read/write
int goStart(int isRead);
int goEnd(int isRead);
int goPos(int isRead, int position);

int writeData(char* data);
int writeData(int dataType, int arrayLength, ...);

std::string getFileName(bool isBinary);
int deleteFile(std::string *fileName);

int closeFile(); void closeFile(bool asdf);

};

#endif







