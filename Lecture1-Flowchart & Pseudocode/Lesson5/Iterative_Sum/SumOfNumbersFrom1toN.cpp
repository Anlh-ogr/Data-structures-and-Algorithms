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

        void CalculateSum() {
            // Gan lai constructor
            sum = 0;
            for (count = 1; count <= n; count++)
                sum += count;
            
            std::cout << "Sum of numbers from 1 to " << n << " is: " << sum;
        }

};

int main() {
    SumOfNumbers son;
    son.InputNumber();
    son.CalculateSum();
}