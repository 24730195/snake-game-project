#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
using namespace std;

// Kích thước khung
const int MIN_WIDTH = 10;
const int MAX_WIDTH = 80;
const int MIN_HEIGHT = 5;
const int MAX_HEIGHT = 30;

enum Direction { RIGHT, LEFT, UP, DOWN };

struct Point {
    int x, y;
};

// Khai báo hàm
void gotoxy(int x, int y);
void textColor(int color);
void showCur(bool CursorVisibility);
void DrawFrame();

class Food {
public:
    Point currentFood;

    Food() { 
        init(); 
    }

    // Hàm khởi tạo vị trí đầu tiên của mồi
    void init() {
        currentFood = {20, 10};
    }

    //Hàm sinh mồi ngẫu nhiên
    void generateFood() {
        currentFood.x = rand() % (MAX_WIDTH - MIN_WIDTH - 1) + MIN_WIDTH + 1;
        currentFood.y = rand() % (MAX_HEIGHT - MIN_HEIGHT - 1) + MIN_HEIGHT + 1;
    }

    //Hàm vẽ mồi
    void drawFood() {
        gotoxy(currentFood.x, currentFood.y);
        textColor(124);
        printf("%c", 15);
    }
};

class Snake {
public:
    Point Body[500];
    int Length;
    Direction dir;

    Snake() {
        init();
    }

    //Hàm khởi tạo vị trí đầu tiên của rắn
    void init() {
        Length = 3;
        dir = RIGHT;
        Body[0] = {15, 8};
        Body[1] = {15, 8};
        Body[2] = {15, 8};
    }

    //Hàm vẽ rắn
    void Draw()
    {
        textColor(113);
        gotoxy(Body[0].x, Body[0].y); printf("%c", 2);
        for (int i = 1; i < Length; i++) {
            gotoxy(Body[i].x, Body[i].y); printf("%c", 1);
        }
    }

    //Hàm di chuyển
    void Move() {
        for (int i = Length; i > 0; i--) Body[i] = Body[i - 1];
        if (kbhit()) {
            char key = getch();
            switch (key)
            {
                case 'a':
                    dir = LEFT; break;
                case 'd':
                    dir = RIGHT; break;
                case 'w':
                    dir = UP; break;
                case 's':
                    dir = DOWN; break;
                default:
                    break;
            }
        }
        switch (dir) {
            case LEFT: Body[0].x--; break;
            case RIGHT: Body[0].x++; break;
            case DOWN: Body[0].y++; break;
            case UP: Body[0].y--; break;
        }
    }

    // Hàm kiểm tra rắn ăn mồi
    void eatFood(Food &food) {
        if (Body[0].x == food.currentFood.x && Body[0].y == food.currentFood.y) {
            Length++;
            food.generateFood();
        }
    }
};

bool checkCollision(const Snake &snake);
void backSpace(const Snake &snake);

int main() {
    // Khởi tạo trò chơi
    showCur(0);
    system("cls");
    DrawFrame();
    // Hình nền
    // Cài đặt trò chơi
    // Chơi game
    Snake snake;
    Food food;
    int gameOver = 0;

    while (!gameOver) {
        snake.Draw();
        food.drawFood();
        backSpace(snake);
        snake.Move();
        snake.eatFood(food);
        // Kiểm tra va chạm
        if (checkCollision(snake)) {
            gameOver = 1;
            gotoxy(35, 15); textColor(12); printf("GAME OVER!");
        }
        Sleep(200);
        gotoxy(0, 0);
    }
    // Kết thúc trò chơi và hiển thị điểm
    _getch();
    gotoxy(0, 0);
    showCur(1);
    return 0;
}


// Hàm di chuyển con trỏ in ra màn hình console
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Hàm đổi màu chữ
void textColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Làm ẩn con trỏ
void showCur(bool CursorVisibility)
{ 
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor = { 10, CursorVisibility };
    SetConsoleCursorInfo(handle, &cursor);
}


// Hàm vẽ khung
void DrawFrame() {
    textColor(11);
    for (int i = MIN_WIDTH; i < MAX_WIDTH; i++) {
        gotoxy(i, MIN_HEIGHT); printf("%c", 205);
        gotoxy(i, MAX_HEIGHT); printf("%c", 205);
    }
    for (int i = MIN_HEIGHT; i <= MAX_HEIGHT; i++) {
        gotoxy(MIN_WIDTH, i); printf("%c", 186);
        gotoxy(MAX_WIDTH - 1, i); printf("%c", 186);
    }
    gotoxy(MIN_WIDTH, MIN_HEIGHT); printf("%c", 201);
    gotoxy(MIN_WIDTH, MAX_HEIGHT); printf("%c", 200);
    gotoxy(MAX_WIDTH - 1, MIN_HEIGHT); printf("%c", 187);
    gotoxy(MAX_WIDTH - 1, MAX_HEIGHT); printf("%c", 188);
    textColor(15);
    gotoxy(39, 5); printf(" SNAKE GAME ");
}

bool checkCollision(const Snake &snake) {
    int x = snake.Body[0].x, y = snake.Body[0].y;
    if (x <= MIN_WIDTH || x >= MAX_WIDTH - 1 || y <= MIN_HEIGHT || y >= MAX_HEIGHT) return true;
    for (int i = 1; i < snake.Length; i++)
        if (x == snake.Body[i].x && y == snake.Body[i].y) return true;
    return false;
}

void backSpace(const Snake &snake) {
    gotoxy(snake.Body[snake.Length].x, snake.Body[snake.Length].y);
    textColor(0);
    printf(" ");
}
