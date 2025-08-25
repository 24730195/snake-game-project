const int WIDTH = 40;   // chiều rộng khung
const int HEIGHT = 20;  // chiều cao khung

// Hàm di chuyển con trỏ in ra màn hình console
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Hàm vẽ khung trò chơi
void DrawFrame() {
    for (int x = 0; x <= WIDTH; x++) {
        gotoxy(x, 0);      cout << "#";   // cạnh trên
        gotoxy(x, HEIGHT); cout << "#";   // cạnh dưới
    }
    for (int y = 0; y <= HEIGHT; y++) {
        gotoxy(0, y);      cout << "#";   // cạnh trái
        gotoxy(WIDTH, y);  cout << "#";   // cạnh phải
    }
}

int main() {
  DrawFrame();
    return 0;
}
