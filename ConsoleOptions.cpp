

#include "ConsoleOptions.h"


int ConsoleOptions::setConsoleSize(unsigned int width, unsigned int height)
{

   SMALL_RECT r;
   COORD      c;
   CONSOLE_SCREEN_BUFFER_INFO csbi;
   HANDLE hConOut = GetStdHandle( STD_OUTPUT_HANDLE );
   if (!GetConsoleScreenBufferInfo( hConOut, &csbi )){
      throw runtime_error( "You must be attached to a human." );
   }

   r.Left   = 0;
   r.Top    = 0;
   r.Right  = width -1;
   r.Bottom = height -1;
   SetConsoleWindowInfo( hConOut, TRUE, &r );

   c.X = width;
   c.Y = height;
   SetConsoleScreenBufferSize( hConOut, c );


}


int ConsoleOptions::test()
{


GetConsoleTitle(output, 64);
cout<<output<<endl;
SetConsoleTitle("New Test!");




/*
  ~console()
    {
    SetConsoleTextAttribute(    hConOut,        csbi.wAttributes );
    SetConsoleScreenBufferSize( hConOut,        csbi.dwSize      );
    SetConsoleWindowInfo(       hConOut, TRUE, &csbi.srWindow    );
    }

*/


   COORD maxSize = GetLargestConsoleWindowSize(hConOut);
   cout<<maxSize.X << " " <<maxSize.Y<<endl;



//http://msdn.microsoft.com/en-us/library/windows/desktop/ms682073(v=vs.85).aspx
//http://www.cplusplus.com/forum/windows/10731/
}



//Graphics!
//http://lazyfoo.net/SDL_tutorials/lesson01/index.php
//http://lazyfoo.net/tutorials/OpenGL/index.php
