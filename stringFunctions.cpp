
#include "stringFunctions.h"


std::string stringFunc::parseFirstToken(std::string input, const char* delim)
{
   std::string output; int inputLength = input.length();
   int delimLength = strlen(delim);
   for (int i=0; i<inputLength; i++){
      for (int j=0; j<delimLength; j++){
         if (input.at(i) == delim[j]){
            return output;   
         }
      }
      output += input.at(i);
   }
   return output;
}

std::string stringFunc::popFirstToken(std::string input, const char* delim)
{
   std::string output; int inputLength = input.length();
   std::string temp = parseFirstToken(input, delim);
   
   if (temp == input){ return NULL; }
   
   input.erase(0, temp.length());
   output = input;
   return output;
}


std::vector <std::string> stringFunc::parseAllTokens(std::string input, const char* delim)
{
   std::vector <std::string> tempVector;
   //tempVector.push_back();
}



