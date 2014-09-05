#ifndef ITEMS_H
#define ITEMS_H 

#include "FileIO.h"
#include "treeType.h"

enum usesEquip {
EQUIP_HAND, EQUIP_CHEST, EQUIP_HEAD, EQUIP_ARM, EQUIP_LEG, EQUIP_FOOT, EQUIP_NECK, 
EQUIP_SYMMETRY, EQUIP_EDGE, STAB, CRUSH, MAGIC_BOOST, MANA_BOOST, STAFF_BOOST, 
SHIELD, BOW, CROSSBOW, DART_GUN, DART_BLOW, GUN, 
LEVER, TOOL_NO_TECH, TOOL_TECH, TOOL_UNIQUE, KEY
};


enum usesConsume {
POTION_HEAL, BANDAGE, OTHER_MEDICAL, FOOD, POTION_MANA, ELEMENT_CLUSTER, POWER_ELEMENT_CLUSTER,
CRYSTAL_MANA, EXPLODE_DISABLE, EXPLODE_DAMAGE, EXPLODE_FLARE, 
};


typedef struct descriptorEffects
{
   std::string descriptorName;
   int lowLvlLmt;
   int highLvlLmt;
   short damageEffectChange;
   float damageEffectMod;
   
   bool isUnique; //Tells the game to look at this differently
   std::string pathToUniqueEffects;
   
   int valueIncrease; 
   float valueMod;
};


typedef struct equipmentTypeBase
{
   std::string singularName;
   std::string pluralName;
   std::vector <descriptorEffects> descriptor;
   
   short size;
   short weight;
   int baseDamage; //Note that damage can be negative...
   float damageIncrItemLvl;
   float damageIncrUserLvl;
   unsigned char assocSkill; 
   short enchantType; //Mostly for staffs, but also for some other things
   
   std::string primaryItemType;
   std::string secondaryItemTypes;
   std::vector <unsigned char> uses;
   std::vector <unsigned char> materials;
   
   bool isUnique; //Tells the game to look at this differently
   std::string pathToUniqueEffects;
   
   int value;
};

typedef struct consumeTypeBase
{
   std::string singularName;
   std::string pluralName;
   short size;
   short weight;
   int effectStrength;
   float effectIncrItemLvl;
   float effectIncrUserLvl;//For healing items, etc.
   unsigned char assocSkill;
   
   std::string primaryItemType;
   std::string secondaryItemTypes;
   std::vector <unsigned char> uses;
   
   bool isUnique; //Tells the game to look at this differently
   std::string pathToUniqueEffects;
   
   int value;
};



typedef struct equipmentType
{
   std::string singularName;
   std::string pluralName;
   std::string descriptor;
   
   short size;
   short weight;
   int baseDamage; //Note that damage can be negative...
   float damageIncrItemLvl;
   float damageIncrUserLvl;
   unsigned char assocSkill; 
   short enchantType; //Mostly for staffs, but also for some other things
   
   std::string primaryItemType;
   std::string secondaryItemTypes;
   std::vector <unsigned char> uses;
   std::vector <unsigned char> materials;
   
   int itemLevel;
   
   bool isUnique; //Tells the game to look at this differently
   std::string pathToUniqueEffects;
   
   equipmentTypeBase* itemBase;

   int value;
};

typedef struct consumeType
{
   std::string singularName;
   std::string pluralName;
   short size;
   short weight;
   int effectStrength;
   float effectIncrItemLvl;
   float effectIncrUserLvl;//For healing items, etc.
   unsigned char assocSkill;
   
   int itemLevel;
   
   std::string primaryItemType;
   std::string secondaryItemTypes;
   std::vector <unsigned char> uses;
   
   bool isUnique; //Tells the game to look at this differently
   std::string pathToUniqueEffects;
   
   equipmentTypeBase* consumeTypeBase;
   
   int value;
};

typedef struct junkType
{
   std::string singularName;
   std::string pluralName;
   short size;
   short weight;
   
   std::string primaryItemType;
   std::string secondaryItemTypes;
   std::vector <unsigned char> uses;
   
   int value;
};




typedef struct inventory
{
   int carryingCapacity;
   std::vector <equipmentType> equipment;
   
   std::vector <int> currentlyEquiped;
   
   std::vector <consumeType> consumables;
   
   std::vector <junkType> shinyThings;
   
};




class itemSet
{

//Tree implementation
//equipmentType
//consumeType
//junkType
public:





};






#endif














