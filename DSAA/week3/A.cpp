#include<iostream>
using namespace std;

int T;
int n,m;
int a[100005],b[100005];

int main(){
    cin>>T;
    while (T--){
        cin>>n>>m;
        for (int i=1;i<=n;i++) cin>>a[i];
        for (int i=1;i<=m;i++) cin>>b[i];
        a[n+1]=2147483647, b[m+1]=2147483647;
        int i=1,j=1;
        while (i<=n || j<=m){
            if (a[i]<b[j]) cout<<a[i++]<<" ";
            else cout<<b[j++]<<" ";
        }
        cout<<endl;
    }
    return 0;
}