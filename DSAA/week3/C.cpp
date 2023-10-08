#include<iostream>
#define int long long
using namespace std;
 
int T;
int n,a[500001];
int tmp[500001];
 
long long inverse(int l,int r){
    if (l==r) return 0;
    int mid=(l+r)>>1;
    long long ans=inverse(l,mid)+inverse(mid+1,r);
    int i=l,j=mid+1;
    int tot=0;
    for (int k=l;k<=r;k++){
        if (i==mid+1) {
            tmp[k]=a[j++];
            tot+=mid-i+1;
        }
        else if (j==r+1) tmp[k]=a[i++];
        else if (a[i]>a[j]) {
            tmp[k]=a[j++];
            tot+=mid-i+1;
        }
        else tmp[k]=a[i++];
    }
    for (int k=l;k<=r;k++) a[k]=tmp[k];
    ans+=tot;
    return ans;
}
 
signed main(){
    cin>>T;
    while (T--){
        cin>>n;
        for (int i=1;i<=n;i++) cin>>a[i];
        cout<<inverse(1,n)<<endl;
    }
}