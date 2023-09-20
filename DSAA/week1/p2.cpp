#include<iostream>
using namespace std;
int n,T,a[100100];
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n;
    for (int i=0;i<n;i++){
        int num; cin>>num;
        a[num]++;
    }
    cin>>T;
    for (int i=0;i<T;i++){
        int num; cin>>num;
        if (a[num]) cout<<"yes"<<"\n";
        else cout<<"no"<<"\n";
    }
}