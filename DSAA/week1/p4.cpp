#include <iostream>
using namespace std;
int T,n,mx,ans;
int a[200000];
int main() {
    cin>>T;
    for (int j=0;j<T;j++){
        ans=-100010; mx=100010;
        cin>>n;
        for (int i=0;i<n;i++){
           scanf("%d",&a[i]);
           if (mx-a[i]>ans&&i!=0) ans=mx-a[i];
           if (a[i]<mx) mx=a[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}   
