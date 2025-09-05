# 🐍 Snake Game – Đồ án nhóm

---

## 🔖 Thông tin dự án
- **Môn học**: Kỹ năng nghề nghiệp  
- **Nhóm**: 05  
- **Ngôn ngữ**: C++  
- **Nền tảng**: Console (Windows)  

---

## 👥 Thành viên & Vai trò

| Role              | Thành viên | Nhiệm vụ |
|-------------------|------------|----------|
| Project Leader    | Hậu        | Quản lý tiến độ, tổng hợp module, kiểm tra merge |
| Technical Writer  | Vy         | Soạn thảo tài liệu (`DESIGN.md`, `CONTRIBUTING.md`), viết báo cáo cuối cùng |
| Module Snake      | Quý        | Viết class Snake và các hàm core |
| Module Food       | Quý        | Viết class Food và các hàm core |
| Module Game       | Tuấn       | Viết class Game và các hàm core |
| Module Utils      | Tuấn       | Viết các hàm tiện ích chung |
| Tester            | Dương      | Test từng module, kiểm tra game loop, kiểm tra merge |

---

## 🌿 Các nhánh (Branch)

- `main` → Bản ổn định cuối cùng để demo hoặc nộp  
- Nhánh cá nhân → Mỗi thành viên code và test riêng  

---

## 📁 Cấu trúc thư mục
- `main/` → Code chính chạy được sau cùng (giữ main sạch)
- `test/` → Code test riêng, thử nghiệm
- `docs/` → Slide, báo cáo, ghi chú, checklist
- `assets/` → Tài nguyên, CONTRIBUTING.md → quy tắc nhóm
- `DESIGN.md` → Tài liệu thiết kế
- `PROJECT_PLAN.md` → Kế hoạch & checklist
- `README.md` → Tài liệu giới thiệu project

---

## 🧠 Cách làm việc (Workflow)

1. Repo có branch `main` (code ổn định).  
2. Mỗi dev nhận task từ Jira → tạo branch từ `main`.  
3. Dev code + tự test phần mình:  
   - Snake movement → test di chuyển 4 hướng  
   - Food → test spawn ngẫu nhiên, không trùng snake  
   - Score → test cộng điểm khi ăn food  
   - Collision → test chạm tường/snake → game over  
   - UI → test hiển thị score, restart, game over  
4. Commit theo chuẩn **Conventional Commits**.  
5. Push branch → tạo Pull Request (PR) vào `main`.  
6. Tester pull branch về → chạy full game → test toàn bộ flow.  
7. Tester báo bug (nếu có) → dev fix.  
8. Khi tester confirm **OK** → merge PR vào `main`.  

---

## ▶️ Hướng dẫn chơi

- **Mục tiêu**: Điều khiển rắn ăn thức ăn để dài hơn, tránh va chạm vào tường hoặc chính mình.  
- **Điều khiển**:  
  - `W` → Lên  
  - `S` → Xuống  
  - `A` → Trái  
  - `D` → Phải  
- **Luật chơi**:  
  - Ăn thức ăn → +1 điểm, rắn dài thêm 1.  
  - Đâm vào tường hoặc thân rắn → **Game Over**.  
- **Kết thúc**: Game sẽ dừng và hiển thị thông báo **Game Over**.  

---

## 💻 Cách chạy chương trình

### Yêu cầu
- Compiler: `g++` hoặc IDE (Code::Blocks, Visual Studio, Dev-C++)  
- Hệ điều hành: Windows (sử dụng `conio.h` và `system("cls")`)  

### Build & Run
```bash
g++ main.cpp -o snake
snake.exe
