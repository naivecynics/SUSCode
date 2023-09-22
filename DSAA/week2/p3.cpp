        #include<iostream>
        using namespace std;

        int n,a[100010];
        int T,x,y;

        int locate_x (int o){
            int l=0,r=n-1;
            while (l<r){
                int mid=(l+r)/2;
                if (a[mid]>o) r=mid;
                else l=mid+1;
            }
            return l;
        }

        int locate_y (int o){
            int l=0,r=n-1;
            while (l<r){
                int mid=(l+r)/2;
                if (a[mid]>=o) r=mid;
                else l=mid+1;
            }
            return l;
        }

        int main(){
            cin>>n>>T;
            for (int i=0;i<n;i++) cin>>a[i];
            while (T--){
                cin>>x>>y;

                if (x>=y || x>=a[n-1] || y<=a[0]){
                    cout<<"NO"<<endl;
                    continue;
                }
                
                int lx=locate_x(x),ly=locate_y(y);
                int ans=ly-lx;

                //cout<<lx<<" "<<ly<<endl;

                if (x>a[lx]) ans++;
                if (y>a[ly]) ans++;

                if (ans>0) cout<<"YES"<<" "<<ans<<endl;
                else cout<<"NO"<<endl;
            }
            return 0;
        }