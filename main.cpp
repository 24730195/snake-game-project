#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
using namespace std;

struct Point {
    int x, y;
};

class Snake {
public:

    Point Body[100];
    int Length;

    Snake() {
        Length = 3;
        Body[0].x = 10; Body[0].y = 10;
        Body[1].x = 11; Body[1].y = 10;
        Body[2].x = 12; Body[2].y = 10;
    }
    
    void Draw()
    {
        for (int i = 0; i < DoDai; i++)
        {
            gotoxy(A[i].x,A[i].y);
            printf("%c%c",219,219);
        }
    }

    void Move(int Direction) {
        for (int i = Length - 1; i > 0; i--)
            Body[i] = Body[i - 1];
        if (Direction == 0) Body[0].x = Body[0].x + 1; // right
        if (Direction == 1) Body[0].y = Body[0].y + 1; // down
        if (Direction == 2) Body[0].x = Body[0].x - 1; // left
        if (Direction == 3) Body[0].y = Body[0].y - 1; // up
    }
};

// Hàm di chuyển con trỏ in ra màn hình console
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}





