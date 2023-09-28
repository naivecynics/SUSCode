#include<iostream>
using namespace std;

int n,S,ans;
int a[3010];

int main(){

    cin>>n>>S;
    for (int i=0;i<n;i++) scanf ("%d",&a[i]);

    for (int i=0;i<n && a[i]<=S/3;i++){
        for (int j=i+1;j<n-1 && S-a[i]-a[j]>=a[j];j++){

            int rest=S-a[i]-a[j];
            int l=j+1,r=n-1;

            while (l<r){
                int mid=(l+r) >> 1;
                if (a[mid]>=rest) r=mid;
                else l=mid+1;
            }   

            while (a[l]==rest){
                ans++;
                l++;
            }
        }
    }
    
    cout<<ans;
    return 0;
}