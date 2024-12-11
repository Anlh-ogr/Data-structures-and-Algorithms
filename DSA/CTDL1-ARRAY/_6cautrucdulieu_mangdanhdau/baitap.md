### Bài tập
Nhập và một số nguyên dương n, tiếp theo là n số nguyên dương lần lượt là các phần tử của một dãy số, hãy đếm tần số (số lần xuất hiện) của các số trong dãy và in nó ra màn hình dưới dạng sau: "a1 - t1; a2 - t2; ... an - tn; ", trong đó t1 là số lần xuất hiện của số a1, t2 là số lần xuất hiện của a2, ... a1, a2, .. an không trùng nhau và được sắp xếp tăng dần (xem ví dụ để rõ hơn).

Ví dụ:
- Test mẫu 1:
  | Input | Output |
  |-------|--------|
  |6<br>4 2 2 5 6 5 | 2 - 2; 4 - 1; 5 - 2; 6 - 1; |
  
  Với a = [4, 2, 2, 5, 6, 5] thì kết quả mong muốn là: "2 - 2; 4 - 1; 5 - 2; 6 - 1; ".

- Test mẫu 2:
    | Input | Output |
    |-------|--------|
    |5<br>2 2 2 1 2 | 1 - 1; 2 - 4; |
    
    Với a = [2, 2, 2, 1, 2] thì kết quả mong muốn là: "1 - 1; 2 - 4;".



### Hướng dẫn bài tập.
Với bài này ta sẽ sử dụng kỹ thuật đánh dấu:

Tạo dãy b với mục đích: b[i] sẽ lưu số lần xuất hiện của số có giá trị là i.

Khởi tạo các phần tử của dãy b bằng 0, nếu trong dãy có số a[i] thì ta tăng b[a[i]] lên 1 đơn vị, giá trị của a[i] sẽ được xem là một chỉ số trong dãy b).

Lưu ý: Với các đánh dấu này chỉ áp dụng được khi a[i] có thể là chỉ số của dãy b.