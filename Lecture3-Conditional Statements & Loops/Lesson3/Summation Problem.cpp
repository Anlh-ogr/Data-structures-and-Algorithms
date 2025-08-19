#include "iostream"
#include "cmath"
#include "vector"


// Encapsulate for Summation
class Summation {
    protected:
        long long n;
        double a, r;    // a: first term, r: common ratio for geometric series
    
    public:
        Summation ( long long Number = 0, double A = 0, double R = 0 )
            : n(Number), a(A), r(R) {}

        void PrintResult ( const std::string& type, auto sum ) const {
            std::cout << "Sum of " << type << " Numbers from 1 to " << n << " is: " << sum << std::endl;
        }
};

// Encapsulate for Sum N
class Sum_N : public Summation {
    public:
        using Summation::Summation;

        void Loop() {
            long long sum = 0;
            for (long long i = 1; i <= n; ++i) sum += i;
            PrintResult("numbers", sum);
        }

        void Formula() {
            // n * (n + 1) / 2
            long long sum = (n * (n + 1)) / 2;
            PrintResult("numbers", sum);
        }
};

// Encapsulate for Sum N even
class Sum_N_Even : public Summation {
    public:
        using Summation::Summation;

        void Loop() {
            long long sum = 0;
            for (long long i = 2; i <= n; i += 2) sum += i;
            PrintResult("even numbers", sum);
        }

        void Formula() {
            // n/2 * (n/2 + 1)
            long long sum = (n / 2) * ((n / 2) + 1);
            PrintResult("even numbers", sum);
        }
};

// Encapsulate for Sum N odd
class Sum_N_Odd : public Summation {
    public:
        using Summation::Summation;

        void Loop() {
            long long sum = 0;
            for (long long i = 1; i <= n; i += 2) sum += i;
            PrintResult("odd numbers", sum);
        }

        void Formula() {
            // (n + 1) / 2 * (n + 1) / 2 - (k²)
            long long sum = ((n + 1) / 2) * ((n + 1) / 2);
            PrintResult("odd numbers", sum);
        }
};

// Encapsulate for Sum N square
class Sum_N_Square : public Summation {
    public:
        using Summation::Summation;

        void Loop() {
            long long sum = 0;
            for (long long i = 1; i <= n; ++i) sum += i * i;
            PrintResult("squared numbers", sum);
        }

        void Formula() {
            // n(n + 1)(2n + 1) / 6
            long long sum = (n * (n + 1) * (2 * n + 1)) / 6;
            PrintResult("squared numbers", sum);
        }
};

// Encapsulate for Sum N cube
class Sum_N_Cube : public Summation {
    public:
        using Summation::Summation;

        void Loop() {
            long long sum = 0;
            for (long long i = 1; i <= n; ++i) sum += i * i * i;
            PrintResult("cubed numbers", sum);
        }

        void Formula() {
            // (n(n + 1) / 2)²
            long long sum = ((n * (n + 1)) / 2) * ((n * (n + 1)) / 2);
            PrintResult("cubed numbers", sum);
        }
};

// Encapsulate + Abstraction for Sum K-mult
class Sum_K_Mult : public Summation {
    private:
        long long k;
    
    public:
        Sum_K_Mult(long long Number = 0, double K = 0)
            : Summation(Number) , k(K) {}

        // Getter/Setter for K
        void SetK( long long K ) { this->k = K; }
        long long GetK() const { return k; }

        void Loop() {
            long long sum = 0;
            for (long long i = k; i <= n; i += k)
                sum += i;
            PrintResult("K-multiples", sum);
        }

        void Formula() {
            // k * (n / k) * ((n / k) + 1) / 2
            long long sum = k * (n / k) * ((n / k) + 1) / 2;
            PrintResult("K-multiples", sum);
        }
};

// Encapsulate + Abstraction for Geo sum
class Geo_Sum : public Summation {
    public:
        Geo_Sum(long long Number = 0, double A = 1, double R = 1)
            : Summation(Number, A, R) {}

        void Loop() {
            double sum = 0;
            for (long long i = 0; i < n; ++i) {
                sum += a * pow(r, i);
            }
            PrintResult("geometric series", sum);
        }

        void Formula() {
            // a * (1 - r^n) / (1 - r)
            double sum = a * (1 - pow(r, n)) / (1 - r);
            PrintResult("geometric series", sum);
        }
};
// Encapsulate + Abstraction for Arith sum
class Arith_Sum : public Summation {
    public:
        Arith_Sum(long long Number = 0, double A = 1, double R = 1)
            : Summation(Number, A, R) {}

        void Loop() {
            double sum = 0;
            for (long long i = 0; i < n; ++i)
                sum += a + i * r;
            PrintResult("arithmetic series", sum);
        }

        void Formula() {
            // n/2 * (2a + (n - 1)r)
            double sum = (n / 2.0) * (2 * a + (n - 1) * r);
            PrintResult("arithmetic series", sum);
        }
};

// Encapsulate + Abstraction for Arith sum
class Arith_Sum : public Summation {
    public:
        Arith_Sum(long long Number = 0, double A = 1, double R = 1)
            : Summation(Number, A, R) {}

        void Loop() {
            double sum = 0;
            for (long long i = 0; i < n; ++i)
                sum += a + i * r;
            PrintResult("arithmetic series", sum);
        }

        void Formula() {
            // n/2 * (2a + (n - 1)r)
            double sum = (n / 2.0) * (2 * a + (n - 1) * r);
            PrintResult("arithmetic series", sum);
        }
};

// 9. Harmonic
// Encapsulate + Abstraction for Harmonic sum
class Harmonic_Sum : public Summation {
    public:
        Harmonic_Sum(long long Number = 0)
            : Summation(Number) {}

        void Loop() {
            double sum = 0;
            for (long long i = 1; i <= n; ++i) {
                sum += 1.0 / i;
            }
            PrintResult("harmonic series", sum);
        }

        void Formula() {
            // The harmonic series does not have a simple closed formula like the others,
            double sum = 0;
            for (long long i = 1; i <= n; ++i) {
                sum += 1.0 / i;
            }
            PrintResult("harmonic series", sum);
        }
};

// Inheritance + Polymorphism for Cond Sum

