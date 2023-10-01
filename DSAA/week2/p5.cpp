#include<iostream>
using namespace std;

int L,n,m;
int d[500005];

bool possible (int dis){
    int last=0,cnt=m-1;
    for (int i=1;i<=n+1;i++){
        if (cnt==0 && d[n+1]-d[last]>dis) return false;
        if (d[i]-d[last]>dis){
            if (i-last==1) return false;
            else{
                last=i-1; 
                cnt--;
                i--;
            }
        }
    }
    if (d[n+1]-d[last]<=dis) return true;
    else return false;
}

void quick_sort (int a[], int l, int r){
    if (l>=r) return;
    int i=l, j=r, p=a[(l+r)>>1];
    while (i<=j){
        while (a[i]<p) i++;
        while (a[j]>p) j--;
        if (i<=j){
            swap (a[i],a[j]);
            i++, j--;
        }
    }
    quick_sort (a,l,j);
    quick_sort (a,i,r);
}

int main(){

    while(std::cin>>L>>n>>m){

        for (int i=1;i<=n;i++) cin>>d[i];
        d[n+1]=L;

        quick_sort (d,0,n+1);

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