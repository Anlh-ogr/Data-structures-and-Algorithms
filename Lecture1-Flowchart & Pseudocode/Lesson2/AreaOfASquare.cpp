#include "iostream"

void InputSideOfSquare(long long &side_a);

long long AreaOfSquare(long long &side_a);

int main() {
    long long side_a;
    InputSideOfSquare(side_a);
    std::cout << "Area of Square: " << AreaOfSquare(side_a);
    return 0;
}

void InputSideOfSquare(long long &side_a) {
    std::cout << "Enter side of Square: "; std::cin >> side_a;
}

long long AreaOfSquare(long long &side_a) {
    long long area = side_a * side_a;
    return area;
}