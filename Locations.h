
#ifndef LOCATION_H
#define LOCATION_H

class basicLocation
{

public:
   std::string nameShown;
   std::string description;
   
   unsigned short type; //This is what the land is.
   
};

class advancedLocation : public basicLocation
{
   
public:
   unsigned char numConnections;
   advancedLocation* connections[10];
   //0 is north, 1 is west, .. 3 is east, 4 is up, 5 is down, 6 is NE, 9 is SE, etc.
   //If there is nothing in that direction, NULL will be found.

   std::vector <advancedInteractive> objects;
   
   std::vector <advancedChar> characters;
   
   unsigned short tag;//This allows on enter/exit effects;
}



#endif
