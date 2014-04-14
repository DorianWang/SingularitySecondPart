
#include "Encrypt.h"

int Encryter::keygen() //For creating new rotors and things
{
   //I think I'll split them into 5 pieces. alphabet, upperAlphabet, numbers, important characters, and extras
   char alphabet[26];
   char upperAlphabet[26];
   char numbers[10];
   // : = 54, " = 34, \ = 92
   char otherChars[]={' ', '.', ',', ';', 'a', '/', 'c', 'b', '~', '<', '>'};
   //How many? 
   //Chars I want: All ten shift+number, ".,;:/\|"'-_+=", " ", a newLine character which I'll have as "~" and a tab as "<"
   
   //http://www.asciitable.com/
   
   for (int i='a'-'a';i<'z'-'a'+1;i++){
      alphabet[i]='a' + i;
      cout<<alphabet[i];
   }
cout<<endl;
 
   for (int i='A'-'A';i<'Z'-'A' + 1;i++){
      upperAlphabet[i]='A' + i;
      cout<<upperAlphabet[i];
   }
cout<<endl;

for (int i='0'-'0';i<'9'-'0' + 1;i++){
      numbers[i]='0' + i;
      cout<<numbers[i];
   }
cout<<endl;

cout<<'!'+1;




system("PAUSE");
return 1;
}







