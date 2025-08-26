# Ngày 01: Class & Object (cpp)

## 📚 Kiến thức cơ bản

### 1. Class (Lớp)
 - **Là bản thiết kế** (blueprint) để tạo ra các đối tượng.
 - Định nghĩa **thuộc tính** (dữ liệu) và **phương thức** (hành vi) của đối tượng.
 - **Cú pháp** khai báo lớp:
    <br>
    ```cpp
    class ClassName {
        public:
            // Thuộc tính (biến)
            // Phương thức (hàm)
    };
    ```
    <br>

### 2. Object (Đối tượng)
 - Là **thể hiện** (instance) cụ thể của một lớp.
 - Mỗi đối tượng có các thuộc tính và phương thức riêng, được tạo từ lớp.
 - **Cú pháp** tạo đối tượng:
    <br>
    ```bash
    ClassName objectName;
    ```
    <br>

### 3. Attributes (Thuôc tính)
 - Là các **biến** bên trong lớp, biểu thị **đặc điểm** của đối tượng.
 - Ví dụ: Trong lớp **`Car`**, thuộc tính có thể là **`brand`** (hãng xe) hoặc **`speed`** (tốc độ).


### 4. Methods (Phương thức)
 - Là các hàm được định nghĩa trong lớp, biểu thị **hành vi** của đối tượng.
 - Ví dụ: Hàm **`drive()`** để hiển thị thông tin xe đang chạy.


## 🛠️ Bài tập: Tạo class Car

### 🎯 Yêu cầu
 - Tạo một lớp **`Car`** với các **thuộc tính**:  
   - **`brand`** (kiểu **`string`**): Hãng xe.  
   - **`speed`** (kiểu **`int`**): Tốc độ xe (km/h).

 - Viết **phương thức** **`drive()`** để in thông tin xe theo định dạng:
    <br>
    ``` bash
    [brand] is driving at [speed] km/h
    ```
    <br>

## 🧠 Hướng dẫn gợi ý

1. Khai báo lớp **Car**:
   - Sử dụng từ khóa **`class`** để định nghĩa lớp.
   - Khai báo hai thuộc tính: **`brand`** (kiểu **`string`**) và **`speed`** (kiểu **`int`**).
   - Đặt thuộc tính và phương thức trong phạm vi **`public`** để truy cập từ bên ngoài.

2. Viết phương thức **`drive()`**:  
   - Định nghĩa hàm **`drive()`** trong lớp, không nhận tham số.
   - Sử dụng **`cout`** để in thông tin xe theo định dạng yêu cầu.

3. Tạo đối tượng và kiểm tra:  
   - Trong hàm **`main()`**, tạo một đối tượng của lớp **`Car`**.  
   - Gán giá trị cho **`brand`** và **`speed`**.  
   - Gọi phương thức **`drive()`** để kiểm tra kết quả.

## 💡 Mẹo và Lưu ý
 - **Thư viện cần thiết**: Đừng quên bao gồm **`string`** để sử dụng kiểu **`string`**.
 - **Phạm vi truy cập**: Sử dụng **`public`** để cho phép truy cập thuộc tính/phương thức từ bên ngoài.
 - **Mở rộng bài tập**: Bạn có thể thêm các thuộc tính như **`color`** (màu xe) hoặc phương thức như **`stop()`** để làm bài tập thú vị hơn!
 - **Thử thách**: Tạo thêm một đối tượng **`car2`** với hãng xe và tốc độ khác, sau đó gọi **`drive()`** để so sánh.