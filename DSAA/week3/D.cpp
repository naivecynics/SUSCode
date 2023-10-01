#include<iostream>
using namespace std;

int n,k;
int a[1000005];

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

int main(){
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    quick_sort (a,1,n);
    cout<<a[k];
    return 0;
}