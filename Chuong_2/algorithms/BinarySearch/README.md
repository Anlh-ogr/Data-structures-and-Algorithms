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
