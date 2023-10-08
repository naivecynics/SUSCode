#include<iostream>
//#include<algorithm>
using namespace std;

int n,n3;
int a[1000005];
int ans[1000005];

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
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    quick_sort (a,1,n);
    // int l=1,r=0x7fffffff;
    // while (l<r){
    //     int mid=(l+r)>>1;
    //     if (check(mid)) r=mid;
    //     else l=mid+1;
    // }
    n3=n/3;
    cout<<a[n3+1]<<endl;
    //cout<<n3*3<<" "<<n-n%3<<endl;
    for (int i=1;i<=n-n%3;i++){
        
        int x=(i/3)+1;
        int y=n3+2*(i/3)+1;
        int z=n3+2*((i-1)/3)+2;
        if (i%3==1) ans[i]=a[x];
        if (i%3==2) ans[i]=a[y];
        if (i%3==0) ans[i]=a[z];
    }

    for (int i=n-n%3+1;i<=n;i++) ans[i]=a[i];
    for (int i=1;i<=n;i++) cout<<ans[i]<<" ";

    return 0;
}