
#include "Encrypt.h"




//int randInt = rand() % 262144;//65536 (16*16*16*16*4)4*2^4^4, or 2^18
int myRand (int i) { return std::rand()%(i);}

int Encryter::keygenChars(char* charSpace, char* scrambledCipher, char* antiCipherChars, bool *cipherType) //For creating new rotors, reflectors and things
{
   //I think I'll split them into 5 pieces. alphabet, upperAlphabet, numbers, important characters, and extras
   char alphabet[26];
   char upperAlphabet[26];
   char importantChars[NUM_IMPORTANT_CHARS]={'.', ',', '!', ' ', '?', 'a'};
   char numbers[10];
   // : = 58, " = 34, \ = 92, / = 47
   char otherChars[NUM_OTHER_CHARS]={'@', '#', '$', '%', '^', '&', '*', '(', ')', ';', 'a', 'b', 'c', 'd', '~', '<', '>', '-', '_', '=', '+', '{', '}'};     
   
   //bool cipherType[5];
   
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
   
   for(int i=0; i<vectorCounter; i++){charSpace[i]=cipherCharSpace[i];}
   cout<<endl;
   cout<<"stuff"<<endl;

   for(int i=0; i<vectorCounter; i++){scrambledCipher[i]=cipherScrambled[i];}
   
   for(int i=0; i<vectorCounter; i++){antiCipherChars[i]=antiCipher[i];}
   //for( std::vector<char>::const_iterator i = cipherScrambled.begin(); i != cipherScrambled.end(); i++){ std::cout << *i;}
   //cout<<endl;
   //for( std::vector<char>::const_iterator i = antiCipher.begin(); i != antiCipher.end(); i++){ std::cout << *i;}
   //cout<<endl<<endl;


//system("PAUSE");
return vectorCounter;
}

//A more useful cipher, that a computer can actually use.
//cipherNum is the number of ciphers which should be made. The char mapping will only be made once though.
//Then char map is basically a salt, preventing brute force guessing.
//The keyname is a name, and does not need to have a file extension. The function will add one.
int Encryter::keygenInts(bool* cipherType, int numCiphers, char* keyName)
{
    
//bool cipherType[5];
int vectorCounter=0;
   
   //testing
   for (int q=0; q<5; q++){cipherType[q]=true;};
    
   std::vector<int> cipherIntSpace;
   std::vector<int> cipherScrambled;
   std::vector<int> antiCipherInts;
   

if (cipherType[0]==true){
   for (int i='a'-'a';i<'z'-'a'+1;i++){
      cipherIntSpace.push_back(vectorCounter);
      vectorCounter++;
   }
}
//cout<<endl;
if (cipherType[1]==true){
   for (int i='A'-'A';i<'Z'-'A' + 1;i++){
      cipherIntSpace.push_back(vectorCounter);
      vectorCounter++;
   }
}
//cout<<endl;
if (cipherType[2]==true){
   for (int i=0;i<NUM_IMPORTANT_CHARS;i++){
      cipherIntSpace.push_back(vectorCounter);
      vectorCounter++;
   }
}
//cout<<endl;

if (cipherType[3]==true){
   for (int i='0'-'0';i<'9'-'0' + 1;i++){
      cipherIntSpace.push_back(vectorCounter);
      vectorCounter++;
   }
}

if (cipherType[4]==true){
   for (int i=0;i<NUM_OTHER_CHARS;i++){
      cipherIntSpace.push_back(vectorCounter);
      vectorCounter++;
   }
}
    
char cipherSalt[vectorCounter];
char antiCipherSalt[vectorCounter];
char charSpace[vectorCounter];//All the characters possible in the cipher.
int temp;

std::string fileName = "Data/";
fileName += keyName;
FileIO outputFileCipher;
FileIO outputFileAntiCipher;
outputFileCipher.textOpenFile(fileName, true);
outputFileAntiCipher.textOpenFile(fileName, true);

//creating ciphers
   for (int i=0;i<numCiphers;i++){
          
      int check = keygenChars(charSpace, cipherSalt, antiCipherSalt, cipherType);
      if (check!=vectorCounter){/*What happened?*/};
          
      cipherScrambled = cipherIntSpace;
      
      std::random_shuffle ( cipherScrambled.begin(), cipherScrambled.end() );
      std::random_shuffle ( cipherScrambled.begin(), cipherScrambled.end() , myRand);
      
      antiCipherInts.resize(vectorCounter,0);
      //Makes the vector a size of vectorCounter, and fills it with 0s.
      
      for (int j=0;j<vectorCounter;j++){  
         temp = cipherScrambled[j];
         antiCipherInts[temp]=j;
      }
          
          
   }

    
}

unsigned int Encryter::hashString( const string &key) {
   long long hashVal = 0;
   
   int arrayLargePrimes[13]={978857489, 694846171, 961990429, 
   982451581, 674506409, 963287929, 674511707, 677404667, 685269437, 
   685263743, 967395713, 690473681, 693809153};
   
   int arrayMediumPrimes[14]={16859341, 16904803, 17096459, 18347759, 25047901, 
   28977719, 30798371, 32452837, 15480901, 
   15466951, 13380331, 7643873, 4172041, 15482917};
      
   int arraySmallPrimes[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 
   29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
   
   int primeCounter = (key[0]*arrayMediumPrimes[key[0]%14])%26;
   
   for(int i = 0; i<key.length();  i++){
     hashVal = ((arraySmallPrimes[primeCounter]*hashVal)%TWO_P_THIRTY_ONE_PRIME)
     +key[i];
      if (primeCounter>=25){
         primeCounter = 0;
         continue;
      }
      primeCounter++;
   }
   hashVal = hashVal * (arrayLargePrimes[arraySmallPrimes[primeCounter%26]]
    - arrayLargePrimes[arraySmallPrimes[(primeCounter+1)%26]]);

   if(hashVal<0){
     hashVal = hashVal*(-1);// += tableSize;
   }
   return (hashVal%TWO_P_THIRTY_ONE_PRIME);
 }



//http://www.cse.yorku.ca/~oz/hash.html
//Knuth's Sorting and Searching
std::string Encryter::passwordToHashInt(std::string password)
{
   std::string empty;
   empty += '0';
   if (password.length()<5){return empty;}//Passwords must be a minimum length.
   if (password.length()>63){return empty;}//Passwords cannot be too large;
   unsigned int key = hashString(password);
   std::string hashInts;
   int passwordLength = password.length();
   int twicePassLength = passwordLength*2;
   srand ((unsigned int)key);
   for (int i=0; i<twicePassLength;i++){
      hashInts+=std::rand()%256;//Return to 256 later
   }

//   srand ((unsigned int)key);
//   for (int i=0; i<twicePassLength;i++){
//      hashInts+=std::rand()%(256);
//   }
return hashInts;    
}











