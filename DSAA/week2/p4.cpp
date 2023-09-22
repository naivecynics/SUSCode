#include<iostream>
using namespace std;

int n,S,ans;
int a[3001];
// int num[3001][2];
// int k;

int main(){

    cin>>n>>S;
    // cin>>a[0];
    // num[0][0]=a[0];
    // num[0][1]=1;
    for (int i=0;i<n;i++){
        cin>>a[i];
        // num[num[k][0]==a[i] ? k : ++k][0]=a[i];
        // num[k][1]++;
    }

    for (int i=0;i<n && a[i]<=S/3;i++){
        for (int j=i+1;j<n-1;j++){
            int rest=S-a[i]-a[j];
            int l=j+1,r=n-1;
            while (l<r){
                int mid=(l+r)/2;
                if (a[mid]>=rest) r=mid;
                else l=mid+1;
            }

            if (a[l]==rest){
                ans++;
                int x=l,y=l;
                while (a[x-1]==rest && x-1>j){
                    ans++;
                    x--;
                }
                while (a[y+1]==rest){
                    ans++;
                    y++;
                }
            }
            // if (a[l]==rest){
            //     int l1=0,r1=k;
            //     while (l1<r1){
            //         int mid=(l1+r1)/2;
            //         if (num[mid][0]>=a[i]) r1=mid;
            //         else l1=mid+1;
            //     }
            //     ans+=num[l1][1];
            // }
        }
    }

    cout<<ans;

    return 0;
}