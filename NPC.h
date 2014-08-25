
#ifndef NPC_H
#define NPC_H

class basicChar
{
   std::string nameShown;
   int lowLvlLmt;
   int highLvlLmt;
   short damageEffectChange;
   float damageEffectMod;
   
   bool isUnique; //Tells the game to look at this differently
   std::string pathToUniqueEffects;
   
   int valueIncrease; 
   float valueMod;
};









#endif
