
#include "Encrypt.h"

int Encryter::keygen() //For creating new rotors, reflectors and things
{
   //I think I'll split them into 5 pieces. alphabet, upperAlphabet, numbers, important characters, and extras
   char alphabet[26];
   char upperAlphabet[26];
   char importantChars[6]={'.', ',', '!', ' ', '?', 'a'};
   char numbers[10];
   // : = 58, " = 34, \ = 92, / = 47
   char otherChars[23]={'@', '#', '$', '%', '^', '&', '*', '(', ')', ';', 'a', 'b', 'c', 'd', '~', '<', '>', '-', '_', '=', '+', '{', '}'};     
   
   //Special chars that are annoying.
   importantChars[5] = 34; 
   otherChars[11] = 47; otherChars[12] = 58; otherChars[13] = 92;
   
   //How many? 
   //newLine character which I'll have as "{" and a tab as "}", backspace as "~"
   
   //http://www.asciitable.com/
   
   int vectorCounter = 0;

if (){
   for (int i='a'-'a';i<'z'-'a'+1;i++){
      alphabet[i]='a' + i;
      cout<<alphabet[i];
      myvector.push_back(alphabet[i]);
      vectorCounter++;
   }
}
//cout<<endl;
 
   for (int i='A'-'A';i<'Z'-'A' + 1;i++){
      upperAlphabet[i]='A' + i;
      cout<<upperAlphabet[i];
      myvector.push_back(upperAlphabet[i]);
      vectorCounter++;
   }
//cout<<endl;

for (int i='0'-'0';i<'9'-'0' + 1;i++){
      numbers[i]='0' + i;
      cout<<numbers[i];
      myvector.push_back(numbers[i]);
      vectorCounter++;
   }
//cout<<endl;






for (int i=0;i<25;i++){

      cout<<otherChars[i];
   }
cout<<endl;

//add rotor complexity selection here.
//How about antirotors, for decryption?
for (int i=0; i<10; ++i) myvector.push_back(i); // 1 2 3 4 5 6 7 8 9
std::random_shuffle ( myvector.begin(), myvector.end() );

//add randomization here.


system("PAUSE");
return 1;
}







