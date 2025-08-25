#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
using namespace std;

//Hàm sinh mồi ngẫu nhiên
void generateFood() {
    food.x = rand() % (WIDTH - 2) + 1;  
    food.y = rand() % (HEIGHT - 2) + 1;  
}

//Kiểm tra rắn ăn mồi
void eatFood(Snake &snake) {
    if (snake.Body[0].x == food.x && snake.Body[0].y == food.y) {
        snake.Length++;     
        generateFood();
    }
}

//Hàm vẽ mồi
void drawFood() {
    gotoxy(food.x, food.y);
    cout << "o";
}

int main() {
    eatFood(snake);   // kiểm tra rắn ăn mồi
    drawFood();       // vẽ mồi
}
return 0;
}
