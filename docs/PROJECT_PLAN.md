# PROJECT_PLAN.md — Snake Game (C++ Console)

## 1️⃣ Project Overview
- **Game:** Snake Game (C++ Console)  
- **Goal:** Xây dựng Snake cơ bản, chạy trên console, rắn di chuyển, ăn thức ăn, tránh va chạm, phát âm thanh khi ăn mồi.  
- **Team Size:** 5 sinh viên  

---

## 2️⃣ Roles & Responsibilities

| Role              | Member | Responsibility                                                         |
|-------------------|--------|------------------------------------------------------------------------|
| Project Leader    | Hậu    | Quản lý tiến độ, tổng hợp module, kiểm tra merge                       |
| Technical Writer  | Vy     | Soạn thảo tài liệu (DESIGN.md, CONTRIBUTING.md), viết báo cáo cuối cùng |
| Module Snake      | Quý    | Viết class Snake và các hàm core                                       |
| Module Food       | Quý    | Viết class Food và các hàm core                                        |
| Module Game       | Tuấn   | Viết class Game và các hàm core                                        |
| Module Utils      | Tuấn   | Viết các hàm tiện ích chung                                            |
| Tester            | Dương  | Test từng module, kiểm tra game loop, kiểm tra merge                   |


---

## 📌 Project Phase

### Phase 1: Setup & Planning
- [x] Tạo project folder, docs, src, assets  
- [x] Tạo `main.cpp` (tất cả code nằm trong 1 file)  
- [x] Hoàn thiện `DESIGN.md`  

---

### Phase 2: Implement Modules

#### 1️⃣ Module Snake  
- [x] `init()` → Khởi tạo rắn ban đầu (3 đốt)  
- [x] `draw()` → Vẽ rắn ra màn hình console  
- [x] `move(int direction)` → Di chuyển rắn theo hướng  
- [x] `grow()` → Đã có trong `eatFood()` (tăng `Length++`)  
- [ ] `eraseTail()` → Xóa đuôi rắn cũ để tránh nháy màn hình khi vẽ lại  
- [ ] `checkCollisionWithWall()` → Kiểm tra đầu rắn có chạm vào tường hay không  
- [ ] `checkCollisionWithSelf()` → Kiểm tra đầu rắn có chạm vào chính thân rắn không  

#### 2️⃣ Module Food  
- [x] `generate()` → Hàm `generateFood()` tạo mồi ngẫu nhiên  
- [x] `draw()` → Hàm `drawFood()` hiển thị mồi ra màn hình  
- [x] `isEaten(const Snake &snake)` → Hàm `eatFood()` kiểm tra rắn đã ăn mồi chưa  

#### 3️⃣ Module Utils  
- [x] `gotoxy(int x, int y)` → Di chuyển con trỏ đến tọa độ (x, y) trên console  
- [ ] `hideCursor()` → Ẩn con trỏ nhấp nháy trong console để giao diện gọn gàng hơn  
- [ ] `randomInt(int min, int max)` → Hàm sinh số ngẫu nhiên trong khoảng (min, max) thay cho `rand()`  
- [ ] *(Optional)* `clearScreen()` → Hàm tự viết để xóa màn hình (thay cho `system("cls")`)  
- [ ] *(Optional)* `beep()` → Hàm phát âm thanh khi rắn ăn mồi  

---

### Phase 3: Integrate Game

#### 4️⃣ Module Game  
- [x] `Game()` → Hiện đang nằm trong `main()`  
- [x] `run()` → Vòng lặp `while(1)` trong `main()`  
- [x] `drawFrame()` → Hàm `DrawFrame()` tạo khung viền  
- [ ] `displayScore()` → Hiển thị điểm số trong quá trình chơi  
- [ ] `gameOver()` → Hiển thị thông báo thua cuộc và kết thúc game  

#### Main Entry  
- [x] `main.cpp` → Đã có, chạy trực tiếp game  

---

### Phase 4: Testing & Bug Fixing
- [x] Test chạy game cơ bản (snake di chuyển + ăn mồi)  
- [ ] Test va chạm tường → Kiểm tra xem rắn có chết khi đụng tường  
- [ ] Test va chạm thân → Kiểm tra xem rắn có chết khi tự cắn vào thân  
- [ ] Fix bug nháy màn hình do `system("cls")`  

---

### Phase 5: Documentation & Wrap-up
- [ ] Báo cáo cuối cùng  
- [ ] README chi tiết (hiện chỉ có checklist)  
- [ ] Comment code, clean up  

---

## ✅ Summary
- **Cốt lõi (snake + food + move):** Đã hoàn thành.  
- **Mượt mà + Game Over + Điểm số:** Cần bổ sung thêm để game hoàn chỉnh.  
