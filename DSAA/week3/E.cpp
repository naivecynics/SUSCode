#include<iostream>
#include<algorithm>
using namespace std;

int n;
int a[1000005];

bool check (int x){
    for (int i = 1; i <= n; i++) {
        int j = (i+1) % n + 1;
        int l = (j+1) % n + 1;
        if (a[i] + x > a[l] || a[j] - x < a[i] || a[l] - x < a[j]) {
            return false;
        }
    }
    return true;
}

int main(){
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort (a+1,a+n+1);
    int l=1,r=0x7fffffff;
    while (l<r){
        int mid=(l+r)>>1;
        if (check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l;
}