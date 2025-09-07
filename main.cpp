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
        textColor(13);
        printf("*");
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
        textColor(12);
        gotoxy(Body[0].x, Body[0].y); printf("0");
        textColor(15);
        for (int i = 1; i < Length; i++) {
            gotoxy(Body[i].x, Body[i].y); printf("o");
        }
    }

    //Hàm di chuyển
    void Move() {
        // Xoá phần đuôi rắn thừa
        gotoxy(Body[Length].x, Body[Length].y);
        textColor(0);
        printf(" ");

        // Dịch chuyển thân rắn
        for (int i = Length; i > 0; i--) Body[i] = Body[i - 1];

        // Điều khiển hướng di chuyển
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

        // Cập nhật vị trí đầu rắn theo hướng di chuyển
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
void clearScreen();
void avatar();
void playGame();
void menu();

int main() {
    // Khởi tạo trò chơi
    showCur(0);
    system("cls");
    DrawFrame();
    // Hình nền
    avatar();
    // Cài đặt trò chơi
    menu();
    system("cls");
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

void clearScreen()
{
    for (int i = MIN_HEIGHT + 1; i < MAX_HEIGHT; i++)
        for (int j = MIN_WIDTH + 1; j < MAX_WIDTH - 1; j++) {
            gotoxy(j, i);
            textColor(0);
            printf(" ");
        }
}


void avatar()
{
    gotoxy(15, 11); textColor(10); printf("                _        ");
    gotoxy(15, 12); textColor(10); printf("                | |       ");
    gotoxy(15, 13); textColor(10); printf(" ___ _ __   __ _| | _____ ");
    gotoxy(15, 14); textColor(10); printf("/ __| '_ \\ / _` | |/ / _ \\");
    gotoxy(15, 15); textColor(10); printf("\\__ \\ | | | (_| |   <  __/");
    gotoxy(15, 16); textColor(10); printf("|___/_| |_|\\__,_|_|\\_\\___|");
    gotoxy(45, 8); textColor(10); printf(" ---_ ......._-_--.       ");
    gotoxy(45, 9); textColor(10); printf(" (|\\ /      / /| \\  \\     ");
    gotoxy(45, 10); textColor(10); printf(" /  /     .'  -=-'   `.   ");
    gotoxy(45, 11); textColor(10); printf(" /  /    .'             )  ");
    gotoxy(45, 12); textColor(10); printf(" _/  /   .'        _.)   / ");
    gotoxy(45, 13); textColor(10); printf(" / o   o        _.-' /  .' ");
    gotoxy(45, 14); textColor(10); printf(" \\          _.-'    / .'*|  ");
    gotoxy(45, 15); textColor(10); printf("  \\______.-'//    .'.' \\*|  ");
    gotoxy(45, 16); textColor(10); printf("   \\|  \\ | //   .'.' _ |*|  ");
    gotoxy(45, 17); textColor(10); printf("    `   \\|//  .'.'_ _ _|*|  ");
    gotoxy(45, 18); textColor(10); printf("     .  .// .'.' | _ _ \\*|  ");
    gotoxy(45, 19); textColor(10); printf("     \\`-|\\_/ /    \\ _ _ \\*\\ ");
    gotoxy(45, 20); textColor(10); printf("      `/'\\__/      \\ _ _ \\*\\ ");
    gotoxy(45, 21); textColor(10); printf("     /^|            \\ _ _ \\* ");
    gotoxy(45, 22); textColor(10); printf("    '  `             \\ _ _ \\ ");
    gotoxy(45, 23); textColor(10); printf("                      \\_      ");
    gotoxy(25, 25); textColor(15); printf("Press any key to go to the menu...");
    _getch();
    clearScreen();
    // Thời gian chuyển khung hình
    Sleep(500);
}

void playGame()
{
    clearScreen();
    Snake snake;
    Food food;
    int gameOver = 0;

    while (!gameOver) {
        snake.Draw();
        food.drawFood();
        snake.Move();
        snake.eatFood(food);
        // Kiểm tra va chạm
        if (checkCollision(snake)) {
            gameOver = 1;
            gotoxy(40, 17); textColor(12); printf("GAME OVER!");
        }
        Sleep(200);
    }
}

void menu()
{
    gotoxy(13, 7); textColor(10); printf("Use the w and s keys to move up and down, and Enter to select...");
    int choose = 0;
	int coodinate = 15;
    textColor(202);
    gotoxy(37, 15); printf("%c  PLAY GAME  ", 175);
    textColor(14);
    gotoxy(37, 16); printf("  HELP         ");
    gotoxy(37, 17); printf("  ABOUT        ");
    gotoxy(37, 18); printf("  HIGHT SCORE   ");
    gotoxy(37, 19); printf("  EXIT         ");
    textColor(0);
	do{
		char key = getch();
        switch (key)
        {
            case 's':
                choose = 1; break;
            case 'w':
                choose = 2; break;    
            case 13:
                choose = 3; break;
            default:
                choose = 0; break;
        }

		if(choose == 1 && coodinate < 19) coodinate++;
		if(choose == 2 && coodinate > 15) coodinate--;

		if(coodinate == 15)
		{
            switch (choose)
            {
                case 1:
                    break;
                case 2:
                    textColor(14);
                    gotoxy(37, 16); printf("  HELP         ");
                    textColor(202);
                    gotoxy(37, 15); printf("%c  PLAY GAME  ", 175);
                    break;    
                case 3:
                    playGame();
                    break;
                case 0:
                    break;
            }
		}

		if(coodinate == 16)
		{
            switch (choose)
            {
                case 1:
                    textColor(14);
                    gotoxy(37, 15); printf("  PLAY GAME    ");
                    textColor(202);
                    gotoxy(37, 16); printf("%c  HELP       ", 175);
                    break;
                case 2:
                    textColor(14);
                    gotoxy(37, 17); printf("  ABOUT        ");
                    textColor(202);
                    gotoxy(37, 16); printf("%c  HELP       ", 175);
                    break;    
                case 3:
                    break;
                case 0:
                    break;
            }
		}

		if(coodinate == 17)
		{
            switch (choose)
            {
                case 1:
                    textColor(14);
                    gotoxy(37, 16); printf("  HELP         ");
                    textColor(202);
                    gotoxy(37, 17); printf("%c  ABOUT      ", 175);
                    break;
                case 2:
                    textColor(14);
                    gotoxy(37, 18); printf("  HIGHT SCORE     ");
                    textColor(202);
                    gotoxy(37, 17); printf("%c  ABOUT      ", 175);
                    break;    
                case 3:
                    break;
                case 0:
                    break;
            }
		}

		if(coodinate == 18)
		{
            switch (choose)
            {
                case 1:
                    textColor(14);
                    gotoxy(37, 17); printf("  ABOUT        ");
                    textColor(202);
                    gotoxy(37, 18); printf("%c  HIGHT SCORE  ", 175);
                    break;
                case 2:
                    textColor(14);
                    gotoxy(37, 19); printf("  EXIT        ");
                    textColor(202);
                    gotoxy(37, 18); printf("%c  HIGHT SCORE  ", 175);
                    break;    
                case 3:
                    break;
                case 0:
                    break;
            }
		}

		if(coodinate == 19)
		{
            switch (choose)
            {
                case 1:
                    textColor(14);
                    gotoxy(37, 18); printf("  HIGHT SCORE   ");
                    textColor(202);
                    gotoxy(37, 19); printf("%c  EXIT      ", 175);
                    break;
                case 2:
                    break;    
                case 3:
                    clearScreen();
                    textColor(14);
                    gotoxy(27,13); printf("Thank you for playing our game!!!");
                    gotoxy(32,14); printf("Wish you a nice day!!!");
                    textColor(15); 
                    gotoxy(39,18); printf("SS004.E31");
                    textColor(15); 
                    gotoxy(40,19); printf("Team 5");
                    Sleep(2000);
                    break;
                case 0:
                    break;
            }
		}
	}while(choose != 3);

    _getch();
    clearScreen();
    gotoxy(0, 0);
    Sleep(500);
}
