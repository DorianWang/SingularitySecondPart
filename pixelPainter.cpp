

#include <windows.h>
#include "windows.h"
#include "stdio.h"
#include <iostream>
#include <cmath>

#include <iostream>

#define ENABLE_INSERT_MODE 0x0020
#define ENABLE_EXTENDED_FLAGS 0x0080

using namespace std;

//I've got no idea...


int pixelPaint() 
{
    AllocConsole();
    FreeConsole();
    //Get a console handle
    HWND myConsole = GetConsoleWindow();
    //Get a handle to device context
    HDC mydc = GetDC(myConsole);

    int pixel =0;

    //Choose any color
    COLORREF COLOR= RGB(255,255,255); 

    //Draw pixels
    //for(double i = 0; i < PI * 4; i += 0.05)
    //{
        //SetPixel(mydc,pixel,(int)(50+25*cos(i)),COLOR);
        //pixel+=1;
    //}

    ReleaseDC(myConsole, mydc);
    cin.ignore();
    return 0;
}
