


#include "pixelPainter.h"



#define PI 3.1415


using namespace std;

//I've got no idea...

//http://stackoverflow.com/questions/12378642/c-pixels-in-console-window

HBITMAP CreateDIBSection(
 HDC hdc,         // handle to DC
 CONST BITMAPINFO *pbmi, // bitmap data
 UINT iUsage,       // data type indicator
 VOID **ppvBits,     // bit values
 HANDLE hSection,     // handle to file mapping object
 DWORD dwOffset      // offset to bitmap bit values
);


int pixelPaint() 
{
   AllocConsole();
   FreeConsole();
   DWORD consoleThing;
   char name[62];
   
   int thingy = GetConsoleTitle(name, 62);
   HBITMAP hBitmap;
   BITMAPINFO* m_Bit;
   CBitmap m_OffscreenBitmap, *m_pOldBitmap;
   FIBITMAP* m_dib;
   
   //ATOM aso;
   //Get a console handle
   HWND myConsole;// = GetConsoleWindow();
   myConsole = FindWindow(NULL, name);
   //Get a handle to device context
   HDC mydc = GetDC(myConsole);
   
   CreateDIBSection(mydc, m_Bit, DIB_RGB_COLORS, (void**)&m_pBits, NULL, 0)
   m_OffscreenBitmap.Attach(hBitmap);
   m_pOldBitmap = m_dcOffscreen.SelectObject(&m_OffscreenBitmap);
   //hBitmap=(HBITMAP) LoadImage(NULL, _T("c:\\Temp\\Temp.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
   
   int pixel =0;

   //Choose any color
   COLORREF COLOR = RGB(255,255,255); 

   //Draw pixels
   for(double i = 0; i < PI * 4; i += 0.05)
   {
      SetPixel(mydc,pixel,12,COLOR);
      pixel+=1;
   }

   ReleaseDC(myConsole, mydc);
   cin.ignore();
   return 0;
}
   
   
   
   
   
   
   
   
   
   
   
