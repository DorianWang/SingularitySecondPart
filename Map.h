
#ifndef MAP_H
#define MAP_H

#include "Locations.h"

typedef struct locationWithExtras
{
   advancedLocation* locationPointer;
   std::vector <int> effects;//Temporary
};


class mapType
{

int numLocations;
std::vector <locationWithExtras*> locations;
//Array of all locations;

//std::vector <locationWithExtras*> effectLocations





};


#endif
