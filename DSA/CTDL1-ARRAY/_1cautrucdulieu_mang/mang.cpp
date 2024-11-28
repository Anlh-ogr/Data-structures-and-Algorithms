#include "iostream"

void cach_1 ();
void cach_2 ();

int main() {
    cach_1();
    cach_2();
    return 0;
}

void cach_1 () {
    int n; std::cin >> n;
    int a[n];
    
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    int total = 0;
    for (int i = 0; i < n; i++)
        total += a[i];
    
    std::cout << total << std::endl;
}

/* khi gan gia tri total = vi tri dau tien cua mang, thi luc duyet mang, ta se
duyet bat dau tu vi tri thu 2 cua mang. neu khong, luc tinh total, vong lap se
bat dau tu vi tri dau tien cua mang, va vi tri dau tien se bi tinh 2 lan gay ra
sai logic de bai yeu cau. */
void cach_2 () {
    int n; std::cin >> n;
    int a[n];
    
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    int total = a[0];
    for (int i = 1; i < n; i++)
        total += a[i];
    
    std::cout << total << std::endl;
}