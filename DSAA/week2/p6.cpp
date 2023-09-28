#include<iostream>
using namespace std;

const int dir[4][2]={{0,1},{0,-1},{-1,0},{1,0}};

struct point{
    long long x,y;    
};

point p,P;
long long T,run[20000];
long long x_T,y_T;

point get_point (int t){
    long long cir=t/T;
    long long rest=t%T;
    point p_t=P;
    p_t.x+=cir*x_T;
    p_t.y+=cir*y_T;
    for (int i=1;i<=rest;i++){
        p_t.x+=dir[run[i]][0];
        p_t.y+=dir[run[i]][1];
    }
    return p_t;
}

bool chase (long long t){
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

    if (p.x==P.x && p.y==P.y){
        cout<<0;
        return 0;
    }

    long long l=1,r=9000000000000000;
    while (l<r){
        long long mid=(l+r) >> 1;
        if (chase(mid)) r=mid;
        else l=mid+1;
    }

    printf("%lld",(l==9000000000000000 ? -1 : l));
    return 0;
}