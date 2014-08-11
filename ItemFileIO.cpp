
#include "Items.h"

typedef struct descriptorEffects
{
   std::string descriptorName;
   int lowLvlLmt;
   int highLvlLmt;
   short damageEffectChange;
   float damageEffectMod;
   
   bool isUnique; //Tells the game to look at this differently
   std::string pathToUniqueEffects;
}


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
}

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
}



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
}

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
}

typedef struct junkType
{
   std::string singularName;
   std::string pluralName;
   short size;
   short weight;
   
   std::string primaryItemType;
   std::string secondaryItemTypes;
   std::vector <unsigned char> uses;

/*
How do I plan to make the item files?

Things in () are comments and don't actaully exist in the file.

Nom:
Sword swords (singular, plural)

BSC: 
400 4 +6 0.2 0.1
(size, weight, base damage, damage increase per item level, 
damage increase per user [skill] level)

(primary item trait)
PRI:
equipment.weapon.edge.sword

(any secondary item traits)
SEC:
equipment.weapon.stab.sword
(There can be more...)


(Special things the item can do)

USE:
Weapon 3 (It is a weapon, with a threat rating of 3)
Slash/Edge(Which one?)
Stab
Lever
CanEnchant 4(Shorten to Enchant or even ECT, power of enchants)
(etc.)

(Materials it can be made from)

MAT: (The colon marks a new thing, and all tags are 3 characters)

ARWM (All regular weapon materials)
Silver +14
Iron +2 (override)

Types:

(Descriptor, low level bound, high level bound, affect of descriptor, 
Damage multiplier)

Broken 1 4 -2 *1
Flawed 2 8 -1 *1
- 3 12 0 (- means no descriptor) *1
Good 5 18 *1
(etc)


*/

























