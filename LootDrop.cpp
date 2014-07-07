
#define NORMAL_LOOT_CHANCE 80
#define HIGHER_LOOT_CHANCE 18
#define HIGHEST_LOOT_CHANCE 2


//These limit players, and creatures armour, clothing and other choices.
//These refer to the size vs "average" (human size). A large knife is smaller
//than a normal sword, for example.
enum itemSize { TINY, SMALL, NORMAL, LARGE, GIGANTIC };

//Humanoid (duh), Serpentine (only snakes), Shapeless (Anyone, think cloaks or magic)
//Exotic (Unique, unable to use)
enum itemShape { HUMANOID, SERPENTINE, SHAPELESS, EXOTIC };

//Shield does crushing damage, 
enum itemType { EDGE_WEAPON, CRUSH_WEAPON, STAB_WEAPON, SPECIAL_WEAPON, SHIELD, 
RANGED_BOW, RANGED_DART, RANGED_LARGE_PROJECTILE, RANGED_EXOTIC, //Ranged weapon with strange uses
MAGIC_TOOL, HEALING, MAGIC_HEAL, RESTORE_HEAL, ARMOUR_CLOTHES, ARMOUR_SPECIAL, 
ARMOUR_MAGIC, ARMOUR_ROBES, ARMOUR_LEATHER,ARMOUR_METAL_CHAIN, 
ARMOUR_METAL_SOLID, ARMOUR_LIVING, QUEST, LOOT, CRAFTING};


enum itemEnchants { ELEMENT_ICE, ELEMENT_FIRE, ELEMENT_LIGHTNING, ELEMENT_LIGHT,
ELEMENT_DARK, ELEMENT_LIFE, ELEMENT_NECRO, ELEMENT_WATER, ELEMENT_AIR, ELEMENT_ARCANE,
ELEMENT_POISON, ELEMENT_MIND , ELEMENT_TECH, ELEMENT_MUNDANE };//The last three aren't really enchants, but...

//Items can be 

//Item hierarchy
/*
All Items (Root)
Equipment
   Weapons (mostly physical)
      Edge
         Sword (slash), knife (slash), axe, ;
      Crushing
         Hammer, bat, mace, axe (partial), ;
      Stabbing
         Pickaxe, knife (stab), spear, sword (stab), ;
      Special
         Gauntlet (crushing, may have stabbing), ;
   Magic Weapons (wands, staffs, etc.)
      Magic tools
         Wand, staff, magic glove, magic crystal, ;
      Magic enhancers
         Ward, thaumometer (temp name), ;
   Shields
      Wood, metal (Weapon metals), ;
   Ranged
      Bow
         Long
            Wood, metal (Weapon materials), ;
         Short
            Wood, metal (Weapon materials), ;
         Cross
            Wood, metal (Weapon materials), ;
         Arrow (ammo)
            Arrow (shaft (wood, metal), head (metal, bone, flint)) ;
            Bolt (wood, metal) ;
      Dart
      
      
Consumables


Loot







Metals in West Aterha:
   Weapon materials: Copper, Bronze, Iron, Steel (low and high), traelmin ;
   Craft materials: Copper, Tin, Brass, Silver, Electrum (used for some spells, purity), Gold ;
   Other "metals" that may be used: thaumium (iron + magic, stronger than low steel), 
   adamantium (very light, strong metal, very valuable), ;
Other materials used:
   Weapon materials: wood, stone, bone, flint, ;
   Craft materials: wood, stone, bone, glass, clay, 
*/














