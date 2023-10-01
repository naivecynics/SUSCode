#include<iostream>
#define int long long
using namespace std;

void quick_sort (int a[], int l, int r){
    if (l>=r) return;
    int i=l, j=r, p=a[(l+r)>>1];
    while (i<=j){
        while (a[i]<p) i++;
        while (a[j]>p) j--;
        if (i<=j){
            swap (a[i],a[j]);
            i++, j--;
        }
    }
    quick_sort (a,l,j);
    quick_sort (a,i,r);
}
int n,a[5000005];

signed main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    quick_sort (a,1,n);
    if (n%2==1) cout<<a[(n+1)/2]*2;
    else cout<<a[n/2]+a[n/2+1];
}