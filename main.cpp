#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
using namespace std;



int main()
{
    CONRAN r;
    int Huong = 0;
    char t;

    while (1)
    {
        if (kbhit())
        {
            t = getch();
            if (t=='a') Huong = 2;
            if (t=='w') Huong = 3;
            if (t=='d') Huong = 0;
            if (t=='x') Huong = 1;
        }
        system("cls");
        r.Draw();
        r.DiChuyen(Huong);
        Sleep(1000);
    }

    return 0;
}