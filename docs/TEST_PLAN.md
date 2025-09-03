# TEST PLAN - Snake Game

## 1. Overview
Mục tiêu: Đảm bảo game Rắn săn mồi (Snake Game) hoạt động đúng logic, không crash, trải nghiệm người dùng ổn định.  
Phạm vi test: Toàn bộ các chức năng gameplay, UI/UX cơ bản.  

---

## 2. Checklist Test

- [ ] Game chạy được (không crash khi mở).  
- [ ] Khởi tạo màn hình, kích thước hiển thị đúng.  
- [ ] Snake hiển thị ban đầu đúng vị trí.  
- [ ] Food xuất hiện ngẫu nhiên, không trùng thân Snake.  
- [ ] Snake di chuyển đúng theo phím bấm (↑ ↓ ← →).  
- [ ] Snake ăn food thì dài thêm 1 ô.  
- [ ] Ăn food thì điểm số tăng.  
- [ ] Game over khi Snake đụng tường.  
- [ ] Game over khi Snake cắn trúng thân.  
- [ ] Sau khi Game over, người chơi có thể restart.  

---

## 3. Functional Testcases

| ID      | Testcase               | Input/Action                | Expected Result                        | Status |
|---------|------------------------|-----------------------------|----------------------------------------|--------|
| TC-01   | Start game             | Run `snake.exe`             | Màn hình hiển thị Snake + Food ban đầu | ✅/❌ |
| TC-02   | Snake di chuyển lên    | Nhấn ↑                      | Snake di chuyển lên 1 ô                 | ✅/❌ |
| TC-03   | Snake di chuyển trái   | Nhấn ←                      | Snake di chuyển sang trái 1 ô           | ✅/❌ |
| TC-04   | Ăn food                | Điều khiển Snake đến food   | Snake dài thêm 1 ô, điểm +1             | ✅/❌ |
| TC-05   | Food respawn           | Snake ăn food               | Food xuất hiện ở vị trí ngẫu nhiên mới  | ✅/❌ |
| TC-06   | Đụng tường             | Cho Snake đi ra khỏi map    | Hiện Game Over                         | ✅/❌ |
| TC-07   | Tự cắn vào thân        | Snake quay lại cắn thân     | Hiện Game Over                         | ✅/❌ |
| TC-08   | Restart sau Game Over  | Nhấn Enter (hoặc phím quy định) | Game reset, Snake về trạng thái ban đầu | ✅/❌ |
| TC-09   | FPS/game speed         | Quan sát tốc độ chạy        | Snake di chuyển mượt, đúng tốc độ       | ✅/❌ |
| TC-10   | Điểm số hiển thị       | Ăn food nhiều lần           | Điểm số hiển thị đúng trên UI           | ✅/❌ |

---

## 4. Non-functional Test

- [ ] **Performance**: Snake không bị lag khi dài nhiều ô.  
- [ ] **Stability**: Chạy game 10 phút không crash.  
- [ ] **UX**: Restart dễ dàng, hiển thị rõ ràng Game Over.  

---

## 5. Bug/Issue Tracking
- Khi test, nếu phát hiện bug, ghi lại vào file `ISSUES.md` hoặc issue trên GitHub theo format:  
  - **ID**: Mã bug  
  - **Steps to Reproduce**: Cách để tái hiện bug  
  - **Expected Result**: Kết quả mong đợi  
  - **Actual Result**: Kết quả thực tế  
  - **Status**: Open / In progress / Fixed  
