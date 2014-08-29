
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

};







#endif
