

std::string parseFirstToken(std::string input, const char* delim)
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
