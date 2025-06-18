#include "iostream"

void InputTwoNumbers(long long &value_a, long long &value_b) {
    std::cout << "Enter number value a: "; std::cin >> value_a;
    std::cout << "Enter number value b: "; std::cin >> value_b;
}

long long SumTwoNumbers(long long &value_a, long long &value_b) {
    long long Sum = value_a + value_b;
    return Sum;
}

int main() {
    long long value_a, value_b;
    InputTwoNumbers(value_a, value_b);
    std::cout<<"Sum of Two numbers: " << SumTwoNumbers(value_a, value_b);
    return 0;
}