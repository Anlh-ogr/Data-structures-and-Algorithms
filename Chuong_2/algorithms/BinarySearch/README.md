# Binary Search - Tìm kiếm nhị phân

##### So sánh với Linear Search(tìm kiếm tuyến tính):

* Thuật toán tìm tuyến tính tỏ ra đơn giản và thuận tiện trong trường hợp số phần tử trong dãy không lớn. Tuy nhiên, khi số phần tử của dãy lớn hơn, ví dụ: khi tìm kiếm tên một khách hàng trong một danh bạ điện thoại của một thành phố lớn theo thuật toán tiềm kiếm tuần tự -> rất mất thời gian.
* Trong thực tế, thông thường các phần tử của dãy đã có 1 thứ tự, do vậy thuật toán tìm kiếm nhị phân sẽ rút ngắn đáng kể thời gian tìm kiếm trên dãy đã có thứ tự.
* Trong thuật toán này, giả sử các phần tử trong dãy đã có thứ tự tăng(không giảm dần), tức là các phần tử đứng trước luôn có giá trị nhỏ hơn hoặc bằng (không lớn hơn) phần tử đứng sau nó.
* Khi đó, nếu x nhỏ hơn giá trị phần tử đứng ở giữa dãy (M[mid]) thì x chỉ có thể tìm thấy ở nữa đầu của dãy và ngược lại, nếu x lớn hơn phần tử M[mid] thì x chỉ có thể tìm thấy ở nửa sau của dãy.

##### Tư tưởng:

* phạm vi tìm kiếm ban đầu của ta là phần tử đầu tiên của dãy(First = 1) cho đến phần tử cuối cùng của dãy(Last = n).
* so sánh giá trị X với giá trị phần tử đứng ở giữa của dãy M là M[mid].
* nếu X = M[mid]: tìm thấy.
* nếu X < M[mid]: rút ngắn phạm vi tìm kiếm về nữa đầu của dãy M(Last = mid - 1).
* nếu X > M[mid]: rút ngắn phạm vi tìm kiếm về nữa sau của dãy M(First = mid + 1).
* lặp lại quá trình này cho đến khi tìm thấy phần tử có giá trị X trong phạm vi tìm kiếm của chúng ta không còn nữa (First > Last)

##### Thuật toán đệ quy(Recursion Algorithm):

    b1: First = 1

    b2: Last = n

    b3: if(First > Last)				// hết phạm vi tìm kiếm

    b3.1: không tìm thấy

    b3.2: thực hiện Bkt

    b4: mid = (First + Last)/2

    b5: if(X = M[mid])

    b5.1: tìm thấy tại vị trí mid

    b5.2: thực hiện Bkt

    b6: if(X < M[mid])

    tìm đệ quy từ First đến Last = mid - 1

    b7: if(X > M[mid])

    tìm đệ quy từ First = mid + 1 đến Last

    Bkt: kết thúc

##### Cài đặt thuật toán đệ quy:

* hàm binarySearch có prototype:
  * int BinarySearch (T M[.], int n, T, X);
* hàm thực hiện việc tìm kiếm phần tử có giá trị X trong mảng M có n phần tử đã có thứ tự tăng. Nếu tìm thấym hàm trả về một số nguyên có giá trị từ 0 đến n-1 là vị trí tương ướng của phần tử tìm thấy.
* ngược lại, hàm trả về giá trị -1(not found).
* hàm binarySearch sử dụng hàm đệ quy RecBinarySearch có prototype:
  * int RecBinarySearch(T M[.], int First, int Last, T, X);
* hàm RecBinarySearch thực hiện việc tìm kiếm phần tử có giá trị X trên mảng M trong phạm vi phần tử thứ First đến Last là vị trí tương ứng của phần tử tìm thấy .
* trong trường hợp ngược lại, hàm trả về giá trị -1(not found).
* nội dung các hàm như sau:
  * int RecBinarySearch(T M[.], int First, int Last, T, X)
  * {
    * if(First > Last)

      * return (-1);
    * int mid = (First + Last)/2;
    * if(X == M[mid])

      * return (mid);
    * if(X < M[mid])

      * return (RecBinarySearch(M, First, mid - 1, X));
    * else

      * return (RecBinarySearch(M, mid + 1, Last,  X));
  * }
  * ===================================
  * int BinarySearch(T M[.], int n, T, X)
  * {
    * return (RecBinarySearch(M, 0, n - 1, X));
  * }

##### Phân tích thuật toán đệ quy:

* trường hợp tốt nhất khi phần tử ở giữa của mảng có giá trị bằng X:

  * số phép gán: Gmin = 1
  * số phép so sánh: Smin = 2
* trường hợp xấu nhất khi không tìm thấy phần tử nào có giá trị bằng X:

  * số phép gán: Gmax = log2N + 1
  * số phép so sánh: Smax = 3log2N + 1
* trung bình:

  * số phép gán: Gavg = 1/2log2N + 1
  * số phép so sánh: Smax = 1/2(3log2N + 3)

##### Thuật toán không đệ quy(Non-Recursion Algorithm)

    b1: First = 1

    b2: Last = n

    b3: if(First > Last)

    b3.1: không tìm thấy

    b3.2: thực hiện Bkt

    b4: mid = (First + Last)/2

    b5: if(X = M[mid])

    b5.1: tìm thấy tại vị trí mid

    b5.2: thực hiện Bkt

    b6: if(X < M[mid])

    b6.1: Last = mid - 1

    b6.2: lặp lại b3

    b7: if(X > M[mid])

    b7.1: First = mid + 1

    b7.2: lặp lại b3

    Bkt: kết thúc

##### Cài đặt thuật toán không đệ quy:

* hàm NRecBinarySearch có prototype: int NRecBinarySearch (T M[.], int n, T, X);
* hàm thực hiện việc tìm kiếm phần tử có giá trị X trong mảng M có n phàn tử đã có thứ tự tăng. Nếu tìm thấy, hàm trả về một số nguyên có giá trị từ 0 đến n-1 là vị trí tương ứng của phần tử tìm thấy. Trong trường hợp ngược lại, hàm trở về giá trị -1(not found). Nội dung của hàm NRecBinarySearch như sau:
  * int NRecBinarySearch(T M[.], int n, T, X)
  * {
    * int First = 0;
    * int Last = n - 1;
    * while (First <= Last)
    * {
      * int Mid = (First + Last)/2;
      * if(X == M[mid])
        * return(mid);
      * if(X < M[mid])
        * Last = mid - 1;
      * else
        * First = mid + 1;
    * }
    * return(-1);
  * }

##### Phân tích thuật toán không đệ quy:

* trường hợp tốt nhất khi phần tử ở giữa của mảng có giá trị bằng X:
  * số phép gán: Gmin = 3
  * số phép so sánh: Smin = 2
* trường hợp xấu nhất khi không tìm thấy phần tử nào có giá trị bằng X:
  * số phép gán: Gmax = 2log2N + 4
  * số phép so sánh: Smax = 3log2N + 1
* trung bình:
  * số phép gán: Gavg = log2N + 3.5
  * số phép so sánh: Smax = 1/2(3log2N + 3)

##### Ví dụ:

giả sử có dãy M gồm 10 phần tử có khóa như sau (n = 10)

* M[10] = {1, 3, 4, 5, 8, 15, 17, 22, 25, 30}

trước tiên ta thực hiện tìm kiếm phần tử có giá trị X = 5(tìm thấy):

| lần lặp | First | Last | First > Last | Mid | M[mid] | X = M[mid] | X < M[mid] | X > M[mid] |
| :-------: | :---: | :--: | :----------: | :-: | :----: | :--------: | :--------: | :--------: |
| ban đầu |   0   |  9  |    false    |  4  |   8   |   false   |    true    |   false   |
|     1     |   0   |  3  |    false    |  1  |   3   |   false   |   false   |    true    |
|     2     |   2   |  3  |    false    |  2  |   4   |   false   |   false   |    true    |
|     3     |   3   |  3  |    false    |  3  |   5   |    true    |            |            |

kết quả sau 3 lần lặp(đệ quy) thuật toán kết thúc.

thực hiện tìm kiếm phần tử có giá trị X = 7(not found)

| Lần lặp | First | Last | First > Last | Mid | M[mid] | X = M[mid] | X < M[mid] | X > M[mid] |
| :-------: | :---: | :--: | :----------: | :-: | :----: | :--------: | :--------: | :--------: |
| ban đầu |   0   |  9  |    false    |  4  |   8   |   false   |    true    |   false   |
|     1     |   0   |  3  |    false    |  1  |   3   |   false   |   false   |    true    |
|     2     |   2   |  3  |    false    |  2  |   4   |   false   |   false   |    true    |
|     3     |   3   |  3  |    false    |  3  |   5   |   false   |   false   |    true    |
|     4     |   4   |  3  |     true     |    |        |            |            |            |

kết quả sau 4 lần lặp(đệ quy) thuật toán kết thúc.

* lưu ý:
  * thuật toán tìm nhị phân chỉ có thể vận dụng trong trường hợp dãy/mảng đã có thứ tự. Trong trường hợp tổng quát chúng ta chỉ có thể áp dụng thuật toán tìm kiếm tuần tự(Sequential Search).
  * các thuật toán đệ quy có thể ngắn gọn song tốn kém bộ nhớ để ghi nhận mã lệnh chương trình(mỗi lần gọi đệ quy) khi chạy chương trình, do vậy có thể làm cho chương trình chạy chậm lại. Trong thực tế, khi viết chương trình nếu có thể ta nên sử dụng thuật toán không đệ quy.
