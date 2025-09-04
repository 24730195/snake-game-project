# PROJECT_PLAN.md — Snake Game (C++ Console)

## 1️⃣ Project Overview
- **Game:** Snake Game (C++ Console)  
- **Goal:** Xây dựng Snake cơ bản, chạy trên console, rắn di chuyển, ăn thức ăn, tránh va chạm, phát âm thanh khi ăn mồi.  
- **Team Size:** 5 sinh viên  

---

## 2️⃣ Roles & Responsibilities
| Role            | Member | Responsibility |
|-----------------|--------|----------------|
| Project Leader  | Hậu    | Quản lý tiến độ, tổng hợp module, kiểm tra merge |
| Documentation   | Vy     | Soạn thảo đồ án, tài liệu, DESIGN.md, CONTRIBUTING.md, báo cáo cuối cùng |
| Module Snake    | Quý    | Viết class Snake, các hàm core |
| Module Food     | Quý    | Viết class Food, các hàm core |
| Module Game     | Tuấn   | Viết class Game, các hàm core |
| Module Utils    | Tuấn   | Viết các hàm tiện ích chung |
| Tester          | Dương  | Test từng module, kiểm tra game loop, merge modules |

---

## 3️⃣ Project Phases

### Phase 1: Setup & Planning
**Goal:** Chuẩn bị project structure, tạo file, xác định roles  
**Tasks:**  
- [x] Tạo project folder, docs, src, assets  
- [ ] Tạo `main.cpp` và header + cpp cho từng module: Snake, Food, Game, Utils  
- [x] Hoàn thiện `DESIGN.md`  

---

## Phase 2: Implement Modules
**Goal:** Hoàn thành logic core cho từng module  

### 1️⃣ Module Snake  
- [x] `init()` → Khởi tạo rắn ban đầu (3 đốt)  
- [x] `draw()` → Vẽ rắn ra màn hình console  
- [x] `move(int direction)` → Di chuyển rắn theo hướng  
- [ ] `grow()` → Rắn dài thêm một đốt khi ăn mồi  
- [ ] `eraseTail()` → Xóa phần đuôi để rắn di chuyển mượt  
- [ ] `checkCollisionWithWall()` → Kiểm tra rắn có đâm vào tường không  
- [ ] `checkCollisionWithSelf()` → Kiểm tra rắn có tự cắn thân không  

---

### 2️⃣ Module Food  
- [x] `generate()` → Sinh mồi ngẫu nhiên trong khung  
- [x] `draw()` → Vẽ mồi ra màn hình console  
- [ ] `isEaten(const Snake &snake)` → Kiểm tra rắn có ăn mồi không  

---

### 3️⃣ Module Utils  
- [x] `gotoxy(int x, int y)` → Di chuyển con trỏ in ra màn hình console  
- [ ] `hideCursor()` → Ẩn con trỏ nhấp nháy trong console  
- [ ] `randomInt(int min, int max)` → Sinh số ngẫu nhiên trong khoảng  
- [ ] *(Optional)* `clearScreen()` → Xóa console trước khi render frame mới  
- [ ] *(Optional)* `beep()` → Phát âm thanh khi rắn ăn mồi  

---

## Phase 3: Integrate Game
**Goal:** Kết hợp các module, xây dựng game loop  

### 4️⃣ Module Game  
- [ ] `Game()` → Khởi tạo game (rắn, mồi, điểm, hướng mặc định)  
- [ ] `run()` → Vòng lặp chính của game (xử lý input + update + render)  
- [x] `drawFrame()` → Vẽ khung viền trò chơi  
- [ ] `displayScore()` → Hiển thị điểm số hiện tại  
- [ ] `gameOver()` → In thông báo thua, dừng game  

### Main Entry  
- [ ] `main.cpp` → Tạo `Game g;` và gọi `g.run()` để khởi động game  

---

### Phase 4: Testing & Bug Fixing
**Goal:** Đảm bảo game chạy đúng, không lỗi  
**Tasks:**  
- [ ] Test từng module độc lập  
- [ ] Test full game loop: di chuyển rắn, ăn thức ăn, va chạm, âm thanh  
- [ ] Merge các module vào project chính  
- [ ] Fix bug nếu có  

---

### Phase 5: Documentation & Wrap-up
**Goal:** Hoàn thiện project, ghi chép, chuẩn bị nộp  
**Tasks:**  
- [ ] Hoàn thiện đồ án báo cáo 
- [ ] Viết README hoặc hướng dẫn sử dụng game  
- [ ] Kiểm tra code, clean up, comment đầy đủ  

---

## Notes
- Team nên làm **module riêng, header + cpp**, test xong mới merge main.  
- Mỗi member cập nhật tiến độ hằng ngày để leader kiểm tra.
