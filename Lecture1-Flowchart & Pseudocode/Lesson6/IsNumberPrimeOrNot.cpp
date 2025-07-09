#include "iostream"
#include "cmath"
#include "random"   // for random number generation
#include "string"   // for std::string and std::string::center
#include "cstdlib"  // for rand() and srand()
#include "ctime"    // for seeding random number generator
#include "chrono"   // for measuring execution time (runtime)
#include "iomanip"  // for setw

class PrimeOrNonPrime{
    private:
        long long *n;   // store number

        // Function for Miller-Rabin Algorithm
        /* @base: the base to be used in the modular exponentiation
           @exp: the exponent
           @mod: the modulus
        */
        long long PowerMod(long long base, long long exp, long long mod) {
            long long result = 1;
            base %= mod;
            while (exp > 0) {
                if (exp % 2 == 1)   // odd exponent
                    result = (result * base) % mod;
                exp = exp >> 1;     // square-and-multiply exponentiation
                base = (base * base) % mod;
            }
            return result;
        }

        // Function to check if a number is prime using Miller-Rabin test
        /* @d: the value (n-1) to be factored
           @base: the base to be used in the test
           @x: the result of the modular exponentiation
        */
        bool Miller(long long d, long long base) {
            long long x = PowerMod(base, d, *n);    // a^d % n
            if (x == 1 || x == *n - 1)
                return true;
            while (d != *n - 1) {
                x = (x * x) % *n;   // square the result
                d *= 2;             // double d until it reaches n-1 
                if (x == 1)
                    return false;
                if (x == *n - 1)
                    return true;
            }
            return false;
        }

    public:
        // Constructor with Pointer
        PrimeOrNonPrime() {
            n = new long long(0);   // setup default value
        }

        // Destructor to release memory
        ~PrimeOrNonPrime() { delete n; }

        void InputNumber(long long value) { *n = value; }

        bool BruteForce(double timeLimit = 5.0) {  // 5000 ms = 5 seconds
            auto start = std::chrono::high_resolution_clock::now();
            if (*n < 2)
                return false;
            for (long long i=2; i < *n; ++i) {
                if (*n % i == 0)
                    return false;
                // break if time exceeds 5 seconds
                auto now = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double, std::milli> elapsed = now - start;
                if (elapsed.count() > timeLimit)
                    throw std::runtime_error("TimeOut");
            }
            return true;
        }

        bool SquareRoot(double timeLimit = 5.0) {   // 5000 ms = 5 seconds
            auto start = std::chrono::high_resolution_clock::now();
            if (*n < 2)
                return false;
            for (long long i = 2; i * i <= *n; ++i) {
                if (*n % i == 0)
                    return false;
                // break if time exceeds 5 seconds
                auto now = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double, std::milli> elapsed = now - start;
                if (elapsed.count() > timeLimit)
                    throw std::runtime_error("TimeOut");
            }
            return true;
        }

        // Miller-Rabin Algorithm
        /* @numRound: number of rounds to perform the test, default is 5
           This function uses the Miller-Rabin primality test to determine if n is prime.
           It performs numRound iterations with random bases to increase accuracy.
           Returns true if n is probably prime, false if it is composite.
           @oddPart: the odd part of n-1, which is used in the test
           @base: a random base chosen for the test, in the range [2, n-2]
        */
        bool MillerRabin(int rounds = 5) {
            if (*n < 2 || (*n > 2 && *n % 2 == 0))
                return false;
            if (*n == 2 || *n == 3)
                return true;
            
            // Factor n-1 into d * 2^r
            long long oddPart = *n - 1;
            while (oddPart % 2 == 0)
                oddPart /= 2;

            // Perform rounds iterations of the Miller-Rabin test
            std::random_device rd;
            std::mt19937_64 gen(rd());
            std::uniform_int_distribution<long long> dis(2, *n - 2); // random base in [2, n-2]
            
            for (int i = 0; i < rounds; ++i) {
                long long base = dis(gen);
                if (!Miller(oddPart, base))
                    return false;
            }
            return true;
        }

        // Wrapper function for Brute and SquareRoot methods
        bool BruteForce5s() { return BruteForce(5.0); }
        bool SquareRoot5s() { return SquareRoot(5.0); }
        bool MillerRabin5rounds() { return MillerRabin(5); }

        // Function to measure the runtime of a method
        double Runtime(bool (PrimeOrNonPrime::*method)()) {
            auto start = std::chrono::high_resolution_clock::now();
            // use try-catch to handle potential timeouts
            try { (this->*method)(); } // call the method
            catch (const std::runtime_error &e) {
                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double, std::milli> duration = end - start;
                return 9999.0; // return a large value to indicate timeout
            }
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> duration = end - start;

            return duration.count();
        }
};

int main() {
    PrimeOrNonPrime ponp;

    long long numbers[] = {29, 30, 9223372036854775783};

    // Define the width for table formatting
    const int widthHeader = 35;
    const int widthHeader2 = 16;
    const int widthHeader3 = 8;
    const int widthUnderline = 58;

    const int widthResult = 14;

    // Table header
    std::cout << std::left
              << std::setw(widthHeader) << "| Methods     | "
              << std::setw(widthHeader) << "Brute Force | "
              << std::setw(widthHeader) << "Square Root | "
              << std::setw(widthHeader) << "Miller-Rabin |" << "\n";
    std::cout << std::string(widthUnderline, '-') << "\n";

    // Loop through each number and test primality
    for (long long number : numbers) {
        ponp.InputNumber(number);
    
        // Lưu kết quả và thời gian
        bool bruteResult = false, sqrtResult = false, millerResult = false;
        bool bruteTimeout = false, sqrtTimeout = false, millerTimeout = false;
    
        double BruteTime = 0, SqrtTime = 0, MillerTime = 0;
    
        // Brute Force
        try {
            auto start = std::chrono::high_resolution_clock::now();
            bruteResult = ponp.BruteForce(5.0);
            auto end = std::chrono::high_resolution_clock::now();
            BruteTime = std::chrono::duration<double, std::milli>(end - start).count();
            if (BruteTime > 5000.0) bruteTimeout = true;
        } catch (...) {
            bruteTimeout = true;
            BruteTime = 9999.0;
        }
    
        // Square Root
        try {
            auto start = std::chrono::high_resolution_clock::now();
            sqrtResult = ponp.SquareRoot(5.0);
            auto end = std::chrono::high_resolution_clock::now();
            SqrtTime = std::chrono::duration<double, std::milli>(end - start).count();
            if (SqrtTime > 5000.0) sqrtTimeout = true;
        } catch (...) {
            sqrtTimeout = true;
            SqrtTime = 9999.0;
        }
    
        // Miller-Rabin
        try {
            auto start = std::chrono::high_resolution_clock::now();
            millerResult = ponp.MillerRabin(20);
            auto end = std::chrono::high_resolution_clock::now();
            MillerTime = std::chrono::duration<double, std::milli>(end - start).count();
            if (MillerTime > 5000.0) millerTimeout = true;
        } catch (...) {
            millerTimeout = true;
            MillerTime = 9999.0;
        }
    
        // In bảng
        std::cout << std::setw(widthHeader) << "| Number      |"
                  << std::setw(widthHeader3) << number << " |\n";

        std::cout << std::setw(widthResult) << "| Result      |"
                  << std::setw(widthResult) << (bruteTimeout ? "Timeout" : (bruteResult ? "Prime" : "Non-Prime"))
                  << std::setw(widthResult) << (sqrtTimeout ? "Timeout" : (sqrtResult ? "Prime" : "Non-Prime"))
                  << std::setw(widthResult) << (millerTimeout ? "Timeout" : (millerResult ? "Prime" : "Non-Prime")) << "|\n";

        std::cout << std::setw(widthResult) << "| Runtime (ms)|"
                  << std::setw(widthResult) << (bruteTimeout ? "Timeout" : std::to_string(BruteTime))
                  << std::setw(widthResult) << (sqrtTimeout ? "Timeout" : std::to_string(SqrtTime))
                  << std::setw(widthResult) << (millerTimeout ? "Timeout" : std::to_string(MillerTime)) << "|\n";

        std::cout << std::string(widthUnderline, '-') << "\n";
    }

    return 0;
}