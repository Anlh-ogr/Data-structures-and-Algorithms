### Bài tập
Nhập vào một số nguyên dương  n, tiếp theo là n số nguyên dương lần lượt là các phần tử của một dãy số a. Hãy kiểm tra xem dãy a có phải là dãy đơn điệu hay không, trả về "YES" nếu có, "NO" nếu không.

Một dãy đơn điệu khi nó là dãy số tăng (a[i] > a[i-1]), hoặc dãy số giảm (a[i] < a[i-1]).

Ví dụ:
- Test mẫu 1:
  | Input | Output |
  |-------|--------|
  |5<br>1 2 3 4 5 | YES |

  Với a = [1, 2, 3, 4, 5] thì kết quả mong muốn là "YES".

- Test mẫu 2:
  | Input | Output |
  |-------|--------|
  |4<br>5 3 1 -4 | YES |

  Với a = [5, 3, 1, -4] thì kết quả mong muốn là "YES".

- Test mẫu 3:
- | Input | Output |
  |-------|--------|
  |5<br>1 2 4 3 -2 | NO |

  Với a = [1, 2, 4, 3, -2] thì kết quả mong muốn là "NO".

### Hướng dẫn bài tập.
Để kiểm tra tính tăng giảm của dãy số, ta lần lượt kiểm tra hiệu số giữa hai phần tử kề nhau ở trong dãy.

Lưu ý: dãy có 1 phần tử cũng là dãy đơn điệu.