#include <iostream>
#include <cmath>

#define Max_n 100

bool getDouble(double &x) {
    std::cin >> x;
    if (std::cin.fail()) {
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
    double coefficients[Max_n + 1];
};

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
        if(!(std::cin >> p.coefficients[i])) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Invalid input. Please try again." << std::endl;
            i--;
        }
    }
}

void outputPolynomial(const Polynomial &p) {
    std::cout << "The polynomial is: ";
    for (int i = p.degree; i >= 0; i--)
        if (p.coefficients[i] != 0)
            if (i == 0)
                std::cout <<p.coefficients[i];
            else if(i == 1)
                if(p.coefficients[i] > 0)
                    std::cout << p.coefficients[i] << "x + ";
                else
                    std::cout << p.coefficients[i] << "x ";
            else
                if(p.coefficients[i] > 0)
                    std::cout << p.coefficients[i] << "x^" << i << " + ";
                else
                    std::cout << p.coefficients[i] << "x^" << i << " ";
    std::cout << std::endl;
}

double evaluatePolynomial(const Polynomial &p, double x) {
    double result = 0;
    for (int i = 0; i <= p.degree; i++)
        result += p.coefficients[i] * std::pow(x, i);
    return result;
}

Polynomial addPolynomials(const Polynomial &p1, const Polynomial &p2) {
    Polynomial result;
    result.degree = std::max(p1.degree, p2.degree);
    for (int i = 0; i <= result.degree; i++)
        result.coefficients[i] = (i <= p1.degree ? p1.coefficients[i] : 0) + (i <= p2.degree ? p2.coefficients[i] : 0);
    return result;
}

Polynomial multiplyPolynomials(const Polynomial &p1, const Polynomial &p2) {
    Polynomial result;
    result.degree = p1.degree + p2.degree;
    for (int i = 0; i <= result.degree; i++)
        result.coefficients[i] = 0;
    
    for (int i = 0; i <= p1.degree; i++)
        for (int j = 0; j <= p2.degree; j++)
            result.coefficients[i + j] += p1.coefficients[i] * p2.coefficients[j];
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



/* giải thích: 
    - Sử dụng struct để tạo ra một kiểu dữ liệu mới có tên là Polynomial.
    - degree lưu trữ bậc của đa thức, là một số nguyên từ 0 đến 100.
    - coefficients là một mảng lưu trữ các hệ số của đa thức.
    - Mảng này có kích thước tối đa là 101, đủ để lưu trữ đa thức bậc tối đa là 100.
    - Kiểu dữ liệu của mảng là double để lưu trữ các số thực.

    thuật toán giải chi tiết ở File README.txt
*/