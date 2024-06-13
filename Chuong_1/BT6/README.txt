Xây dựng cấu trúc dữ liệu để lưu trữ trong bộ nhớ trong(RAM) của máy
    tính đa thức có bậc tự nhiên n (0<=n<=100) trên trường số hữu tỉ(Q)
                fn(x) = a0/b0 + a1/b1*x + a2/b2*x^2 + ... + an/bn*x^n

    Với cấu trúc dữ liệu đã xây dựng, trình bày thuật toán và thực hiện các việc sau:
        - 1 nhập, xuất các đa thức
        - 2 tính giá trị của đa thức tại một điểm x nào đó
        - 3 tính tổng, tích của hai đa thức


nhập  - n;
	  - mảng a[i], b[i] (i = 0 -> n);
      - x;

xuất  - bậc n, giá trị của hàm số tại x, tổng đa thức, tích da thức

      - giá trị của hàm số tại x
        ví dụ: n = 4, a[i] = [1, 2, 3, 4], b[i] = [4, 3, 2, 1], x = 3
                fn(x) = a0/b0 + a1/b1*x + a2/b2*x^2 + a3/b3*x^3
                      = 1/4   + 2/3*3   + 3/2*3^2   + 4/1*3^3
                      = 1/4   + 2       + 9         + 108
                      = 120.25


      - tổng đa thức a[i]/b[i] + c[i]/d[i]
        ví dụ: n = 4, a[i] = [1, 2, 3, 4], b[i] = [4, 3, 2, 1], c[i] = [2, 3, 4, 5], d[i] = [3, 2, 1, 4]
                fn(x) = a0/b0 + a1/b1*x + a2/b2*x^2 + a3/b3*x^3
                      = 1/4   + 2/3*x   + 3/2*x^2   + 4/1*x^3

                fn(x) = c0/d0 + c1/d1*x + c2/d2*x^2 + c3/d3*x^3
                      = 2/3   + 3/2*x   + 4/1*x^2   + 5/4*x^3

                fn(x) = a0/b0+c0/d0 + a1/b1*x+c1/d1*x + a2/b2*x^2+c2/d2*x^2 + a3/b3*x^3+c3/d3*x^3
                      = 1/4  +2/3   + 2/3*x  +3/2*x   + 3/2*x^2  +4/1*x^2   + 4/1*x^3  +5/4*x^3
                => a[i]/b[i] + c[i]/d[i] = 3/4 + 5/3*x + 5/2*x^2 + 9/4*x^3  


      - tích đa thức a[i]/b[i] * c[i]/d[i]
        ví dụ: n = 4, a[i] = [1, 2, 3, 4], b[i] = [4, 3, 2, 1], c[i] = [2, 3, 4, 5], d[i] = [3, 2, 1, 4]
                fn(x) = a0/b0 + a1/b1*x + a2/b2*x^2 + a3/b3*x^3
                      = 1/4   + 2/3*x   + 3/2*x^2   + 4/1*x^3

                fn(x) = c0/d0 + c1/d1*x + c2/d2*x^2 + c3/d3*x^3
                      = 2/3   + 3/2*x   + 4/1*x^2   + 5/4*x^3
                
                fn(x) = a0/b0*c0/d0 + a1/b1*c1/d1*x + a2/b2*c2/d2*x^2 + a3/b3*c3/d3*x^3
                      = 1/4  * 2/3  + 2/3*3/2*x     + 3/2*4/1*x^2     + 4/1*5/4*x^3
                      = 2/12        + 6/6*x         + 12/2*x^2        + 20/4*x^3
                      = 1/6         + x             + 6*x^2           + 5*x^3


demo code:
                  Enter the first polynomial: 
Enter the degree of the polynomial: 2
Enter the a0 coefficient: 3                     Enter the b0 coefficient: 2
Enter the a1 coefficient: 2                     Enter the b1 coefficient: 3
Enter the a2 coefficient: 1                     Enter the b2 coefficient: 4
      => The polynomial is: 1/4x^2 + 2/3x + 3/2

                  Enter the second polynomial: 
Enter the degree of the polynomial: 3
Enter the a0 coefficient: 7                     Enter the b0 coefficient: 3
Enter the a1 coefficient: 6                     Enter the b1 coefficient: 4
Enter the a2 coefficient: 5                     Enter the b2 coefficient: 5
Enter the a3 coefficient: 4                     Enter the b3 coefficient: 6
      => The polynomial is: 4/6x^3 + 5/5x^2 + 6/4x + 7/3

                  Enter the value of x: 2
The value of the first polynomial at x = 2 is: 3.83333

The value of the second polynomial at x = 2 is: 14.6667

The sum of the two polynomials is:        => The polynomial is: 0.666667x^3 + 1.25x^2 + 2.16667x + 3.83333

The product of the two polynomials is:    => The polynomial is: 0.166667x^5 + 0.694444x^4 + 2.04167x^3 + 3.08333x^2 + 3.80556x + 3.5