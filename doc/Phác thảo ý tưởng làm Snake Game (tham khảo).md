## 1. Tên trò chơi: Snake Classic

## 2. Cách chơi:
- Người chơi điều khiển con rắn để ăn các thức ăn và mỗi lần ăn kéo dài chiều dài rắn thêm 1 đơn vị, càng nhiều càng tốt và mỗi lần ăn mồi +3đ.
- Trò chơi kết thúc khi rắn chạm vào tường hoặc chính cơ thể của nó.
- Sau đó hiển thị tổng số điểm.

## 3. Luật chơi
- Bắt đầu với rắn dài 3 khúc
- Rắn di chuyển liên tục theo một hướng.
- Người chơi điều khiển rắn bằng các phím: W/A/S/D hoặc Mũi tên.
- Khi rắn ăn được thức ăn:
  - Rắn dài ra
  - Điểm tăng 3đ
- Khi rắn đụng tường hoặc cắn vào chính mình → Game Over

## 4. Kỹ thuật:

### 4.1. Ngôn ngữ lập trình sử dụng: C/C++

### 4.2. Thư viện sử dụng:
- `<iostream>` để xử lý nhập xuất cơ bản  
- `<conio.h>` để nhận phím bấm không cần nhấn Enter  
- `<windows.h>` để xử lý thời gian và di chuyển con trỏ console (hàm `Sleep`, `gotoxy`)  
- `<cstdlib>` và `<ctime>` để tạo vị trí mồi ngẫu nhiên  

### 4.3. Giải thuật chính:
- **Di chuyển rắn:**
  - Mỗi lần tick thời gian, cập nhật vị trí đầu rắn theo hướng đang di chuyển.
  - Dịch chuyển các khúc thân theo sau đầu.
  - Nếu không ăn mồi → bỏ khúc đuôi (để giữ độ dài).
  - Nếu ăn mồi → không bỏ khúc đuôi → rắn dài thêm 1.
- **Sinh mồi:**
  - Tạo vị trí ngẫu nhiên nằm trong bản đồ (dùng `rand()` để tạo x, y ngẫu nhiên).
  - Đảm bảo không trùng với thân rắn.
- **Va chạm:**
  - Nếu đầu rắn trùng với tường → thua.
  - Nếu đầu rắn trùng với bất kỳ khúc thân nào → thua.
- **Điều khiển:**
  - Dùng phím mũi tên để thay đổi hướng rắn.

### 4.4. Cấu trúc dữ liệu chính:

### 4.5. Các hàm chính:

#### Hàm xử lý logic và trạng thái game

| Tên hàm          | Mô tả                                                                 |
|------------------|----------------------------------------------------------------------|
| `init_game()`     | Khởi tạo trạng thái ban đầu của game: tạo rắn, thức ăn, điểm, tốc độ. |
| `reset_game()`    | Đặt lại game về trạng thái ban đầu sau khi thua hoặc chơi lại.        |
| `update_game()`   | Cập nhật trạng thái game theo thời gian thực: di chuyển rắn, kiểm tra va chạm, ăn mồi. |
| `check_collision()` | Kiểm tra va chạm với tường hoặc thân rắn (kết thúc game).             |
| `check_eat_food()` | Kiểm tra nếu rắn ăn trúng mồi → tăng chiều dài, tăng điểm.            |

#### Hàm xử lý đầu vào

| Tên hàm                | Mô tả                                                           |
|------------------------|----------------------------------------------------------------|
| `handle_input(event)`    | Nhận và xử lý phím điều hướng (trái/phải/lên/xuống) từ người chơi. |
| `change_direction(new_direction)` | Đổi hướng đi của rắn, tránh trường hợp quay đầu ngược lại.        |

#### Hàm xử lý hiển thị

| Tên hàm             | Mô tả                             |
|---------------------|----------------------------------|
| `draw_snake(screen)`  | Vẽ rắn lên màn hình.              |
| `draw_food(screen)`   | Vẽ mồi.                           |
| `draw_score(screen)`  | Hiển thị điểm số.                 |
| `draw_game_over(screen)` | Hiển thị màn hình “Game Over”.   |
| `render()`           | Gọi tất cả hàm vẽ để hiển thị frame hiện tại. |

#### Hàm xử lý thời gian & tốc độ

| Tên hàm             | Mô tả                                      |
|---------------------|---------------------------------------------|
| `set_game_speed()`    | Cài đặt tốc độ ban đầu của game.             |
| `increase_speed()`    | Tăng tốc độ game theo thời gian hoặc số điểm. |

#### Hàm lưu điểm cao

| Tên hàm               | Mô tả                       |
|------------------------|-----------------------------|
| `save_high_score(score)` | Lưu điểm cao vào file.       |
| `load_high_score()`      | Tải điểm cao khi khởi động game. |

## 5. Giao diện hiển thị
- Hiển thị bằng console (màn hình đen)
- Mỗi phần của rắn vẽ bằng ký tự `O`
- Mồi vẽ bằng
- Tường là `#` hoặc `|`
- Dùng `gotoxy(x, y)` để vẽ tại vị trí bất kỳ trong console
- Hiển thị điểm ở góc màn hình

**Hoặc giao diện thiết kế UI**
