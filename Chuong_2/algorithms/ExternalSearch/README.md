# External Search - giải thuật tìm kiếm ngoại (Tìm kiếm trên tập tin)

##### Đặt vấn đề

Giả sử ta có một tập tin F lưu trữ n phần tử. Vấn đề đặt ra là có hay không phần tử có giá trị bằng X được lưu trữ trong tập tin F? Nếu có thì phần tử có giá trị bằng X là phần tử nằm ở vị trí nào trên tập tin F?

##### Tìm tuyến tính

* **Tư tưởng****:** lần lượt đọc các phần tử từ đầu tập tin F và so sánh với giá trị X cho đến khi đọc được phần tử có giá trị X hoặc đã đọc hết tập tin F thì kết thúc.
* **Thuật toán****:**

  * b1: k = 0
  * b2: rewind(F)				// về đầu tập tin F
  * b3: read(F, a)				// đọc một phần tử từ tập tin F
  * b4: k = k + sizeof(T)		// vị trí phần tử hiện hành(sau phần tử mới đọc)
  * b5: if a != X && !=(eof(F))
    * lặp lại b3
  * b6:  if(a = X)
    * tìm thấy tại vị trí k byte(s) tính từ đầu tập tin
  * b7: else
    * không tìm thấy phần tử có giá trị X
  * b8: kết thúc
* **Cài đặt thuật toán****:**

  * hàm FLinearSearch có prototype: long FLinearSearch(char *FileName, T X);
  * hàm thực hiện tìm kiếm phần tử có giá trị X trong tập tin có tên FileName. Nếu tìm thấy, hàm trả về một số nguyên có giá trị từ 0 đến filelength(FileName) là vị trí tương ứng của phần tử tìm thấy so với đầu tập tin(tính bằng byte). Trong trường hợp ngược lại, hoặc có lỗi khi thao tác trên tập tin hàm trả về giá trị -1(không tìm thấy hoặc lỗi thao tác trên tập tin). Nội dung của hàm như sau:
  * long FLinearSearch(char *FileName, T X)
  * {
    * FILE *Fp;
    * Fp = fopen(FileName, "rb");
    * if(Fp == NULL)
      * return(-1);
    * long k = 0;
    * T a;
    * int SOT = sizeof(T);
    * while (!feof(Fp))
    * {
      * if(fread(&a, SOT, 1, Fp) == 0)
        * break;
      * k = k + SOT;
      * if(a == X)
        * break;
    * }
    * fclose(Fp);
    * if(a == X)
      * return(k - SOT);
    * return(-1);
  * }
* **Phân tích thuật toán:**

  * trường hợp tốt nhất khi phần tử đầu tiên của tập tin có giá trị = X:

    * số phép gán:  Gmin = 1 + 2 = 3
    * số phép so sánh: Smin = 2 + 1 = 3
    * số lần đọc tập tin: Dmin = 1
  * trường hợp xấu nhất khi không tìm thấy phần tử nào có giá trị = X:

    * số phép gán:  Gmax = n + 2
    * số phép so sánh: Smax = 2n + 1
    * số lần đọc tập tin: Dmax = n
  * trung bình:

    * số phép gán:  Gavg = 1/2(n + 5)
    * số phép so sánh: Savg = (3 + 2n + 1) : 2 = n + 2
    * số lần đọc tập tin: Davg = 1/2(n + 1)

##### Tìm kiếm theo chỉ mục(Index Search)

Như ta đã biết, mỗi phần tử dữ liệu được lưu trữ trong tập tin dữ liệu F thường có kích thước lớn, điều này cũng làm cho kích thước tập tin F cũng khá lớn. Vì vậy việc thao tác dữ liệu trực tiếp lên tập tin F sẽ trở nên lâu, chưa kể sự mất an toàn cho dữ liệu trên tập tin.

Để giải quyết vấn đề này, đi kèm theo một tập tin dữ liệu thường có thêm các tập tin chỉ mục(Index File) để làm nhiệm vụ điều khiển thứ tự truy xuất dữ liệu trên tập tin theo một khóa chỉ mục(Index key) nào đó.

Mỗi phần tử dữ liệu trong tập tin chỉ mục IDX gồm có 2 thành phần: khóa chỉ mục và Vị trí vật lý của phần tử dữ liệu có khóa chỉ mục tương ứng trên tập dữ liệu. Cấu trúc dữ liệu của các phần tử trong tập tin chỉ mục như sau:

    typedef	struct IdxElement

    {

    T		IdxKey;

    long		Pos;

    } IdxType;

Tậptin chỉ mục luôn luôn được sắp xếp theo thứ tự tăng của khóa chỉ mục. Việc tạo tập tin chỉ mục IDX sẽ được nghiên cứu ở Chap3, phần này, xem như ta đã có tập tin chỉ mục IDX để thao tác.

* **Tư tưởng:**
  * Lần lượt đọc các phần tử từ đầu tập tin IDX và so sánh thành phần khóa chỉ mục với giá trị X cho đến khi đọc được phần tử có giá trị khóa chỉ mục lớn hơn hoặc bằng X hoặc đã đọc hết tập tin IDX thì kết thúc.
  * Nếu tìm thấy thì ta đã có vị trí vật lý của phần tử dữ liệu trên tập tin dữ liệu F, khi đó chúng ta có thể truy cập trực tiếp đến vị trí này để đọc dữ liệu của phần tử tìm thấy.
* **Thuật toán:**
