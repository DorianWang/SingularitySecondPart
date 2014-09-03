
#ifndef EFFECTS_MAP_H
#define EFFECTS_MAP_H


enum allEffects
{
   MOD_HP, MOD_MP, MOD_UN_ONE, MOD_UN_TWO, MOD_INT, MOD_WIS, MOD_CHA, MOD_STR, 
   MOD_AGL, MOD_END, MOD_UN_THREE, MOD_UN_FOUR, MOD_MGC_KNL, MOD_TCH_KNL, 
   MOD_BASE_MGC_RST, MOD_BASE_PHYS_RST, 
   
   
   
   
   
   
   KILL_PLAYER, KILL_ENEMY, 
};

typedef struct mapEffectsAdvanced
{
   mapEffects effect;
   int effectStrength;
   int descriptionIndex;
};















#endif
