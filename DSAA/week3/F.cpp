#include<iostream>
#include<cmath>
using namespace std;

int n,p,q;
long long ans,tot;

struct plant{
    long long h,s;
    long long p_value;
    long long q_value;
    // bool operator<(const plant& other) const {
    //     return p_value > other.p_value;
    // }
} a[200010];

void quick_sort_p (int l, int r){
    if (l>=r) return;
    int i=l, j=r, p=a[(l+r)>>1].p_value;
    while (i<=j){
        while (a[i].p_value>p) i++;
        while (a[j].p_value<p) j--;
        if (i<=j){
            swap (a[i],a[j]);
            i++, j--;
        }
    }
    quick_sort_p (l,j);
    quick_sort_p (i,r);
}

void quick_sort_q (int l, int r){
    if (l>=r) return;
    int i=l, j=r, p=a[(l+r)>>1].q_value;
    while (i<=j){
        while (a[i].q_value>p) i++;
        while (a[j].q_value<p) j--;
        if (i<=j){
            swap (a[i],a[j]);
            i++, j--;
        }
    }
    quick_sort_q (l,j);
    quick_sort_q (i,r);
}


int main(){
    // freopen("T6.in","r",stdin);
	// freopen("T6.out","w",stdout);
    cin>>n>>p>>q;
    for (int i=1;i<=n;i++){
        cin>>a[i].h>>a[i].s;
        a[i].p_value=a[i].h*pow(2,p)-a[i].s;
        a[i].q_value=a[i].h-a[i].s;
        tot+=a[i].s;
    }
    if (q==0){
        cout<<tot;
        return 0;
    }
    // quick_sort_p(1,n);
    // for (int i=1;i<=n && q>0;i++){
    //     if (a[i].p_value>0 && p>0){
    //         ans+=a[i].p_value;
    //         p=0;
    //         q--;
    //         quick_sort_q (1+i,n);
    //         for (int j=i+1;j<=n && q>0;j++){
    //             if (a[j].q_value>0){
    //             ans+=a[j].q_value;
    //             q--;
    //            }
    //         }
    //         break;
    //     }
    //     if (a[i].q_value>0){
    //         ans+=a[i].q_value;
    //         q--;
    //     }
    // }
    quick_sort_q (1,n);
    int ddl=0;
    ans = tot;
    for (int i=1;i<=n && q>0;i++){
        if (a[i].q_value>0){
            tot+=a[i].q_value;
            q--; ddl=i;
        }
    }
    for (int i=1;i<=n;i++){
        if (i<=ddl) ans=max (ans, max (tot, tot-a[i].q_value+a[i].p_value));
        else if (q==0) ans=max (ans, max (tot, tot-a[ddl].q_value+a[i].p_value));
        else ans=max (ans, max (tot, tot+a[i].p_value));
    }
    cout<<ans;
    return 0;
}

