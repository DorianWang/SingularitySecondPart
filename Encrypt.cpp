
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

//http://www.cse.yorku.ca/~oz/hash.html
//Knuth's Sorting and Searching
unsigned int Encryter::passwordToInt(std::string password)
{
   int arrayPrimes[NUM_PRIMES] = {59233, 49157, 32647, 
   99083, 158003, 779347, 2141, 8501};
   
   if (password.length()<5){return 0;}//Passwords must be a minimum length.
   
   int primesSelected[4];
   unsigned int AllCharsMult = 1;
   unsigned int AllCharAdded = 0;
   
   for (int i=0;i<password.length(); i++){
      AllCharsMult = (AllCharsMult * password.at(i)) % TWO_P_THIRTY + 1;
      AllCharAdded += (AllCharAdded + password.at(i)) % TWO_P_THIRTY + 1;
   }
   
   for (int i=0; i<4;i++){
      primesSelected[i] = arrayPrimes[(AllCharsMult * i * (password.at(0)-20)) % (AllCharAdded % NUM_PRIMES+1)];
   }
   long long protoKey = AllCharsMult % TWO_P_SIXTEEN
    + AllCharsMult % TWO_P_THIRTY//(TWO_P_TWENTYFOUR * 64)//2^30
    //+ AllCharsMult % TWO_P_FOUR
    + AllCharsMult % primesSelected[1]//99083
    + AllCharsMult % primesSelected[2]//158003
    + (AllCharsMult * AllCharAdded * primesSelected[3]) % 
    (TWO_P_TWENTYFOUR * TWO_P_FOUR);
    + (AllCharsMult - AllCharAdded) % primesSelected[4]//2141
    //+ (AllCharsMult ^ AllCharAdded) % 2
   ;
   cout<<"!!!"<<endl;
   protoKey = (protoKey * (primesSelected[2]-primesSelected[1]));
   if (protoKey<TWO_P_THIRTY){//TWO_P_SIXTY){
      protoKey = protoKey * (protoKey % primesSelected[4]);
   }
   // protoKey = (protoKey * (primesSelected[3] - primesSelected[2]))%(TWO_P_THIRTY*TWO_P_THIRTY);
   cout<<"!!!"<<endl;
   unsigned int key = ((protoKey) % 
   (TWO_P_TWENTYFOUR * TWO_P_FOUR * TWO_P_FOUR - 1));

   srand ((unsigned int)key);
   for (int i=0; i<30;i++){
      cout<<std::rand()%(26)+65;
   }
   cout<<endl;
   srand ((unsigned int)key);
   for (int i=0; i<30;i++){
      cout<<std::rand()%(26)+65;
   }
   cout<<endl;  
         
         
}











