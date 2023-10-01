#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int n,p,q;
long long ans;

struct plant{
    long long h,s;
    long long p_value;
    long long q_value;
    bool operator<(const plant& other) const {
        return p_value > other.p_value;
    }
} a[200010];

int main(){
    cin>>n>>p>>q;
    for (int i=1;i<=n;i++){
        cin>>a[i].h>>a[i].s;
        a[i].p_value=a[i].h*pow(2,p)-a[i].s;
        a[i].q_value=a[i].h-a[i].s;
        ans+=a[i].s;
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n && q>0;i++){
        if (a[i].p_value>0 && p>0){
            ans+=a[i].p_value;
            p=0;
            q--;
        }
        else if (a[i].q_value>0){
            ans+=a[i].q_value;
            q--;
        }
    }
    cout<<ans;
    return 0;
}

/*
3 3 10
2 8
3 5
4 1

3 5 10
7 8
7 8
7 8
*/