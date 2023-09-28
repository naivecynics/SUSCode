#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

int n,a[5000005];

signed main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort (a+1,a+n+1);
    if (n%2==1) cout<<a[(n+1)/2]*2;
    else cout<<a[n/2]+a[n/2+1];
}