#include "iostream"

// Time Complexity: O(n)
class SumOfNumbers {
    private:
        long long n, sum, count;

    public:
        SumOfNumbers(long long Number, long long Sum, long long Count) {
            n = Number;
            sum = Sum;
            count = Count;       
        }

        // Constructor
        SumOfNumbers() {
            n = 0;
            sum = 0;
            count = 1;
        }

        void InputNumber() {
            std::cout << "Enter number: "; std::cin >> n;
        }

        long long GetN() const { return n; }

        long long CalculateSum() {
            sum = (n * (n+1))/2;
            return sum;
        }
};

int main() {
    SumOfNumbers son;
    son.InputNumber();
    std::cout << "Sum of numbers from 1 to " << son.GetN() << " is: " << son.CalculateSum();
}