
#ifndef ENCRYPT_H
#define ENCRYPT_H 

#define NUM_IMPORTANT_CHARS 6
#define NUM_OTHER_CHARS 23
#define NUM_LETTERS 26
#define NUM_NUMBERS 10

#define TWO_P_FOUR 0x10
#define TWO_P_SIXTEEN 0x10000
#define TWO_P_TWENTYFOUR 0x1000000
#define TWO_P_THIRTY 0x40000000
#define TWO_P_SIXTY 0x1000000000000000LL
#define TWO_P_THIRTY_ONE_PRIME 0x7FFFFFFFLL  //2^31 - 1 = 2147483647

#define NUM_PRIMES 8

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <ctime>      
#include <cstdlib>      // std::rand, std::srand  

#include "FileIO.h"

using namespace std;

typedef struct rotor{
   int setNum;//Different rotors in different sets
   int numChars;//number of characters on the rotor
   //std::string mapping;//gives the mapping rules. For example the map DBCA means ADCB -> DACB
   
   int currentNum;//Where the "Front" of the rotor should be.
};

typedef struct intRotor{
   std::vector<int> mapping;
   int currentNum;//What the rotor has been set to.        
   bool rotorType[5];//Type of rotor.
   int rotorLength;
};

class Encrypter
{

public:

Encrypter();
char importantChars[NUM_IMPORTANT_CHARS];//={'.', ',', '!', ' ', '?', 'a'};
   // : = 58, " = 34, \ = 92, / = 47
char otherChars[NUM_OTHER_CHARS];//={'@', '#', '$', '%', '^', '&', '*', '(', ')', ';', 'a', 'b', 'c', 'd', '~', '<', '>', '-', '_', '=', '+', '{', '}'};     
   //importantChars[5] = 34; 
   //otherChars[11] = 47; otherChars[12] = 58; otherChars[13] = 92;

int charToCipherInt(bool* cipherType, char input);
char cipherIntToChar(bool* cipherType, int input);

int keygenChars(char* charSpace, char* scrambledCipher, char* antiCipher, bool *cipherType);
int keygenInts(bool* cipherType, int numCiphers, std::string keyName);
unsigned int passwordToHashInt(std::string password);
unsigned int hashString( const string &key);
std::vector <int> createCharSpace(bool* cipherType);
std::vector <int> keygenIntsCharMap(unsigned int passwordHash, bool* cipherType, bool cipherToReturn);
int createAllCiphers(bool* cipherType, int numCiphers, char* keyName, char* folderName, int totalNumCiphers);

int getCiphersFromFile(intRotor* rotors, bool* cipherType, FileIO* myFile, int maxRotors);

bool iterateRotor(intRotor* rotor);

char cipherChar(char input, intRotor* rotors, int numRotors);
std::string encryptString(intRotor* rotors, int numRotors, std::string input);
std::vector <std::string> decryptFile(FileIO* myFile, unsigned int hashPass);

private:
//Primes: 59233, 49157, 32647, 99083, 158003, 779347, 2141, 8501 


};

#endif

//Enigma machine like cipher, not really too secure...

//http://codereview.stackexchange.com/questions/44196/enigma-simulator-performance
//http://www.dreamincode.net/forums/topic/233977-enigma-machine-rotors/
//http://en.wikipedia.org/wiki/Typex

//Can I add more ciphers? Fewer?




