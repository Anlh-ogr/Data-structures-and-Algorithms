#include "iostream"
 
int main() {
    int n; std::cin >> n;
    int a[n];

    for (int i=0; i < n; i++) std::cin >> a[i];

    bool isNonIncreasing = true;
    bool isNonDecreasing = true;

    for (int i=0; i < n-1; i++)
        if (a[i] < a[i+1])
            isNonIncreasing = false;
        else if (a[i] > a[i+1])
            isNonDecreasing = false;

    if (isNonIncreasing || isNonDecreasing)
        std::cout << "YES";
    else std::cout << "NO";

    return 0;
}