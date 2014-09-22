#include "ItemDeclaration.h"




inventory::inventory()
{
   carryingCapacityWeight = 0;
   carryingCapacitySize = 0;

   isOverloaded = 0;

   currentlySortedAs = 0;//Unsorted

   currentStorageWeight = 0;
   currentStorageSpace = 0;
}

inventory::~inventory()
{
   for (int i = 0; i < equipment.size(); i++){
      delete (equipment[i]);
   }
   equipment.clear();
   currentlyEquiped.clear();
   consumables.clear();
   shinyThings.clear();
   keyItems.clear();
}








int inventory::isOverloaded()
{
   int halfWeightCap = carryingCapacityWeight/2; int halfSizeCap = carryingCapacitySize/2;

   if (currentStorageWeight - 1 > carryingCapacityWeight * 2)
   ||(currentStorageSpace - 1 > carryingCapacitySize * 2){
      return 3;//Completely overloaded
   }

   if (currentStorageWeight - 1 > carryingCapacityWeight + halfWeightCap)
   ||(currentStorageSpace - 1 > carryingCapacitySize + halfSizeCap){
      return 2;//Overloaded
   }

   if (currentStorageWeight - 1 > carryingCapacityWeight)
   ||(currentStorageSpace - 1 > carryingCapacitySize){
      return 1;//Slightly overloaded
   }


return 0;//Not overloaded
}
















