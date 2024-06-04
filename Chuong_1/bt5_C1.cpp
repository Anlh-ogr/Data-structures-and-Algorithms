/*
    Xây dựng cấu trúc dữ liệu để lưu trữ trong bộ nhớ trong(RAM) của máy
    tính đa thức có bậc tự nhiên n (0<=n<=100) trên trường số thực(R)
                fn(x) = a0 + a1*x + a2*x^2 + ... + an*x^n
*/

// xây dựng cấu truc dữ liệu đa thức
/*
    Có thể sử dụng một cấu trúc struct để lưu trữ đa thức bậc n. 
    Cấu trúc này sẽ bao gồm các thành phần sau:
        degree: lưu trữ bậc của đa thức (int)
        coefficients: mảng lưu trữ các hệ số của đa thức (kiểu double).
                      kích thước = degree + 1
*/


// xây dựng giải thuật
#include <iostream>

#define Max_n 100

bool getDouble(double &x) {
    if(!(std::cin >> x)) {
        std::cout << "Loi: nhap sai dinh dang so thuc!\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        return false;
    }
    return true;
}

typedef struct Polynomial {
    int degree;
    double coefficients[Max_n + 1];
} Polynomial;

void inputPolynomial(Polynomial p) {
    std::cout << "Nhap bac cua da thuc: ";
    std::cin >> p.degree;

    if(!getDouble(p.degree) || p.degree < 0 || p.degree > Max_n) {
        std::cout << "Loi: bac cua da thuc phai la so nguyen duong <= 100\n";
        inputPolynomial(p);
        return;
    }
}

void outputPolynomial(Polynomial p) {
    for(int i = p.degree; i >= 0; i--) {
        if(p.coefficients[i] != 0) {
            if(i == 0)
                std::cout << p.coefficients[i];
            else if(i == 1)
                if(p.coefficients[i] > 0)
                    std::cout << p.coefficients[i] << "x + ";
                else
                    std::cout << p.coefficients[i] << "x - ";
            else
                if(p.coefficients[i] > 0)
                    std::cout << p.coefficients[i] << "x^" << i << " + ";
                else
                    std::cout << p.coefficients[i] << "x^" << i << " - ";
        }
    }
    std::cout << std::endl;
}

double evaluatePolynomial(Polynomial p, double x) {
    double result = 0;
    for(int i = p.degree; i >= 0; i--)
        result = result*x + p.coefficients[i];
    return result;
}

Polynomial addPolynomial(Polynomial p1, Polynomial p2) {
    Polynomial result;
    result.degree = std::max(p1.degree, p2.degree);
    for(int i = 0; i <= result.degree; i++)
        result.coefficients[i] = p1.coefficients[i] + p2.coefficients[i];

    return result;
}





























/* giải thích: 
- Sử dụng struct để tạo ra một kiểu dữ liệu mới có tên là Polynomial.
- degree lưu trữ bậc của đa thức, là một số nguyên từ 0 đến 100.
- coefficients là một mảng lưu trữ các hệ số của đa thức.
- Mảng này có kích thước tối đa là 101, đủ để lưu trữ đa thức bậc tối đa là 100.
- Kiểu dữ liệu của mảng là double để lưu trữ các số thực.*/