#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int T;
string tiles[13];

//Wx>Tx>Yx>E>S>W>N>B>F>Z
int mp(string o){
    int value;
    if (o[0]=='W' && o[1]) value=0+o[1]-'0';
    else if (o[0]=='T') value=10+o[1]-'0';
    else if (o[0]=='Y') value=20+o[1]-'0';
    else if (o[0]=='E') value=30;
    else if (o[0]=='S') value=40;
    else if (o[0]=='W') value=50;
    else if (o[0]=='N') value=60;
    else if (o[0]=='B') value=70;
    else if (o[0]=='F') value=80;
    else if (o[0]=='Z') value=90;
    return value;
}

bool cmp(string a, string b){
    if(mp(a)!=mp(b)){
        return mp(a)<mp(b);
    }else{
        return mp(a)>mp(b);
    }
}


int main(){
    cin>>T;
    while(T--){
        for(int i=0;i<13;i++) cin>>tiles[i];
        sort(tiles, tiles+13, cmp);
        for(int i=0;i<13;i++) cout<<tiles[i]<<" ";
        cout<<endl;
    }
    return 0;
}