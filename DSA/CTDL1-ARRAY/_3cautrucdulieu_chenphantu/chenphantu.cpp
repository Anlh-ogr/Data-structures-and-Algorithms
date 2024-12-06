#include "iostream"

void cach1(int n, int k, int x);
void cach2(int n, int k, int x);
void cach3(int n, int k, int x);

int main() {
    int nval, kval, xval;
    cach1(nval, kval, xval);
    std::cout << std::endl;
    cach2(nval, kval, xval);

    return 0;
}

void cach1 (int n, int k, int x) {
    std::cin >> n;
    
    int a[n+1];
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::cin >> k >> x;

    // duyet tu cuoi mang den vi tri k, dich cac phan tu tu vi tri k den n
    for (int i = n; i >= k; i--)
        a[i] = a[i-1];

    a[k] = x;
    n++;

    for (int i = 0; i < n; i++)
        std::cout << a[i] << " ";
}

/*  duyet tu cuoi mang den vi tri k, dich cac phan tu tu vi tri k den n
    for (int i = n; i >= k; i--)
        a[i] = a[i-1] <=> vi tri mang sau khi dich = vi tri mang trc khi dich
    
    vd: n=4, k=1, x=10
        a[n+1] = a[5] = {0, 1, 2, 3, 4, null}
    mang trc khi them k: a[5] = {1, 2, 3, 4, null}
    mang sau khi chen k: a[5] = {1, k, 2, 3, 4}
    
    duyet mang tu k -> n:
        khi i=n=4, i(4) >= k(1): a[4] mang luc sau = a[3] mang ban dau -> giam i xuong 1: a[4] = 4
        khi i=n=3, i(3) >= k(1): a[3] mang luc sau = a[2] mang ban dau -> giam i xuong 1: a[3] = 3
        khi i=n=2, i(2) >= k(1): a[2] mang luc sau = a[1] mang ban dau -> giam i xuong 1: a[2] = 2
        khi i=n=1, i(1) >= k(1): a[1] mang luc sau = a[0] mang ban dau -> giam i xuong 1: a[1] = 1
        khi i=n=0, i(0) >= k(1) -> khong thoa dieu kien -> thoat vong lap

    a[k] = x; <=> a[1] = 10
    n++; */

void cach2 (int n, int k, int x) {
    std::cin >> n;

    int arr[n+1];
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];

    std::cin >> k >> x;

    // tim vi tri k trong mang
    int a, b, temp[n+1];
    for (int i = 0; i < n; i++) {
        if(arr[i] == k) {
            a = i + 1;
            break;
        }
    }

    // chen x vao vi tri k va dich cac phan tu tu vi tri k den n
    int j = 0;
    while(true) {
        if(j == a) {
            temp[a] = x;
            for (int i = j + 1; i < n + 1; i++)
                temp[i] = arr[i-1];
            break;
        } else
            temp[j] = arr[j];
        j++;
    }

    for (int i = 0; i < n + 1; i++)
        std::cout << temp[i] << " ";
}
