
#ifndef FILEIO_H
#define FILEIO_H 

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class FileIO
{

public:

bool getProfile(std::string name);
bool makeProfile(std::string name);
bool writeDwarf();







};

#endif
