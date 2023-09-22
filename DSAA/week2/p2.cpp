#include<iostream>
using namespace std;

long long n,T;

int main(){

    cin>>T;

    while (T--){
        cin>>n;
        long long ans=n*(n+1)*(n+2)/6;
        printf ("%lld\n",ans);
    }

    return 0;
}