#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
using namespace std;



int main()
{
    Snake snake;
    int Direction = 0;
    char t;

    while (1)
    {
        if (kbhit())
        {
            t = getch();
            if (t=='a') Direction = 2;
            if (t=='w') Direction = 3;
            if (t=='d') Direction = 0;
            if (t=='x') Direction = 1;
        }
        system("cls");
        snake.Draw();
        snake.Move(Direction);
        Sleep(1000);
    }

    return 0;
}