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
- [ ] Tạo project folder, docs, src, assets  
- [ ] Tạo `main.cpp` và header + cpp cho từng module: Snake, Food, Game, Utils  
- [ ] Hoàn thiện `DESIGN.md`  

---

### Phase 2: Implement Modules
**Goal:** Hoàn thành logic core từng module  

**Module Snake:**  
- [ ] **move()** → Di chuyển rắn theo hướng  
- [ ] **grow()** → Tăng chiều dài rắn khi ăn thức ăn  
- [ ] **changeDirection(char newDir)** → Nhận input W/A/S/D  
- [ ] **eatSelf()** → Kiểm tra rắn tự cắn → game over  
- [ ] **getBody()** → Trả về vector tọa độ rắn  

**Module Food:**  
- [ ] **respawn(int width, int height, vector<pair<int,int>> snakeBody)** → Sinh thức ăn không trùng rắn  
- [ ] **getPosition()** → Trả về tọa độ thức ăn  

**Module Utils:**  
- [ ] **clearScreen()** → Xóa console trước khi render frame mới  
- [ ] **sleep(ms)** → Tạm dừng game, tạo tốc độ di chuyển ổn định  
- [ ] **randomInt(min, max)** → Sinh số ngẫu nhiên  
- [ ] **beep()** → Phát âm thanh khi rắn ăn thức ăn  

---

### Phase 3: Integrate Game
**Goal:** Kết hợp các module, tạo game loop  

**Module Game:**  
- [ ] **run()** → Vòng lặp chính: processInput → update → render  
- [ ] **processInput()** → Nhận input W/A/S/D  
- [ ] **update()** → Di chuyển rắn, kiểm tra ăn thức ăn, va chạm, tăng điểm  
- [ ] **render()** → Vẽ bản đồ, rắn, thức ăn, điểm  
- [ ] **playSound()** → Phát âm thanh khi rắn ăn thức ăn  
- [ ] `main.cpp` → Tạo Game object, gọi run()  

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
