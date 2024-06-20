Đặt vấn đề: giả sử chúng ta có một mảng M (array_M[a,b,...,n]) gồm n phần tử. Vấn đề đặt ra là có hay không phần tử có giá trị X trong mảng M? Nếu có thì phần tử có giá trị X làm phần tử thứ mấy trong mảng M?

Tìm tuyến tính(Linear Search) còn được gọi là Thuật toán tìm kiếm tuần tự(Sequential Search)

- Giải quyết vấn đề(tư tưởng): lần lượt so sánh các phần tử mảng M với giá trị X bất đầu từ phần tử ở vị trí đầu tiên trong mảng M cho đến khi tìm đến được phần tử có giá trị X hoặc đã duyệt qua hết tất cả các phần tử trong mảng M thì kết thúc.
- Thuật toán:
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
- Cài đặt thuật toán
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
