# RESULT TEST - Snake Game

## 1. Summary
- Ngày test: 8/9/2025
- Tester: Dương
- Phiên bản (commit ID): 2259f69

---

## 2. Test Results

| ID    | Testcase               | Result | Note |
|-------|------------------------|--------|------|
| TC-01 | Start game             |   ✅   |      |
| TC-02 | Snake di chuyển lên    |   ✅   |      |
| TC-03 | Snake di chuyển trái   |   ✅   |      |
| TC-04 | Ăn food                |   ✅   |      |
| TC-05 | Food respawn           |   ✅   |      |
| TC-06 | Đụng tường             |   ✅   |      |
| TC-07 | Tự cắn vào thân        |   ✅   |      |
| TC-08 | Restart sau Game Over  |   ✅   |      |
| TC-09 | FPS/game speed         |   ✅   |      |
| TC-10 | Điểm số hiển thị       |   ✅   |      |

- Result: ✅ = Pass, ❌ = Fail  
- Note: Ghi mô tả ngắn gọn khi fail (ví dụ: "không tăng điểm").  

---

## TC01 - Start game
- **Mô tả**: Kiểm tra khởi động game
- **Bước thực hiện**: Chạy chương trình
- **Kết quả mong đợi**: Màn hình game hiển thị, rắn xuất hiện ở giữa
- **Kết quả thực tế**: Đúng
- **Trạng thái**: Pass ✅

## TC02 - Snake đi chuyển lên
- **Mô tả**: Kiểm tra khi nhấn phím để rắn đi chuyển lên
- **Bước thực hiện**: Điều khiển rắn đi chuyển lên
- **Kết quả mong đợi**:
  - Rắn đi chuyển lên
- **Kết quả thực tế**: Đúng
- **Trạng thái**: Pass ✅

## TC03 - Snake di chuyển trái
- **Mô tả**: Kiểm tra khi rắn di chuyển trái
- **Bước thực hiện**: Điều khiển rắn đi chuyển trái
- **Kết quả mong đợi**:
  - Rắn đi chuyển trái
- **Kết quả thực tế**: Đúng
- **Trạng thái**: Pass ✅

## TC04 - Ăn Food
- **Mô tả**: Kiểm tra khi đầu rắn chạm mồi
- **Bước thực hiện**: Điều khiển rắn ăn mồi
- **Kết quả mong đợi**:
  - Độ dài rắn tăng thêm 1
  - Mồi mới sinh ra trong khung
- **Kết quả thực tế**: Đúng
- **Trạng thái**: Pass ✅

## TC05 - Đụng tường
- **Mô tả**: Kiểm tra va chạm tường
- **Bước thực hiện**: Điều khiển rắn đi vào tường
- **Kết quả mong đợi**: Game Over
- **Kết quả thực tế**: Đúng
- **Trạng thái**: Pass ✅

## TC06 - Tự cắn vào thân
- **Mô tả**: Kiểm tra va chạm thân rắn
- **Bước thực hiện**: Điều khiển rắn tự cắn vào thân
- **Kết quả mong đợi**: Game Over
- **Kết quả thực tế**: Đúng
- **Trạng thái**: Pass ✅

## TC07 - Điểm số hiển thị
- **Mô tả**: Kiểm tra điểm số khi rắn ăn mồi
- **Bước thực hiện**: Cho rắn ăn liên tiếp nhiều mồi
- **Kết quả mong đợi**: Điểm số tăng đúng với số mồi ăn được
- **Kết quả thực tế**: Đúng
- **Trạng thái**: Pass ✅

## TC08 - FPS / Game speed
- **Mô tả**: Kiểm tra tốc độ game khi rắn dài hơn
- **Bước thực hiện**: Cho rắn ăn nhiều mồi để tăng độ dài
- **Kết quả mong đợi**: FPS/game speed ổn định, không bị chậm hoặc lag bất thường
- **Kết quả thực tế**: Đúng
- **Trạng thái**: Pass ✅

## TC09 - Restart sau Game Over
- **Mô tả**: Kiểm tra khả năng chơi lại sau khi thua
- **Bước thực hiện**: 
  1. Điều khiển rắn va chạm để Game Over  
  2. Chọn tính năng Restart / nhấn phím restart (nếu có)  
- **Kết quả mong đợi**: Game bắt đầu lại từ đầu, rắn ở vị trí khởi tạo, điểm số = 0
- **Kết quả thực tế**: Đúng
- **Trạng thái**: Pass ✅

---

## 3. Bug Report
- None - Không phát hiện bug trong quá trình test.

---

## 4. Conclusion
- Passed: All
- Failed: None
- Tổng kết: Tất cả các test case đều chạy đúng yêu cầu, chương trình hoạt động ổn định và không phát hiện lỗi.
