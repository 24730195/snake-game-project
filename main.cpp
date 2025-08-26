#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
using namespace std;

struct Point {
    int x, y;
};

Point food;

// Hàm di chuyển con trỏ in ra màn hình console
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Hàm sinh mồi ngẫu nhiên
void generateFood() {
    food.x = rand() % (MAX_WIDTH - MIN_WIDTH - 1) + MIN_WIDTH + 1;
    food.y = rand() % (MAX_HEIGHT - MIN_HEIGHT - 1) + MIN_HEIGHT + 1;
}

// Hàm kiểm tra rắn ăn mồi
void eatFood(Snake &snake) {
    if (snake.Body[0].x == food.x && snake.Body[0].y == food.y) {
        snake.Length++;
        generateFood();
    }
}

// Hàm vẽ mồi
void drawFood() {
    gotoxy(food.x, food.y);
    cout << "o";
}

