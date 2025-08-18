#include <iostream>
#include <thread>
#include <chrono>
#include <string>

class PositiveOrNegative {
    private:
        int num = 0, count = 1;

    public:
        PositiveOrNegative( int n = 0, int c = 1 ) : num(n), count(c) {}

        void Pos_Neg() {
            // Ternary statement
            (num >= 0) ? std::cout << "Positive" : std::cout << "Negative";
        }

        void Slow(const std::string& message, int delay_ms = 1000) {
            for (char c : message) {
                std::cout << c << std::flush;   // Print character immediately
                std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms)); // Delay
            }
            std::cout << std::endl;
        }

        void Lop() {
            while (count <= num) {
                std::string msg = "Bios " + std::to_string(count) + " running...";
                Slow(msg, 30);
                count++;
            }
        }
};

int main() {
    PositiveOrNegative pon(45); // Create an instance of PositiveOrNegative class
    pon.Pos_Neg();
    std::cout << std::endl;
    pon.Lop();
    std::cout << "All Bios running successfully!" << std::endl;
    
    return 0;
}