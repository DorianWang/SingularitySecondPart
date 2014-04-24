
#include "Encrypt.h"


//int randInt = rand() % 262144;//65536 (16*16*16*16*4)4*2^4^4, or 2^18
int myRand (int i) { return std::rand()%(i);}

int Encryter::keygenChars(char* charSpace, char* scrambledCipher, char* antiCipherChars) //For creating new rotors, reflectors and things
{
   //I think I'll split them into 5 pieces. alphabet, upperAlphabet, numbers, important characters, and extras
   char alphabet[26];
   char upperAlphabet[26];
   char importantChars[NUM_IMPORTANT_CHARS]={'.', ',', '!', ' ', '?', 'a'};
   char numbers[10];
   // : = 58, " = 34, \ = 92, / = 47
   char otherChars[NUM_OTHER_CHARS]={'@', '#', '$', '%', '^', '&', '*', '(', ')', ';', 'a', 'b', 'c', 'd', '~', '<', '>', '-', '_', '=', '+', '{', '}'};     
   
   bool cipherType[5];
   
   //testing
   for (int q=0; q<5; q++){cipherType[q]=true;};
   
   std::vector<char> cipherCharSpace;
   std::vector<char> cipherScrambled;

   //Special chars that are annoying.
   importantChars[5] = 34; 
   otherChars[11] = 47; otherChars[12] = 58; otherChars[13] = 92;
   
   //How many? 
   //newLine character which I'll have as "{" and a tab as "}", backspace as "~"
   
   //http://www.asciitable.com/
   
   int vectorCounter = 0;

if (cipherType[0]==true){
   for (int i='a'-'a';i<'z'-'a'+1;i++){
      alphabet[i]='a' + i;
      cout<<alphabet[i];
      cipherCharSpace.push_back(alphabet[i]);
      vectorCounter++;
   }
}
//cout<<endl;
if (cipherType[1]==true){
   for (int i='A'-'A';i<'Z'-'A' + 1;i++){
      upperAlphabet[i]='A' + i;
      cout<<upperAlphabet[i];
      cipherCharSpace.push_back(upperAlphabet[i]);
      vectorCounter++;
   }
}
//cout<<endl;
if (cipherType[2]==true){
   for (int i=0;i<NUM_IMPORTANT_CHARS;i++){
      //importantChars[i]='0' + i;
      cout<<importantChars[i];
      cipherCharSpace.push_back(importantChars[i]);
      vectorCounter++;
   }
}
//cout<<endl;

if (cipherType[3]==true){
   for (int i='0'-'0';i<'9'-'0' + 1;i++){
      numbers[i]='0' + i;
      cout<<numbers[i];
      cipherCharSpace.push_back(numbers[i]);
      vectorCounter++;
   }
}

if (cipherType[4]==true){
   for (int i=0;i<NUM_OTHER_CHARS;i++){
      //otherChars[i]='0' + i;
      cout<<otherChars[i];
      cipherCharSpace.push_back(otherChars[i]);
      vectorCounter++;
   }
}

   //add rotor complexity selection here.
   //How about antirotors, for decryption?

   srand ( time(NULL) );
   //65536
   
   //for (int i=0; i<10; ++i) cipherCharSpace.push_back(i); // 1 2 3 4 5 6 7 8 9
   cipherScrambled = cipherCharSpace;
   //randomization.
   
   for (int i=0;i<vectorCounter;i++){
      cout<< cipherCharSpace[i];   
   }
   cout<<endl;
   
   std::random_shuffle ( cipherScrambled.begin(), cipherScrambled.end() );
   std::random_shuffle ( cipherScrambled.begin(), cipherScrambled.end() , myRand);
   //Used to cause segfaults...
   
   
   std::vector<char> antiCipher (vectorCounter); int temp = 0;
   system("PAUSE");
   for (int j = 0; j<vectorCounter; j++){
      for (int k=0; k<vectorCounter; k++){
         if (cipherScrambled[j]==cipherCharSpace[k]){
            temp = k;
            break;
         } 
      }   
      
      antiCipher[temp] = cipherCharSpace[j];
   }
   /* Print path vector to console 
   copy(path.begin(), path.end(), ostream_iterator<char>(cout, " "));
   */
   
   for (int i=0;i<vectorCounter;i++){
      cout<< cipherCharSpace[i];   
   }
   cout<<endl;
   
   for( std::vector<char>::const_iterator i = cipherCharSpace.begin(); i != cipherCharSpace.end(); i++){ std::cout << *i;}
   cout<<endl;
   cout<<"stuff"<<endl;
   for( std::vector<char>::const_iterator i = cipherScrambled.begin(); i != cipherScrambled.end(); i++){ std::cout << *i;}
   cout<<endl;
   for( std::vector<char>::const_iterator i = antiCipher.begin(); i != antiCipher.end(); i++){ std::cout << *i;}
   cout<<endl<<endl;


system("PAUSE");
return vectorCounter;
}



int Encryter::keygenInts(bool* cipherType)//A more useful cipher, that a computer can actually use.
{
    
//bool cipherType[5];
int vectorCounter=0;
   
   //testing
   for (int q=0; q<5; q++){cipherType[q]=true;};
    
   std::vector<int> cipherIntSpace;
   std::vector<int> cipherScrambled;


if (cipherType[0]==true){
   for (int i='a'-'a';i<'z'-'a'+1;i++){
      cipherCharSpace.push_back(vectorCounter);
      vectorCounter++;
   }
}
//cout<<endl;
if (cipherType[1]==true){
   for (int i='A'-'A';i<'Z'-'A' + 1;i++){
      upperAlphabet[i]='A' + i;
      cout<<upperAlphabet[i];
      cipherCharSpace.push_back(upperAlphabet[i]);
      vectorCounter++;
   }
}
//cout<<endl;
if (cipherType[2]==true){
   for (int i=0;i<NUM_IMPORTANT_CHARS;i++){
      //importantChars[i]='0' + i;
      cout<<importantChars[i];
      cipherCharSpace.push_back(importantChars[i]);
      vectorCounter++;
   }
}
//cout<<endl;

if (cipherType[3]==true){
   for (int i='0'-'0';i<'9'-'0' + 1;i++){
      numbers[i]='0' + i;
      cout<<numbers[i];
      cipherCharSpace.push_back(numbers[i]);
      vectorCounter++;
   }
}

if (cipherType[4]==true){
   for (int i=0;i<NUM_OTHER_CHARS;i++){
      //otherChars[i]='0' + i;
      cout<<otherChars[i];
      cipherCharSpace.push_back(otherChars[i]);
      vectorCounter++;
   }
}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}













