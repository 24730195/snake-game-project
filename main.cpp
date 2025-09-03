#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
using namespace std;

struct Point {
    int x, y;
};

// Kích thước khung
const int MIN_WIDTH = 10;
const int MAX_WIDTH = 95;
const int MIN_HEIGHT = 1;
const int MAX_HEIGHT = 25;

// Khai báo hàm
void gotoxy(int x, int y);
void DrawFrame();
void drawFood();
void generateFood();
void eatFood(class Snake &snake);
Point food;

//Khởi tạo class Snake
class Snake {
public:

    Point Body[100];
    int Length;

    Snake() {
        init();
    }

    //Hàm khởi tạo vị trí đầu tiên của rắn
    void init() {
        Length = 3;
        Body[0].x = 10; Body[0].y = 10;
        Body[1].x = 11; Body[1].y = 10;
        Body[2].x = 12; Body[2].y = 10;
    }

    //Hàm vẽ rắn
    void Draw()
    {
        for (int i = 0; i < Length; i++)
        {
            gotoxy(Body[i].x,Body[i].y);
            printf("%c",219);
        }
    }

    //Hàm di chuyển
    void Move(int Direction) {
        for (int i = Length - 1; i > 0; i--){
            Body[i] = Body[i - 1];
        }
        if (Direction == 0) Body[0].x = Body[0].x + 1; // right
        if (Direction == 1) Body[0].y = Body[0].y + 1; // down
        if (Direction == 2) Body[0].x = Body[0].x - 1; // left
        if (Direction == 3) Body[0].y = Body[0].y - 1; // up
    }
};


int main() {
    // Dựng trò chơi
    // ---Cài đặt---
    generateFood();
    DrawFrame();

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
        DrawFrame();
        drawFood();
        snake.Move(Direction);
        snake.Draw();
        eatFood(snake);
        Sleep(300);;
    }

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
