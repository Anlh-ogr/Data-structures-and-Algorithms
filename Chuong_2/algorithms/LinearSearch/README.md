## Đặt vấn đề:

Giả sử chúng ta có một mảng M (array_M[a,b,...,n]) gồm n phần tử. Vấn đề đặt ra là có hay không phần tử có giá trị X trong mảng M? Nếu có thì phần tử có giá trị X làm phần tử thứ mấy trong mảng M?

## Tìm tuyến tính

Tìm tuyến tính(Linear Search) còn được gọi là Thuật toán tìm kiếm tuần tự(Sequential Search)

### Giải quyết vấn đề(tư tưởng):

lần lượt so sánh các phần tử mảng M với giá trị X bất đầu từ phần tử ở vị trí đầu tiên trong mảng M cho đến khi tìm đến được phần tử có giá trị X hoặc đã duyệt qua hết tất cả các phần tử trong mảng M thì kết thúc.

##### Thuật toán:

- b1: k = 1							- duyệt từ đầu mảng M
- b2: if(M[k] != X && k <= n)			- nếu chưa tìm thấy và chưa duyệt hết mảng
  - b2.1: k++					 - tiếp tục tăng vị trí giá trị phần tử trong mảng
  - b2.2: lặp lại b2
- b3: if(k <= n)
  - tìm thấy X tại vị trí k
- b4: else
  - không tìm thấy phần tử có giá trị X
- b5: kết thúc
  - return 0;

##### Cài đặt thuật toán

- hàm LinearSearch có protoptype: int LinearSearch (int array_M[], int N, T, X)
- chức năng: thực hiện việc tìm kiếm phần tử có giá trị X trên mảng M có n phần tử.
  - nếu tìm thấy, trả về 1 số nguyên có giá trị từ 0 đến n-1 là vị trí tương ứng của phần tử tìm thấy.
  - ngược lại, trả về giá trị -1(not found)
- int LinearSearch (int array_M[], int N, T, X)
- {
  - int k = 0;
  - while (array_M[k] != X && k < n)
    - k++;
  - if(k < n)
    - return (k);
  - return (-1);
- }

##### Phân tích thuật toán:

* trường hợp tốt nhất khi phần tử đầu tiên của mảng có giá trị = X:

  * số phép gán : Gmin = 1
  * số phép so sánh: Smin = 2 + 1 = 3
* trường hợp xấu nhất khi không tìm thấy phần tử nào có giá trị = X:

  * số phép gán : Gmax = 1
  * số phép so sánh: Smax = 2n + 1
* trung bình:

  * số phép gán : Gavg = 1
  * số phép so sánh: Savg = (3 + 2n + 1) : 2 = n + 2

##### Cải tiến thuật toán:

trong thuật toán trên, ở mỗi bước lặp, cần phải thực hiện 2 phép so sánh để kiểm tra sự tìm thấy và kiểm soát sự hết mảng trong quá trình duyệt mảng. Ta có thể giảm bớt 1 phép so sánh nếu ta thêm vào cuối mảng một phần tử cầm canh(sentinel/stand by) có giá trị bằng X để nhận diện ra sự hết mảng khi duyệt mảng, khi đó thuật toán này được cải tiến lại như sau:

* b1: k = 1
* b2: M[n + 1] = X					// phần tử cầm canh
* b3: if(M[k] != X)

  * b3.1: k++
  * b3.2: lặp lại b3
* b4: if(k < n)

  * tìm thấy tại vị trí k
* b5: else							// k = n (phần tử cầm canh)

  * không tìm thấy phần tử có giá trị X
* b6: kết thúc

  * return 0;

hàm linearSearch được viết lại thành hàm linearSearch1 như sau:

    int LinearSearch1(T M[.], int n, T, X)

    {

    int k = 0;

    M[n] = X;

    while(M[k] != X)

    k ++;

    if(k < n)

    return (k);

    return (-1);

    }

phân tích thuật toán cải tiến:

* trường hợp tốt nhất khi phần tử đầu tiên của mảng có giá trị = X:

  * số phép gán : Gmin = 2
  * số phép so sánh: Smin = 1 + 1 = 2
* trường hợp xấu nhất khi không tìm thấy phần tử nào có giá trị = X:

  * số phép gán : Gmax = 2
  * số phép so sánh: Smax = (n + 1) + 1 = n + 2
* trung bình:

  * số phép gán : Gavg = 2
  * số phép so sánh: Savg = (2 + n + 2) : 2 = n/2 + 2
* như vậy, thời gian thực hiện phép gán không đáng kể thì thuật toán cải tiến sẽ chạy nhanh hơn (>) thuật toán nguyên thủy.
