
#ifndef NPC_H
#define NPC_H

class basicChar
{
public:
   std::string nameShown;
   std::string species;
   
   std::string description;
   
   unsigned char tag;
};

class advancedChar : public basicChar
{
public:

   int temporaryVariable;
   int faction; //Who is this? Who do they belong to?

};

class enemyChar : public advancedChar
{

public:
   bool isHostile;//If it is not hostile, it will not attack first.
   //equipmentContainer equipItems;
   

}





#endif





