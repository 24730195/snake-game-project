#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
using namespace std;

class Snake {
public:
    struct Point {
        int x, y;
    } Body[100];
    
    int Length;
    
    Snake() {
        Length = 3;
        Body[0].x = 10; Body[0].y = 10;
        Body[1].x = 11; Body[1].y = 10;
        Body[2].x = 12; Body[2].y = 10;
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

int main() {
    Snake snake;
    int Direction = 0;
    char key;

    while (1) {
        if (kbhit()) {
            key = getch();
            if (key == 'a') Direction = 2;
            if (key == 'w') Direction = 3;
            if (key == 'd') Direction = 0;
            if (key == 'x') Direction = 1;
        }
        system("cls");
        snake.Move(Direction);
        Sleep(300);
    }

    return 0;
}
