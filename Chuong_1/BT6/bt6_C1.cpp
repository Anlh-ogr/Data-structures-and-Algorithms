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
                if (p.coefficients2[i] == 1)
                    std::cout << p.coefficients1[i];
                else
                    std::cout << p.coefficients1[i] << "/" << p.coefficients2[i];
            else if (i == 1)
                if (p.coefficients2[i] == 1)
                    std::cout << p.coefficients1[i] << "x" << (p.coefficients1[i] > 0 ? " + " : " ");
                else
                    std::cout << p.coefficients1[i] << "/" << p.coefficients2[i] << "x" << (p.coefficients1[i] > 0 ? " + " : " ");
            else
                if (p.coefficients2[i] == 1)
                    std::cout << p.coefficients1[i] << "x^" << i << (p.coefficients1[i] > 0 ? " + " : " ");
                else
                    std::cout << p.coefficients1[i] << "/" << p.coefficients2[i] << "x^" << i << (p.coefficients1[i] > 0 ? " + " : " ");
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

