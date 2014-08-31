
#include "MapLoader.h"

int mapLoader::readMapFile(std::string mapName, mapType* map)
{
   FileIO mapFile;
   mapFile.dataOpenFile(MAP_FOLDER + mapName, false);
   //Who is responsible for the file extension?
   
   int numLocationsFound = -1;
   int errorType = 0;
   mapFile.readData(INT_SIZE, 1, &errorType, &numLocationsFound);
   
   if (numLocationsFound >= 0 && errorType < 0){
      return 0;//Bad stuff happened!
   }
   
   for (int i=0; i < numLocationsFound; i++){
      readLocations(&mapFile, map);
   }
   
}

int readLocations(FileIO* mapFile, mapType* map)
{
   int numFound = -1;
   int errorType = 0;
   
   mapFile.readData(INT_SIZE, 1, &errorType, &numFound);
   //Temporary
   
   
}
   
   
   
   
   
   
   
