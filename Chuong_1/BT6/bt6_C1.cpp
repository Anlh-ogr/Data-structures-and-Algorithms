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
    for (int i = p.degree; i >= 0; i--) {
        if (p.coefficients[i] != 0) {
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
        }
    }
}

double evaluatePolynomial(const Polynomial &p, double x) {
    double result = 0;
    for (int i = p.degree; i >= 0; i--) {
        result += p.coefficients[i] * pow(x, i);
    }
    return result;
}
