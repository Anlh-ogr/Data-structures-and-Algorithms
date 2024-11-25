# Cấu trúc dữ liệu mảng

### Cấu trúc dữ liệu mảng là gì ?

**Mảng (Array)** là một trong các cấu trúc dữ liệu cũ và quan trọng nhất. Mảng có thể lưu giữ một số phần tử cố định và các phần tử này nền có cùng kiểu. Hầu hết các cấu trúc dữ liệu đều sử dụng mảng để triển khai giải thuật. Dưới đây là các khái niệm quan trọng liên quan tới Mảng.

* **Phần tử** : Mỗi mục được lưu giữ trong một mảng được gọi là một phần tử.
* **Chỉ mục (Index)** : Mỗi vị trí của một phần tử trong một mảng có một chỉ mục số được sử dụng để nhận diện phần tử.

Mảng gồm các bản ghi có kiểu giống nhau, có kích thước cố định, mỗi phần tử được xác định bởi chỉ số.

Mảng là cấu trúc dữ liệu được cấp phát liên tục cơ bản.

Ưu điểm của mảng :

* Truy câp phần tử với thời gian hằng số **O(1).**
* Sử dụng bộ nhớ hiệu quả.
* Tính cục bộ về bộ nhớ.

Nhược điểm của mảng:

* Không thể thay đổi kích thước của mảng khi chương trình đang thực hiện.

**Mảng động:**

**Mảng động (dynamic array)** : cấp phát bộ nhớ cho mảng một cách động trong quá trình chạy chương trình trong C là malloc và calloc, trong C++ là new.

Sử dụng mảng động ta bắt đầu với mảng có 1 phần tử, khi số lượng phần tử vượt qua khả năng của mảng thì ta gấp đôi kích thước mảng cũ và copy phần tử mảng cũ vào nửa đầu của mảng mới.

**Ưu điểm:**

* Tránh lãng phí bộ nhớ khi phải khai báo mảng có kích thước lớn ngay từ đầu.

**Nhược điểm:**

* Phải thực hiện them thao tác copy phần tử mỗi khi thay đổi kích thước.
* Một số thời gian thực hiện thao tác không còn là hằng số nữa.

### Biểu diễn Cấu trúc dữ liệu mảng.

Mảng có thể được khai báo theo nhiều cách đa dạng trong các ngôn ngữ lập trình. Để minh họa, chúng ta sử dụng phép khai báo mảng trong ngôn ngữ C:

![](https://s3-sgn09.fptcloud.com/codelearnstorage/Media/Default/Users/linhdk13_40fpt_2Ecom/linhdk13/692192-1.png)

Hình minh họa phần tử và chỉ số:

![](https://s3-sgn09.fptcloud.com/codelearnstorage/Media/Default/Users/linhdk13_40fpt_2Ecom/linhdk13/692192-2.png)

Dưới đây là một số điểm cần ghi nhớ về cấu trúc dữ liệu mảng:

* Chỉ mục bắt đầu với `0`.
* Độ dài mảng là `5`, nghĩa là mảng có thể lưu giữ `5` phần tử.
* Mỗi phần tử đều có thể được truy cập thông qua chỉ số của phần tử đó. Ví dụ, chúng ta có thể lấy giá trị của phần tử tại chỉ số `3` là `-9`.

Phép toán cơ bản được hỗ trợ bởi mảng:

Dưới đây là các hoạt động cơ bản được hỗ trợ bởi một mảng:

* **Duyệt** : In tất cả các phần tử mảng theo cách in từng phần tử một.
* **Chèn** : Thêm một phần tử vào mảng tại chỉ mục đã cho.
* **Xóa** : Xóa một phần tử từ mảng tại chỉ mục đã cho.
* **Tìm kiếm** : Tìm kiếm một phần tử bởi sử dụng chỉ mục hay bởi giá trị.
* **Cập nhật** : Cập nhật giá trị một phần tử tại chỉ mục nào đó.
