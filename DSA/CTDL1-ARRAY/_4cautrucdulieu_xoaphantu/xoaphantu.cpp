#include "iostream"

int main() {
    int n, k; std::cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    
    std::cin >> k;
    for (int i = k; i < n; i++)
        a[i] = a[i+1];
    n--;

    for (int i = 0; i < n; i++)
        std::cout << a[i] << " ";

    return 0;
}