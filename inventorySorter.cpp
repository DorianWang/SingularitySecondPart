
#include "ItemDeclaration.h"

//http://en.wikipedia.org/wiki/Variadic_function
//^This will be used in here, maybe...


//http://stackoverflow.com/questions/5386834/c-get-base-class-object-from-derived-class-pointer
//I'll test this later, as it has a low chance of working the way I want...
//The first item will be the one earlier in the sorted list.
int sortByBaseName(itemBaseType one, itemBaseType two)
{


   int compareValue = one.singularName.compare(two.singularName);

   if ((compareValue == -1) || (compareValue == 0)){
      return 0; //No switch, the two strings are good where they are.
   }
   return 1; //Switch required
   //{
   /*
   std::string StringOne = "AAA";
   std::string StringTwo = "BBB";

   cout<<StringOne.compare(StringTwo)<<endl;
   This returns -1.
   */
   //}
};

int sortByBaseSize(itemBaseType one, itemBaseType two)
{

   if (one.size <= two.size){
      return 0; //No switch, the two strings are good where they are.
   }
   return 1; //Switch required

};




/*
int sortEquipment ((std::vector <equipmentType*>)* inputArray, const char sortType)
{
   int asdf = inputArray -> size();
    for (int j = 0; j < asdf; j++){
            //TODO
            //http://www.algolist.net/Algorithms/Sorting/Quicksort
    }


}


*/



