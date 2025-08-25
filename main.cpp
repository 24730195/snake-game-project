#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
using namespace std;


void Draw (SNAKE snake)
{
    int i;
    for (i = 0; i < snake.Leng; i++)
    {
        gotoxy(snake.A[i].x*2, snake.A[i].y);
        printf("%c%c",219,219);
        Sleep(1000);
    }
    gotoxy(snake.A[i].x*2, snake.A[i].y);
    printf(" ");
    gotoxy(40,20);
    printf("\n");
}