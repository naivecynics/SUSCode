#include<iostream>
using namespace std;

const int dir[4][2]={{0,1},{0,-1},{-1,0},{1,0}};

struct point{
    int x,y;    
};

point p,P;
int T,run[10010];
int x_T,y_T;

point get_point (int t){
    int cir=t/T;
    int rest=t%T;
    point p_t=P;
    p_t.x+=cir*x_T;
    p_t.y+=cir*y_T;
    for (int i=1;i<=rest;i++){
        p_t.x+=dir[run[i]][0];
        p_t.y+=dir[run[i]][1];
    }
    return p_t;
}

bool chase (int t){
    point P_t=get_point(t);
    return abs(P_t.x-p.x)+abs(P_t.y-p.y)<=t ? true : false;
}


int main(){

    cin>>p.x>>p.y>>P.x>>P.y;
    cin>>T;
    for (int i=1;i<=T;i++){
        char c;
        cin>>c;
        if (c=='U') run[i]=0;
        else if (c=='D') run[i]=1;
        else if (c=='L') run[i]=2;
        else if (c=='R') run[i]=3;

        x_T+=dir[run[i]][0];
        y_T+=dir[run[i]][1];
    }

    int l=1,r=1000000000;
    while (l<r){
        int mid=(l+r)/2;
        if (chase(mid)) r=mid;
        else l=mid+1;
    }

    cout<<l;
    return 0;
}