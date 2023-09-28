#include<iostream>
using namespace std;

int T;
int n,a[100001];
int tot;

int main(){
    cin>>T;
    while (T--){
        cin>>n;
        tot=0;
        for (int i=1;i<=n;i++) cin>>a[i];
        for (int i=1;i<=n-1;i++){
            bool swaap=false;
            for (int j=1;j<=n-i+1;j++){
                if (a[j-1]>a[j]){
                    swap(a[j-1],a[j]);
                    tot++, swaap=true;
                }
            }
            if (!swaap) break;
        }
        //for (int i=1;i<=n;i++) cout<<a[i]<<" ";
        //cout<<endl;
        cout<<tot<<endl;
    }
}