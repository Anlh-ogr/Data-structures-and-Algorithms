## Bài tập.

Nhập vào một số nguyên dương `n`, và `n` số nguyên lần lượt là các phần tử trong dãy `a`.
Hãy thay đổi giá trị của mỗi phần tử thành bình phương của chính nó, sau đó in mảng đó ra màn hình (mỗi phần tử cách nhau bởi một khoảng trắng).

**Ví dụ:**

* Test mẫu 1:

  | **Input** | **Input** |
  | --------------- | --------------- |
  | 4<br />1 3 5 -3 | 1 9 25 9        |

  Với `n = 4` và `a = [1, 3, 5, -3]` thì kết quả mong muốn là: `"1 9 25 9 "`.
* Test mẫu 2:

  | **Input** | **Input** |
  | --------------- | --------------- |
  | 4<br />1 2 3 4  | 1 4 9 16        |

  Với `n = 4` và `a = [1, 2, 3, 4]` thì kết quả mong muốn là: `"1 4 9 16 "`.

## Hướng dẫn bài tập.

Để xử lý một phần tử trong mảng ta chỉ cần biết chỉ số của phần tử đó:

![](https://s3-sgn09.fptcloud.com/codelearnstorage/Media/Default/Users/linhdk13_40fpt_2Ecom/linhdk13/692784-1.png)

Ví dụ `a[0] = 4, a[1] = 6, ...`

Để cập nhập phần tử ta cũng có thể gán thẳng giá trị cần cập nhật vào cho vị trí đó.
Ví dụ `a[0] = 7` thì dãy được cập nhật là:

![](https://s3-sgn09.fptcloud.com/codelearnstorage/Media/Default/Users/linhdk13_40fpt_2Ecom/linhdk13/692784-2.png)

Với bài tập trên chúng ta chỉ cần duyệt hết tất cả những phần tử và thay đổi `a[i] = a[i]*a[i]` là được.
