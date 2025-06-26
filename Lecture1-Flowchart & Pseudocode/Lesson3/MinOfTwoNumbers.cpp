#include "iostream"

class MinOfTwoNumbers {
    private:
        long long value_a, value_b;

    public:
        MinOfTwoNumbers(long long a, long long b) {
            value_a = a;
            value_b = b;
        }

        // Constructor
        MinOfTwoNumbers() {
            value_a = 0;    // initialize to default values
            value_b = 0;    // initialize to default values
        }

        void InputTwoNumber() {
            std::cout << "Enter value a: "; std::cin >> value_a;
            std::cout << "Enter value b: "; std::cin >> value_b;
        }

        long long FindMin() {
            return (value_a < value_b) ? value_a: value_b;
        }

        long long FindMin2() {
            long long fm2 = value_a - value_b; 
            return (fm2 > 0) ? value_b : value_a; 
        }
};

int main() {
    MinOfTwoNumbers motn1;
    motn1.InputTwoNumber();
    std::cout << "Min: " << motn1.FindMin() << std::endl;

    MinOfTwoNumbers motn2;
    motn2.InputTwoNumber();
    std::cout << "Min: " << motn2.FindMin2() << std::endl;
    return 0;
}