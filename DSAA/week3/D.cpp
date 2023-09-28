#include<iostream>
#include<algorithm>
using namespace std;

int n,k;
int a[1000005];

int main(){
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort (a+1,a+n+1);
    cout<<a[k];
    return 0;
}