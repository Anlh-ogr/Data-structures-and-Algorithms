#include "iostream"

class OddOrEven {
    private:
        long long n;
    public:
        OddOrEven(long long number) { n = number; }

        OddOrEven() {n = 0;}

        void InputNumber() {
            std::cout << "Enter number: "; std::cin >> n;
        }

        long long CheckOddOrEven() {
            return (n%2==0)? 1 : 0;
        }
        
        void Print() {
            if (CheckOddOrEven() == 1)
                std::cout << "Even";
            else
                std::cout << "Odd";
        }
};

int main() {
    OddOrEven ooe;
    ooe.InputNumber();
    ooe.CheckOddOrEven();
    ooe.Print();

    return 0;
}