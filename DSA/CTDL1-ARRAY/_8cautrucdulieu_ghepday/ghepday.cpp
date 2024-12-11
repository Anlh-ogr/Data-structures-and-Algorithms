#include "iostream"

int main() {
    int n; std::cin>>n;
    int a[n];
    for (int i=0;i<n;i++) std::cin>>a[i];
    
    int m; std::cin>>m;
    int b[m]; 
    for (int i=0;i<m;i++) std::cin>>b[i];

    int c[n+m];
    for (int i=0;i<n;i++) c[i]=a[i];
    for (int i=0;i<m;i++) c[n+i]=b[i];

    for (int i=0;i<n+m;i++)
        for (int j=0;j<n+m;j++)
            if (c[i]<c[j]) {
                int tmp=c[i];
                c[i]=c[j];
                c[j]=tmp;
            }
    
    for (int i=0;i<n+m;i++) std::cout<<c[i]<<" ";
}