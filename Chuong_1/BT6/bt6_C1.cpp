/*
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
*/




#include <iostream>
#include <cmath>

#define Max_n 100

bool getDouble(double &x) {
    std::cin >> x;
    if(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::cout << "Invalid input. Please try again: ";
        return false;
    }
    std::cin.ignore(32767, '\n');
    return true;
}

struct Polynomial {
    int degree;
    double coefficients1[Max_n + 1];
    double coefficients2[Max_n + 1];
};


// input a[i]; b[i]
void inputPolynomial(Polynomial &p) {
    std::cout << "Enter the degree of the polynomial: ";
    if(!(std::cin >> p.degree) || p.degree < 0 || p.degree > Max_n) {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        inputPolynomial(p);
        return;
    }
    for(int i = 0; i <= p.degree; i++) {
        std::cout << "Enter the a" << i << " coefficient: ";
        if(!(std::cin >> p.coefficients1[i])) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Invalid input. Please try again." << std::endl;
            i--;
        }
        // a[i] = 0 -> n
    }
    for(int i = 0; i <= p.degree; i++) {
        std::cout << "Enter the b" << i << " coefficient: ";
        if(!(std::cin >> p.coefficients2[i])) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Invalid input. Please try again." << std::endl;
            i--;
        }
        // b[i] = 0 -> n
    }
}
// output a[i]/b[i] = a[i]/b[i]*x^i
void outputPolynomial(const Polynomial &p) {
    std::cout << "The polynomial is: ";
    for (int i = p.degree; i >= 0; i--)
        if (p.coefficients1[i] != 0)
            if (i == 0)
                std::cout << p.coefficients1[i] << "/" << p.coefficients2[i];
            else if(i == 1)
                if(p.coefficients1[i] > 0)
                    std::cout << p.coefficients1[i] << "/" << p.coefficients2[i] << "x + ";
                else
                    std::cout << p.coefficients1[i] << "/" << p.coefficients2[i] << "x ";
            else
                if(p.coefficients1[i] > 0)
                    std::cout << p.coefficients1[i] << "/" << p.coefficients2[i] << "x^" << i << " + ";
                else
                    std::cout << p.coefficients1[i] << "/" << p.coefficients2[i] << "x^" << i << " ";
    std::cout << std::endl;
}

// evaluate a[i]/b[i] at x
double evaluatePolynomial(const Polynomial &p, double x) {
    double result = 0;
    for (int i = 0; i <= p.degree; i++)
        result += p.coefficients1[i] / p.coefficients2[i] * std::pow(x, i);
    return result;
}

// sum a[i]/b[i] + c[i]/d[i]
Polynomial addPolynomials(const Polynomial &p1, const Polynomial &p2) {
    Polynomial result;
    result.degree = std::max(p1.degree, p2.degree);
    for (int i = 0; i <= result.degree; i++) {
        result.coefficients1[i] = (i <= p1.degree ? p1.coefficients1[i] : 0) / (i <= p1.degree ? p1.coefficients2[i] : 1) + (i <= p2.degree ? p2.coefficients1[i] : 0) / (i <= p2.degree ? p2.coefficients2[i] : 1);
        result.coefficients2[i] = 1;
    }
    return result;
}

// multiply a[i]/b[i] * c[i]/d[i]
/*
    tích đa thức a[i]/b[i] * c[i]/d[i]
    ví dụ: n = 4, a[i] = [1, 2, 3, 4], b[i] = [4, 3, 2, 1], c[i] = [2, 3, 4, 5], d[i] = [3, 2, 1, 4]
            fn(x) = a0/b0 + a1/b1*x + a2/b2*x^2 + a3/b3*x^3
                = 1/4   + 2/3*x   + 3/2*x^2   + 4/1*x^3

            fn(x) = c0/d0 + c1/d1*x + c2/d2*x^2 + c3/d3*x^3
                    = 2/3   + 3/2*x   + 4/1*x^2   + 5/4*x^3
*/
Polynomial multiplyPolynomials(const Polynomial &p1, const Polynomial &p2) {
    Polynomial result;
    result.degree = p1.degree + p2.degree;
    for (int i = 0; i <= result.degree; i++) {
        result.coefficients1[i] = 0;
        result.coefficients2[i] = 1;
    }

    for (int i = 0; i <= p1.degree; i++) {
        for (int j = 0; j <= p2.degree; j++) {
            result.coefficients1[i + j] += p1.coefficients1[i] / p1.coefficients2[i] * p2.coefficients1[j] / p2.coefficients2[j];
            result.coefficients2[i + j] = 1;
        }
    }
    return result;
}


int main() {
    Polynomial p1, p2;
    std::cout << "Enter the first polynomial: " << std::endl;
    inputPolynomial(p1);
    outputPolynomial(p1);

    std::cout << "Enter the second polynomial: " << std::endl;
    inputPolynomial(p2);
    outputPolynomial(p2);

    double x;
    std::cout << "Enter the value of x: ";
    getDouble(x);
    std::cout << "The value of the first polynomial at x = " << x << " is: " << evaluatePolynomial(p1, x) << std::endl;
    std::cout << "The value of the second polynomial at x = " << x << " is: " << evaluatePolynomial(p2, x) << std::endl;

    Polynomial sum = addPolynomials(p1, p2);
    std::cout << "The sum of the two polynomials is: " << std::endl;
    outputPolynomial(sum);

    Polynomial product = multiplyPolynomials(p1, p2);
    std::cout << "The product of the two polynomials is: " << std::endl;
    outputPolynomial(product);

    return 0;
}

