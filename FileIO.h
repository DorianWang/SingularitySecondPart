
#ifndef FILEIO_H
#define FILEIO_H 

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdarg>
#include <cstdlib>
#include <vector>

#include "typeChanger.h"

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
bool dataInLineBuffer;

//Functions
FileIO();
~FileIO();

std::string getFileName();
int returnStart();

bool getProfile(std::string name);
bool makeProfile(std::string name);
bool writeDwarf();

//opening files
int createFile();

int textOpenFile();
int textOpenFile(std::string fileName, bool isFirstTime);
int dataOpenFile();
int dataOpenFile(std::string filePath, bool isFirstTime);

//reading data
int readLine(std::string *output);
int readIntData(int *output);
int readData(int dataType, int arrayLength, ...);

//moving the read/write
int goStart(int isRead);
int goEnd(int isRead);
int goPos(int isRead, int position);

//Writing data
int writeDataToFile(char* data, int length);
int writeLine(std::string output);
int writeStringText(std::string output);
int writeData(int dataLength, int arrayLength, ...);

//Other stuff
std::string getFileName(bool isBinary);
int deleteFile(std::string *fileName);

//Data buffer stuff, to allow for storage in the object. More convienient.
void bufferLines(std::string input);
void bufferAddition(std::string input);
void writeBuffer();
void writeBuffer(bool clearData);
void clearBuffer();
int clearBuffer(int line);

int closeFile(); void closeFile(bool asdf);

;
private:

int lineCounter;
int dataCounter;
vector <std::string> lineBuffer;
vector <char> dataBuffer;
        

};

#endif







