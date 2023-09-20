#include<iostream>
using namespace std;

int n,a[100000];
int T,num;

int main(){
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>T;
    while (T--){
        cin>>num;
        int l=0,r=n-1;
        while (l<r){
            int mid=(l+r)/2;
            if (a[mid]>=num) r=mid;
            else l=mid+1;
        }
        if (a[l]==num) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}