#include<iostream>
#include<algorithm>
using namespace std;

int L,n,m;
int d[5005];

bool possible (int dis){
    int last=0,cnt=m-1;
    for (int i=1;i<=n+1;i++){
        if (cnt==0) return false;
        if (d[i]-d[last]>dis){
            if (i-last==1) return false;
            else{
                last=i-1; 
                cnt--;
            }
        }
    }
    if (d[n+1]-d[last]<=dis) return true;
    else return false;
}

int main(){

    while(std::cin>>L>>n>>m){

        for (int i=1;i<=n;i++) cin>>d[i];
        d[n+1]=L;

        sort (d,d+n+2);

        int l=0,r=L;
        while (l<r){
            int mid=(l+r)/2;
            if (possible(mid)) r=mid;
            else l=mid+1;
        }

        cout<<l<<endl;
    }

    return 0;

}