
#ifndef MAP_H
#define MAP_H

#include "Locations.h"

typedef struct locationWithExtras
{
   advancedLocation* locationPointer;
   std::vector <short> effects;
};


class mapType
{

int numLocations;
std::vector <advancedLocation*> locations;
//Array of all locations;

std::vector <advancedLocation*> 





};


#endif
