#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
using namespace std;


void Draw()
{
    for (int i = 0; i < DoDai; i++)
    {
        gotoxy(A[i].x,A[i].y);
        printf("%c%c",219,219);
    }
}


