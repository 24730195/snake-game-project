# **DESIGN.md — Snake Game (C++ Console)**

---

## **1️⃣ Concept**

- **Game**: Snake Game  
- **Nền tảng**: Console / Terminal  
- **Mục tiêu**: Điều khiển rắn ăn thức ăn, tránh va chạm tường hoặc chính mình.  
- **Giao diện**: ASCII/console, hiển thị rắn, thức ăn, điểm.  
- **Âm thanh**: khi rắn ăn thức ăn → phát beep hoặc âm thanh đơn giản console.  
- **Controls**: `W/A/S/D` → di chuyển rắn.  
- **Bản đồ**: mặc định `20x20`, có thể mở rộng.  

---

## **2️⃣ Modules & Functions**

### 1. Module **Snake**
**Chức năng**: Quản lý rắn, di chuyển, tăng chiều dài, kiểm tra va chạm.  

**Hàm chính:**
- `init()` → Khởi tạo rắn ban đầu (3 đốt).  
- `draw()` → Vẽ rắn ra màn hình console.  
- `move(int direction)` → Di chuyển rắn theo hướng.  
- `grow()` → Rắn dài thêm một đốt khi ăn mồi.  
- `eraseTail()` → Xóa phần đuôi để rắn di chuyển mượt.  
- `checkCollisionWithWall()` → Kiểm tra rắn có đâm vào tường không.  
- `checkCollisionWithSelf()` → Kiểm tra rắn có tự cắn thân không.  

---

### 2. Module **Food**
**Chức năng:** Quản lý vị trí mồi và sinh mồi mới.  

### Hàm chính:
- `generate()` → Sinh mồi ngẫu nhiên trong khung.  
- `draw()` → Vẽ mồi ra màn hình console.  
- `isEaten(const Snake &snake)` → Kiểm tra rắn có ăn mồi không.  

---

### 3. Module **Game**
**Chức năng:** Quản lý vòng lặp chính của trò chơi.  

### Hàm chính:
- `Game()` → Khởi tạo game (rắn, mồi, điểm, hướng mặc định).  
- `run()` → Vòng lặp chính của game.  
- `drawFrame()` → Vẽ khung viền trò chơi.  
- `displayScore()` → Hiển thị điểm số hiện tại.  
- `gameOver()` → In thông báo thua, dừng game.  

*(Xử lý input (W/A/S/D) được viết gộp trong `run()`.)*  

---

### 4. Module **Utils**
**Chức năng:** Các hàm tiện ích dùng chung.  

### Hàm chính:
- `gotoxy(int x, int y)` → Di chuyển con trỏ in ra màn hình console.  
- `hideCursor()` → Ẩn con trỏ nhấp nháy trong console.  
- `randomInt(int min, int max)` → Sinh số ngẫu nhiên trong khoảng.  

*(Có thể mở rộng thêm: `clearScreen()`, `beep()` nếu muốn hiệu ứng âm thanh hoặc xóa màn hình.)*

---

## **3️⃣ File Structure**
📂 Project Root
│── main.cpp # Entry point, chỉ khởi tạo Game object và gọi run()
│── Game.h / Game.cpp # Chứa class Game
│── Snake.h / Snake.cpp # Chứa class Snake
│── Food.h / Food.cpp # Chứa class Food
│── Utils.h / Utils.cpp # Chứa các hàm tiện ích chung
│── (Optional) Assets/ # Chứa âm thanh hoặc file dữ liệu nếu cần

**Nguyên tắc:**
- **Header (.h)** → khai báo class, hàm, biến  
- **CPP (.cpp)** → implement logic  
- **main.cpp** → chạy game, không code logic chi tiết  

---

## **4️⃣ Game Flow / Team Guidance**

### **Game Flow**
1. `main.cpp` tạo `Game g;` → gọi `g.run()`.  
2. `Game.run()`:
   - Bắt phím điều khiển (W/A/S/D).  
   - Di chuyển rắn → kiểm tra ăn mồi → tăng điểm.  
   - Kiểm tra va chạm (tường, thân).  
   - Vẽ lại khung + rắn + mồi + điểm.
3. Khi rắn ăn mồi → gọi `snake.grow()`, `food.generate()`, `score++`.  
4. Khi va chạm → gọi `gameOver()` và kết thúc vòng lặp. 

### **Team Guidance**
- Ai làm module nào → code module đó riêng (`.h` + `.cpp`)  
- Xong module → merge vào `main`  
- Test từng module trước khi combine  
