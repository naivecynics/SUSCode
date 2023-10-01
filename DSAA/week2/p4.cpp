#include<iostream>
using namespace std;

int n,S,ans;
int a[3010];
int rest,l,r,mid;

int main(){

    cin>>n>>S;
    for (int i=0;i<n;i++) scanf ("%d",&a[i]);

    for (int i=0;i<n && a[i]<=S/3;i++){
        for (int j=i+1;j<n-1 && S-a[i]-a[j]>=a[j];j++){

            rest=S-a[i]-a[j];
            l=j+1,r=n-1;

            while (l<r){
                mid=(l+r)>>1;
                if (a[mid]>=rest) r=mid;
                else l=mid+1;
            }   

            while (a[l]==rest && rest!=0){
                ans++;
                l++;
            }
        }
    }
    
    cout<<ans;
    return 0;
}