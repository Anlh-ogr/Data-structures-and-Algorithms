
    Xây dựng cấu trúc dữ liệu để lưu trữ trong bộ nhớ trong(RAM) của máy
    tính đa thức có bậc tự nhiên n (0<=n<=100) trên trường số thực(R)
                fn(x) = a0 + a1*x + a2*x^2 + ... + an*x^n

    Với cấu trúc dữ liệu đã xây dựng, trình bày thuật toán và thực hiện các việc sau:
        - 1 nhập, xuất các đa thức
        - 2 tính giá trị của đa thức tại một điểm x nào đó
        - 3 tính tổng, tích của hai đa thức


nhập  - n;
	  - mảng a[i];
      - x;

xuất - bậc n, giá trị của hàm số tại x, tổng đa thức a[i] và b[i], tích đa thức a[i] và b[i]

    - giá trị của hàm số tại x
       ví dụ: n = 4, a[i] = [3, 4, 6, 2, 8], x = 5
              fn(x) = a0 + a1x^1 + a2x^2 + a3x^3 + a4x^4
                    = 3  + 4*5   + 6*5^2 + 2*5^3 + 8*5^4
                    = 3  + 20    + 150   + 250   + 2000
                    = 2423

    - tổng đa thức a[i] và b[i]
        ví dụ: n = 3; a = [2, 3, 4, 5]; b = [1, 2, 3, 4]
               a[i] = 2 + 3x + 4x^2 + 5x^3
               b[i] = 1 + 2x + 3x^2 + 4x^3
     => a[i] + b[i] = 3 + 5x + 7x^2 + 9x^3

    - tích đa thức a[i] và b[i]
        ví dụ: n = 3; a = [2, 3, 4, 5]; b = [1, 2, 3, 4]
               a[i] = 2 + 3x + 4x^2 + 5x^3
               b[i] = 1 + 2x + 3x^2 + 4x^3
               => a[i] * b[i] = 2*1 + 2**2x + 2*3x^2 + 2*4x^3
                                    + 3x*1  + 3x*2x  + 3x*3x^2 + 3x*4x^3
                                            + 4x^2*1 + 4x^2*2x + 4x^2*3x^2 + 4x^2*4x^3
                                                     + 5x^3*1  + 5x^3*2x   + 5x^3*3x^2 + 5x^3*4x^3
                              = 2 + 4x + 6x^2 + 8x^3
                                  + 3x + 6x^2 + 9x^3 + 12x^4
                                       + 4x^2 + 8x^3 + 12x^4 + 16x^5
                                              + 5x^3 + 10x^4 + 15x^5 + 20x^6

                              = 2 + 7x + 19x^2 + 42x^3 + 33x^4 + 20x^5 + 20x^6



review code:
        Enter the first polynomial:
Enter the degree of the polynomial: 3
Enter the a0 coefficient: 2
Enter the a1 coefficient: 3
Enter the a2 coefficient: 4
Enter the a3 coefficient: 5
The polynomial is: 5x^3 + 4x^2 + 3x + 2

        Enter the second polynomial: 
Enter the degree of the polynomial: 4
Enter the a0 coefficient: 7
Enter the a1 coefficient: 6
Enter the a2 coefficient: 5
Enter the a3 coefficient: 4
Enter the a4 coefficient: 3
The polynomial is: 3x^4 + 4x^3 + 5x^2 + 6x + 7

        Enter the value of x: 3
The value of the first polynomial at x = 3 is: 182

The value of the second polynomial at x = 3 is: 421

The sum of the two polynomials is: 

The polynomial is: 3x^4 + 9x^3 + 9x^2 + 9x + 9

The product of the two polynomials is: 

The polynomial is: 15x^7 + 32x^6 + 50x^5 + 68x^4 + 82x^3 + 56x^2 + 33x + 14