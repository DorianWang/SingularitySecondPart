#include "Encrypt.h"


int Encryter::charToCipherInt(bool* cipherType, char input)
{
   char importantChars[NUM_IMPORTANT_CHARS]={'.', ',', '!', ' ', '?', 'a'};
   // : = 58, " = 34, \ = 92, / = 47
   char otherChars[NUM_OTHER_CHARS]={'@', '#', '$', '%', '^', '&', '*', '(', ')', ';', 'a', 'b', 'c', 'd', '~', '<', '>', '-', '_', '=', '+', '{', '}'};     
   importantChars[5] = 34; 
   otherChars[11] = 47; otherChars[12] = 58; otherChars[13] = 92;
   
   int typeCounter = 0;
   if (cipherType[0]){
      if(input>='a'&&input<='z'){
         return input - 'a' + typeCounter;
      }
      typeCounter = typeCounter + NUM_LETTERS;
   }
   
   if (cipherType[1]){
      if(input>='A'&&input<='Z'){
         return input - 'A' + typeCounter;
      }
      typeCounter = typeCounter + NUM_LETTERS;
   }
   
   if (cipherType[2]){
      for (int i=0; i<NUM_IMPORTANT_CHARS; i++){
         if(input==otherChars[i]){
            return i + typeCounter;
         }
      }
      typeCounter = typeCounter + NUM_IMPORTANT_CHARS;
   }

   if (cipherType[3]){
      if(input<='9'&&input>='0'){
         return input - '0' + typeCounter;
      }
      typeCounter = typeCounter + NUM_NUMBERS;
   }
   
   if (cipherType[4]){
      for (int i=0; i<NUM_OTHER_CHARS; i++){
         if(input==otherChars[i]){
            return i + typeCounter;
         }
      }
      //typeCounter = typeCounter + NUM_OTHER_CHARS;
      //Not needed...
   }
    
return -1; //not in cipher
}


char cipherIntToChar(bool* cipherType, int input)
{

   char importantChars[NUM_IMPORTANT_CHARS]={'.', ',', '!', ' ', '?', 'a'};
   // : = 58, " = 34, \ = 92, / = 47
   char otherChars[NUM_OTHER_CHARS]={'@', '#', '$', '%', '^', '&', '*', '(', ')', ';', 'a', 'b', 'c', 'd', '~', '<', '>', '-', '_', '=', '+', '{', '}'};     
   importantChars[5] = 34; 
   otherChars[11] = 47; otherChars[12] = 58; otherChars[13] = 92;
   
   int typeCounter = 0; int temp = 0;
   if (cipherType[0]){
      temp = input - NUM_LETTERS;
      if(temp>=0&&temp<NUM_LETTERS){
         return input + 'a';// + typeCounter;
      }
      typeCounter = typeCounter + NUM_LETTERS;
   }
   
   if (cipherType[1]){
      temp = input - NUM_LETTERS;
      if(input>='A'&&input<='Z'){
         return input - 'A' + typeCounter;
      }
      typeCounter = typeCounter + NUM_LETTERS;
   }
   
   if (cipherType[2]){
      for (int i=0; i<NUM_IMPORTANT_CHARS; i++){
         if(input==otherChars[i]){
            return i + typeCounter;
         }
      }
      typeCounter = typeCounter + NUM_IMPORTANT_CHARS;
   }

   if (cipherType[3]){
      if(input<='9'&&input>='0'){
         return input - '0' + typeCounter;
      }
      typeCounter = typeCounter + NUM_NUMBERS;
   }
   
   if (cipherType[4]){
      for (int i=0; i<NUM_OTHER_CHARS; i++){
         if(input==otherChars[i]){
            return i + typeCounter;
         }
      }
      //typeCounter = typeCounter + NUM_OTHER_CHARS;
      //Not needed...
   }
    
return -1; //not in cipher
     
     

}
     
     



