#ifndef ITEMDECLARATION_H
#define ITEMDECLARATION_H


//User defined folding points
//This one contains header files
//{
#include "iostream"
#include "string"
#include "vector"
//}

enum usesEquip {
EQUIP_HAND, EQUIP_CHEST, EQUIP_HEAD, EQUIP_ARM, EQUIP_LEG, EQUIP_FOOT, EQUIP_NECK,
EQUIP_SYMMETRY, EQUIP_EDGE, STAB, CRUSH, MAGIC_BOOST, MANA_BOOST, STAFF_BOOST,
SHIELD, BOW, CROSSBOW, DART_GUN, DART_BLOW, GUN,
LEVER, TOOL_NO_TECH, TOOL_TECH, TOOL_UNIQUE, KEY
};


enum usesConsume {
POTION_HEAL, BANDAGE, OTHER_MEDICAL, FOOD, POTION_MANA, ELEMENT_CLUSTER, POWER_ELEMENT_CLUSTER,
CRYSTAL_MANA, EXPLODE_DISABLE, EXPLODE_DAMAGE, EXPLODE_FLARE, TRANSFORM_MAGIC, TRANSFORM_TECH,

};


struct descriptorEffects
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





class itemBaseType
{
   std::string singularName;
   std::string pluralName;
   std::string descriptor;

   short size;
   short weight;

   int value;

   bool isUnique; //Tells the game to look at this differently
   std::string uniqueEffectsKey;
};




class equipmentTypeBase : itemBaseType
{
   std::vector <descriptorEffects> descriptor;


   int baseDamage; //Note that damage can be negative...
   float damageIncrItemLvl;
   float damageIncrUserLvl;
   unsigned char assocSkill;
   short enchantType; //Mostly for staffs, but also for some other things

   std::string primaryItemType;
   std::string secondaryItemTypes;
   std::vector <unsigned char> uses;
   std::vector <unsigned char> materials;

};

class consumeTypeBase : itemBaseType
{

   int effectStrength;
   float effectIncrItemLvl;
   float effectIncrUserLvl;//For healing items, etc.
   unsigned char assocSkill;

   std::string primaryItemType;
   std::string secondaryItemTypes;
   std::vector <unsigned char> uses;

};




class equipmentType : itemBaseType
{

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


   equipmentTypeBase* itemBase;

};

class consumeType : itemBaseType
{

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

};

class junkType : itemBaseType
{

   std::string primaryItemType;
   std::string secondaryItemTypes;
   std::vector <unsigned char> uses;

};

class keyItemType : itemBaseType
{
   std::string primaryItemType;
   std::string secondaryItemTypes;
   std::vector <unsigned char> uses;

   unsigned short tag;
};



class inventory
{
public:
   int carryingCapacityWeight;
   int carryingCapacitySize;

   unsigned char currentlySortedAs;

   inventory();
   ~inventory();

   int showInventory();//The return will be changed later...
   void sortInventory(char sortType);

   bool addItem(int itemType, ...); //Change int into an enum?
   bool removeItem(int itemType, std::string itemName);

   int isOverloaded();//Returns 0 for no, 1 for slightly, 2 for quite a bit, and 3 for crushing weight (basically can't move).

   int changeCarryWeight();
   int changeCarrySize();
   int testItem(int weight, int size);//This will return the overloaded int if the item used is added.

private:

   int currentStorageWeight;
   int currentStorageSpace;

   std::vector <equipmentType*> equipment;

   std::vector <equipmentType*> currentlyEquiped;

   std::vector <consumeType> consumables;

   std::vector <junkType> shinyThings;

   std::vector <keyItemType> keyItems;

};





#endif // ITEMDECLARATION_H
