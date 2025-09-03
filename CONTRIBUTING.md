# Quy trình làm việc Git & Workflow dự án Snake Game

## 1. Quy tắc đặt tên Branch

### Branch chính
- `main`: chứa code ổn định, đã qua review & test.
- Feature branch: chứa code đang phát triển, merge vào main chính.

### Quy tắc Feature branch:
`feature/<short-description>-name`

## 2. Quy tắc đặt tên Commit
- Sử dụng chuẩn **Conventional Commits**:
`<type>(<scope>): <short-description>`
- Trong đó:
  - `type`: loại commit (feat, fix, docs, style, refactor, perf, test, build, ci, chore, revert)
  - `scope`: phạm vi ảnh hưởng (module, tính năng, component…). Có thể bỏ trống.
  - `short-description`: mô tả ngắn gọn thay đổi, ≤ 72 ký tự.

### Các loại commit
- `feat` → thêm mới tính năng
- `fix` → sửa bug
- `docs` → thay đổi tài liệu (README, docs, comment)
- `style` → chỉnh sửa format/code style (không ảnh hưởng logic)
- `refactor` → tái cấu trúc code, không sửa bug, không thêm feature
- `perf` → cải thiện hiệu năng
- `test` → thêm hoặc chỉnh sửa test case
- `build` → thay đổi build system, dependency, tool, bundler
- `chore` → thay đổi lặt vặt (config, deps, script, rename file…)
- `revert` → hoàn tác commit trước đó

### Ví dụ commit
- `feat(snake): add snake movement controls`
- `feat(food): implement random food spawn`
- `fix(score): correct score calculation when eating food`
- `fix(collision): prevent snake from spawning inside wall`

**📌 Tóm gọn:**  
- Branch: `feature/snake_movement-hau`  
- Commit: `feat(snake): add snake movement controls`

## 3. Workflow

1. Repo có branch `main` (chứa code ổn định).  
2. Mỗi dev nhận task từ Jira → tạo branch từ main:
3. Dev code + tự test phần mình làm:
   - Snake movement → test di chuyển 4 hướng
   - Food → test spawn ngẫu nhiên, không trùng snake
   - Score → test cộng điểm khi ăn food
   - Collision → test chạm tường/snake → game over
   - UI → test hiển thị score, restart, game over
4. Commit theo chuẩn Conventional Commits.
5. Push branch → tạo Pull Request (PR) vào main.
6. Tester pull branch về → chạy full game → test toàn bộ flow.
7. Tester báo bug (nếu có) → dev fix trên branch đó.
8. Khi tester confirm OK → merge PR vào main.
9. Khi đủ tính năng → leader build file `.exe`:
- Với file (`.cpp + .h`):
<pre> bash g++ main.cpp -o snake.exe </pre>
- Nếu có nhiều file (`game.cpp, snake.cpp, food.cpp…`):
<pre> bash g++ main.cpp snake.cpp food.cpp -o snake.exe </pre>

10. Tester chạy thử `.exe` cuối cùng trên nhiều máy.
11. Test di chuyển, ăn food, tăng điểm, game over.
12. Confirm OK → nộp đồ án.

---

## 4. Cách Pull Request (PR)

1. Mỗi task → tạo branch từ main.
2. Sau khi code xong → push branch và mở PR vào main.
3. Nội dung PR cần có:
- Tiêu đề ngắn gọn (ví dụ: `feat(snake): add movement`)
- Mô tả thay đổi (tính năng/bugfix nào)
- Ảnh/clip minh họa (nếu có)
4. PR chỉ được merge khi:
- Dev tự test OK
- Tester test toàn bộ OK
- Code đã review qua

## 5. Quy tắc test & fix
- Tài liệu test nằm trong `TEST_PLAN.md`:  
Mô tả từng test case (snake di chuyển, food spawn, score, collision…)
- Mỗi lần tester test PR → tạo file `RESULTS_TEST.md` theo format:

### Test Results
#### Checklist
- [x] Snake di chuyển 4 hướng (PASS)
- [x] Food spawn ngẫu nhiên, không trùng snake (PASS)
- [ ] Score tăng đúng khi ăn food (FAIL)

#### Kết quả
- PASS: ✅
- FAIL: ❌

### Quy trình xử lý bug

**Bước 1: Ghi chú**  
- Test case FAIL: Score không cộng khi snake ăn food.

**Bước 2: Tạo Issue trên GitHub**  
- Title: ngắn gọn, dễ hiểu  
Ví dụ: `fix(score): score not increasing after eating food`  
- Nội dung issue:
- Mô tả bug
- Cách tái hiện (step to reproduce)
- Kỳ vọng (expected)
- Kết quả thực tế (actual)
- Assign issue cho dev phụ trách

**Bước 3: Liên kết Issue với PR**  
- Tester comment vào PR: ❌ Test FAIL – liên quan đến issue #15

**Bước 4: Retest**  
- Tester test lại sau khi dev push.  
- Cập nhật `RESULTS_TEST.md`: chuyển từ FAIL → PASS

**👉 Tóm lại:**  
- Tester tạo Issue (ghi bug chi tiết)  
- Ghi link Issue vào PR  
- Dev nhìn vào Issue để biết cần fix gì  
- Khi fix xong → tester retest, update kết quả
