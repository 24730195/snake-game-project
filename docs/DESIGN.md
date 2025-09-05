# Snake Game — DESIGN.md

## 1️⃣ Concept

- **Game**: Snake Game  
- **Nền tảng**: Console / Terminal  
- **Mục tiêu**: Điều khiển rắn ăn thức ăn, tránh va chạm tường hoặc chính mình.  
- **Giao diện**: ASCII/console, hiển thị rắn, thức ăn, điểm.  
- **Âm thanh**: khi rắn ăn thức ăn → có thể phát *beep*.  
- **Controls**: `W/A/S/D` → di chuyển rắn.  
- **Bản đồ**: khung viền, kích thước mặc định ~ `90x25`.  

---

## 2️⃣ Modules & Functions
### 🔹 1. Module Snake
- **Chức năng**: Quản lý rắn, di chuyển, tăng chiều dài.  
- `init()` → Khởi tạo rắn ban đầu (3 đốt).  
- `draw()` → Vẽ rắn ra màn hình console.  
- `move(int direction)` → Di chuyển rắn theo hướng.  
- `grow()` → Được xử lý trong `eatFood()` (tăng `Length++`).  
- `eraseTail()` → Xóa phần đuôi để rắn di chuyển mượt (hiện dùng `system("cls")`).  
- `checkCollisionWithWall()` → Kiểm tra rắn có đâm vào tường không.  
- `checkCollisionWithSelf()` → Kiểm tra rắn có tự cắn thân không.  

---

### 🔹 2. Module Food
- **Chức năng**: Quản lý vị trí mồi và sinh mồi mới.  
- `generateFood()` → Sinh mồi ngẫu nhiên trong khung.  
- `drawFood()` → Vẽ mồi ra màn hình console.  
- `eatFood(Snake &snake)` → Kiểm tra rắn có ăn mồi không và tăng chiều dài.  

---

### 🔹 3. Module Game
- **Chức năng**: Quản lý vòng lặp chính, khung chơi, input, logic.  
- Vòng lặp `while(1)` để chạy game.  
- Bắt phím điều khiển `W/A/S/D`.  
- `DrawFrame()` → Vẽ khung viền trò chơi.  

**Hàm dự kiến bổ sung**:
- `displayScore()` → Hiển thị điểm số hiện tại.  
- `gameOver()` → In thông báo thua, dừng game.  

---

### 🔹 4. Module Utils
- **Chức năng**: Các hàm tiện ích dùng chung.  
- `gotoxy(int x, int y)` → Di chuyển con trỏ in ra màn hình console.  
- `hideCursor()` → Ẩn con trỏ nhấp nháy trong console.  
- `randomInt(int min, int max)` → Sinh số ngẫu nhiên trong khoảng (hiện dùng `rand()`).  
- *(Optional)* `clearScreen()` → Xóa console trước khi render frame mới (hiện dùng `system("cls")`).  
- *(Optional)* `beep()` → Phát âm thanh khi rắn ăn mồi.  

---

## 3️⃣ File Structure
- `main.cpp` # Chứa toàn bộ code (Snake, Food, Utils, Game loop)
- `DESIGN.md` # Tài liệu thiết kế
- `PROJECT_PLAN.md` # Kế hoạch & checklist

## 4️⃣ Game Flow / Team Guidance

### Game Flow
1. `main.cpp` → khởi tạo **Snake + Food**, vẽ khung.  
2. Vòng lặp game (`while(1)`):  
   - Nhận input từ bàn phím (`W/A/S/D`).  
   - Di chuyển rắn theo hướng.  
   - Vẽ lại khung, rắn, mồi.  
   - Kiểm tra ăn mồi (`eatFood()`) → tăng chiều dài.  
   - *(Sau này)* Kiểm tra va chạm (tường, thân).  
   - *(Sau này)* Cập nhật điểm số.  
3. Khi va chạm → gọi `gameOver()` và kết thúc vòng lặp.  

### **Team Guidance**
- Xong module → merge vào `main`  
- Test từng module trước khi combine  
