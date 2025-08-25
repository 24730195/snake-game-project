#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
using namespace std;

// Kích thước khung
const int MIN_WIDTH = 10;
const int MAX_WIDTH = 95;
const int MIN_HEIGHT = 1;
const int MAX_HEIGHT = 25;

// Khai báo hàm
void gotoxy(int x, int y);
void DrawFrame();

int main() {
    // Dựng trò chơi
    // ---Cài đặt---
    DrawFrame();

    return 0;
}

// Hàm di chuyển con trỏ in ra màn hình console
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Hàm vẽ khung
void DrawFrame() {
    for (int x = MIN_WIDTH; x <= MAX_WIDTH; x++) {
        gotoxy(x, MIN_HEIGHT);
        cout << "#";   // cạnh trên
        gotoxy(x, MAX_HEIGHT);
        cout << "#";   // cạnh dưới 
    }
    
    for (int y = MIN_HEIGHT; y <= MAX_HEIGHT; y++) {
        gotoxy(MIN_WIDTH, y);
        cout << "#";   // cạnh trái
        gotoxy(MAX_WIDTH, y);
        cout << "#";   // cạnh phải
    }
}
