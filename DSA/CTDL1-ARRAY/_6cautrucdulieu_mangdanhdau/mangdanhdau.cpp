#include "iostream"
#include "queue"
#include "vector"

int main() {
    int n; std::cin>>n;

    int a[n], count = 0, prev = -1;
    for (int i=0;i<n;i++) std::cin>>a[i];
    
    for (int i=0;i<n;i++)
        for (int j=0;j<n-1;j++)
            if(a[j]>a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        
    for (int i=0;i<n;i++) std::cout<<a[i]<<" ";
    std::cout<<std::endl;

    std::queue<int> q;
    for (int i=0;i<n;i++) q.push(a[i]);

    std::vector<bool> appeared(n+1, false);

    while(!q.empty()) {
        int first = q.front();
        q.pop();

        if(first != prev) {
            if(prev != -1) std::cout<<prev<<"-"<<count<<"; ";
            prev = first;
            count = 1;
        } else count++;
    }
    if (prev != -1)
        std::cout<<prev<<"-"<<count<<"; ";

    return 0;
}
