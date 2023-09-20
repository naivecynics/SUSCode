#include<iostream>
using namespace std;

int T;
int a,b,h;

int main(){
    cin>>T;

    for (int o=0;o<T;o++){
        cin>>a>>b>>h;
        if (b<=h){
            for (int i=0;i<b;i++){
                for (int j=0;j<2*(b-i);j++) cout<<".";
                for (int j=0;j<a;j++) cout<<"+-";
                for (int j=0;j<i;j++) cout<<"+.";
                cout<<"+"; cout<<endl;
                for (int j=0;j<2*(b-i)-1;j++) cout<<".";
                for (int j=0;j<a;j++) cout<<"/.";
                for (int j=0;j<i+1;j++) cout<<"/|";
                cout<<endl;
            }
            for (int i=0;i<h-b;i++){
                for (int j=0;j<a;j++) cout<<"+-";
                for (int j=0;j<b;j++) cout<<"+.";
                cout<<"+"; cout<<endl;
                for (int j=0;j<a;j++) cout<<"|.";
                for (int j=0;j<b;j++) cout<<"|/";
                cout<<"|"; cout<<endl;
            }
            for (int j=0;j<a;j++) cout<<"+-";
            for (int j=0;j<b;j++) cout<<"+.";
            cout<<"+"; cout<<endl;
            for (int i=0;i<b;i++){
                for (int j=0;j<a;j++) cout<<"|.";
                for (int j=0;j<b-i;j++) cout<<"|/";
                for (int j=0;j<2*i+1;j++) cout<<".";
                cout<<endl;
                for (int j=0;j<a;j++) cout<<"+-";
                for (int j=0;j<b-i;j++) cout<<"+.";
                for (int j=0;j<2*i+1;j++) cout<<".";
                cout<<endl;
            }
        }
        else{
            for (int i=0;i<h;i++){
                for (int j=0;j<2*(b-i);j++) cout<<".";
                for (int j=0;j<a;j++) cout<<"+-";
                for (int j=0;j<i;j++) cout<<"+.";
                cout<<"+"; cout<<endl;
                for (int j=0;j<2*(b-i-1);j++) cout<<".";
                for (int j=0;j<a+1;j++) cout<<"./";
                for (int j=0;j<i;j++) cout<<"|/";
                cout<<"|"; cout<<endl;
                //这里有问题，1 5 2
            }
            for (int i=0;i<(b-h);i++){
                for (int j=0;j<2*(b-h-i);j++) cout<<".";
                for (int j=0;j<a;j++) cout<<"+-";
                for (int j=0;j<h;j++) cout<<"+.";
                cout<<"+"; 
                for (int j=0;j<2*i;j++) cout<<".";
                cout<<endl;
                for (int j=0;j<2*(b-h-i)-1;j++) cout<<".";
                for (int j=0;j<a;j++) cout<<"/.";
                for (int j=0;j<h;j++) cout<<"/|";
                cout<<"/"; 
                for (int j=0;j<2*i+1;j++) cout<<".";
                cout<<endl;
            }
            for (int j=0;j<a;j++) cout<<"+-";
            for (int j=0;j<h;j++) cout<<"+.";
            cout<<"+"; 
            for (int j=0;j<2*(b-h);j++) cout<<".";
            cout<<endl;
            for (int i=0;i<h;i++){
                for (int j=0;j<a;j++) cout<<"|.";
                for (int j=0;j<h-i;j++) cout<<"|/";
                for (int j=0;j<2*(b+i-h)+1;j++) cout<<".";
                cout<<endl;
                for (int j=0;j<a;j++) cout<<"+-";
                for (int j=0;j<h-i-1;j++) cout<<"+.";
                cout<<"+";
                for (int j=0;j<2*(b+i-h+1);j++) cout<<".";
                cout<<endl;
            }
        }
    }
}