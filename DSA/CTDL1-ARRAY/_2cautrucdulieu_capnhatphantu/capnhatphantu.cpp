#include "iostream"

int main () {
    int n, binhphuong; std::cin >> n;
    int a[n];
    
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    for (int i = 0; i < n; i++) {
        binhphuong = a[i] * a[i];
        std::cout << binhphuong << " ";
    }
}