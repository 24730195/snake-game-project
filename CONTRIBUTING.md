# 🤝 Quy tắc làm việc nhóm – Snake Game

## 📁 1. Cấu trúc thư mục

`/main`       → code chính chạy được sau cùng, giữ main sạch

`/dev`        → nơi để nhóm test, ghép code, fix bug trước khi đưa lên main

`/test`       → Code test riêng, thử nghiệm, lỗi

`/design`     → Ảnh UI, wireframe, export từ Figma

`/doc`        → Slide, báo cáo, ghi chú checklist

---

## 🌿 2. Đặt tên nhánh (branch)

### Các nhánh chính:
- `main` → Bản ổn định để demo/nộp bài
- `dev` → Nhánh phát triển chính

### Nhánh cá nhân:
- Quy tắc: `thao_tac-người_thực_hiện`
- Ví dụ:
  - `test-hau`
  - `update-readme-vy`
  - `ui-quy`

---

## 📝 3. Đặt tên commit

- Quy tắc: `[Loại] Mô tả ngắn gọn`
- Các loại phổ biến:

| Loại commit | Ý nghĩa                |
|-------------|------------------------|
| `[Add]`     | Thêm file/tính năng mới |
| `[Fix]`     | Sửa lỗi (bug)          |
| `[Update]`  | Cập nhật phần đã có    |
| `[Refactor]`| Cải tiến code, tách hàm |
| `[Doc]`     | Ghi chú, tài liệu      |

- Ví dụ:
  - `[Add] Tạo file snake.h`
  - `[Fix] Va chạm rắn với tường`
  - `[Update] Hiển thị điểm số`

---

## 🔁 4. Quy tắc pull / merge

- ✅ Ai làm xong phần mình → **push vào nhánh riêng**
- ✅ Muốn merge vào `dev`:
  - Tạo **pull request**
  - Chọn người review là: **Hậu**
  - Sau khi Hậu duyệt → mới merge vào `dev`
- ❗ Chỉ merge từ `dev` → `main` khi:
  - Chuẩn bị **demo**
  - Code đã **ổn định, không còn lỗi lớn**

---

📌 *Lưu ý: Không push trực tiếp vào `main` hoặc `dev` mà không review.*

---

✅ **Cập nhật bởi nhóm 05 – Snake Game Project**
