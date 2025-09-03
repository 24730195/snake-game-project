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
- `move()` → Di chuyển rắn theo hướng hiện tại  
- `grow()` → Tăng chiều dài rắn khi ăn thức ăn  
- `changeDirection(char newDir)` → Thay đổi hướng rắn dựa trên input `W/A/S/D`  
- `eatSelf()` → Kiểm tra rắn tự cắn → game over  
- `getBody()` → Trả về vector các tọa độ hiện tại của rắn  

---

### 2. Module **Food**
**Chức năng**: Tạo và quản lý vị trí thức ăn trên bản đồ  

**Hàm chính:**
- `respawn(int width, int height, vector<pair<int,int>> snakeBody)` → Sinh thức ăn ngẫu nhiên, không trùng rắn  
- `getPosition()` → Trả về tọa độ hiện tại của thức ăn  

---

### 3. Module **Game**
**Chức năng**: Điều phối game loop, xử lý input, update trạng thái  

**Hàm chính:**
- `run()` → Vòng lặp chính: input → update → render  
- `processInput()` → Nhận input từ người chơi (`W/A/S/D`)  
- `update()` → Di chuyển rắn, kiểm tra ăn thức ăn, va chạm, tăng điểm  
- `render()` → Vẽ bản đồ ra console, hiển thị rắn, thức ăn, điểm  
- `playSound()` → Phát âm thanh khi rắn ăn thức ăn  

---

### 4. Module **Utils**
**Chức năng**: Các hàm tiện ích dùng chung cho game.  

**Hàm chính:**
- `clearScreen()` → Xóa console để render frame mới  
- `sleep(ms)` → Tạm dừng game, tạo tốc độ di chuyển rắn  
- `randomInt(min, max)` → Sinh số ngẫu nhiên trong khoảng  
- `beep()` → Phát âm thanh đơn giản trên console  

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
1. `main.cpp` tạo **Game object** → gọi `run()`  
2. `Game.run()` → vòng lặp: `processInput()` → `update()` → `render()`  
3. **Game** sử dụng **Snake + Food + Utils**  
4. **Snake** quản lý thân rắn, di chuyển, ăn thức ăn, check va chạm  
5. **Food** quản lý vị trí thức ăn  
6. **Utils** cung cấp helper: `clearScreen`, `sleep`, `randomInt`, `beep`  

### **Team Guidance**
- Ai làm module nào → code module đó riêng (`.h` + `.cpp`)  
- Xong module → merge vào `main`  
- Test từng module trước khi combine  
