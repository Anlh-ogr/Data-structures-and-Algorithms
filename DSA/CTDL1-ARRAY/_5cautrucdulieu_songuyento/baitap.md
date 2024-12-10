### Bài tập
Nhập vào một số nguyên dương n, và n số nguyên lần lượt là các phần tử trong dãy a. Hãy in lần lượt các số nguyên tố có trong dãy a ra màn hình, sau mỗi phần tử có đúng một khoảng trắng.
(Số nguyên tố là số nguyên dương có đúng 2 ước là 1 và chính nó. Số a được gọi là ước của b nếu b chia hết cho a). Biết rằng dãy sẽ có ít nhất một số nguyên tố.

Ví dụ:
- Test mẫu 1:
  
  | Input | Output |
  | --- | --- |
  | 4<br>1 2 3 4 | 2 3 |

  Với n = 4, a = [1, 2, 3, 4] thì kết quả mong muốn là: "2 3 ".

- Test mẫu 2:

  | Input | Output |
  | --- | --- |
  | 3<br>7 2 3 | 7 2 3 |

  Với n = 3, a = [7, 2, 3] thì kết quả mong muốn là: "7 2 3 ".


### Hướng dẫn bài tập.
Một trong những cách kiểm tra số nguyên tố tốt nhất đó là:
Để kiểm tra một số n có phải là số nguyên tố hay không ta làm như sau:
- Nếu n < 2 thì n không là số nguyên tố.
- Nếu n = 2 hoặc n = 3 thì n là số nguyên tố.
- Nếu n ≥ 2:
    - Nếu n không có ước trong khoảng 2 đến phần nguyên căn bậc 2 của n thì n là số nguyên tố, ngược lại n không là số nguyên tố.