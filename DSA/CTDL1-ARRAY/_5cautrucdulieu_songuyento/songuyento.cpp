#include "iostream"
#include "cmath"

bool isPrime(int numbers);

int main() {
    int n; std::cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    for (int i = 0; i < n; i++)
        if (isPrime(a[i]))
            std::cout << a[i] << " ";

    return 0;
}

bool isPrime(int numbers) {
    if (numbers < 2) return false;
    for (int i = 2; i<= sqrt(numbers); i++)
        if (numbers % i == 0)
            return false;
    return true;
}