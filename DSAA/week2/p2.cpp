#include<iostream>
using namespace std;

int n,T;
unsigned long long int ans[1000001];

int main(){

    for (int i=1;i<=1000000;i++) ans[i] = ans[i-1] +i*(i+1)/2;//printf("%llu\n",ans[i]);

    cin>>T;

    while (T--){
        cin>>n;
        //cout<<ans[n]<<endl;
        printf("%lld\n",ans[n]);
    }
    // system("pause");
    return 0;
}