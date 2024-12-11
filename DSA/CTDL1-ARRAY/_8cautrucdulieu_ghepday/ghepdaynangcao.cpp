#include "iostream"
#include "vector"
#include "algorithm"

int main() {
    int n; std::cin>>n;
    std::vector<int> a(n);
    for (int& x: a) std::cin>>x;

    int m; std::cin>>m;
    std::vector<int> b(m);
    for (int& x: b) std::cin>>x;

    a.insert(a.end(), b.begin(), b.end());
    std::sort(a.begin(), a.end());

    for (int x : a) std::cout<<x<<" ";
    return 0;
}