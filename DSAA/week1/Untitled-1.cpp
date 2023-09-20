#include <iostream>

using namespace std;

int T;
int mj[10][4];
int three,two;

//i: type rest: rest majong type: if contain two
/*
void dfs(int i,int num,int rest,int type){
    if (!rest) {

    }
    if (mj[num][i]==0) dfs(i,num++,rest,type);
    else{
        if (mj[num][i]>=3){
            if (three){
                mj[num][i]-=3;
                three--;
                dfs(i,num,rest-3,type);
                mj[num][i]+=3;
                three++;
            }
            else if (type && two){
                mj[num][i]-=2;
                two--;
                dfs(i,num,rest-2,type);
                mj[num][i]+=2;
                two++;
            }
        }
        if (mj[num][i]==2){
            if (type && two){
                mj[num][i]-=2;
                two--;
                dfs(i,num+1,rest-2,type);
                mj[num][i]+=2;
                two++;
            }
            if (mj[num+1][i]>0 && mj[num+2][i]>0 && num<=7 && three){
                mj[num][i]--; mj[num+1][i]--; mj[num+2][i]--;
                three--;
                dfs(i,num,rest-3,type);
                mj[num][i]++; mj[num+1][i]++; mj[num+2][i]++;
                three++;
            }
            else return;
        }
        if (mj[num][i]==1 && num<=7 && three){
            if (mj[num+1][i]>0 && mj[num+2][i]>0){
                mj[num][i]--; mj[num+1][i]--; mj[num+2][i]--;
                three--;
                dfs(i,num+1,rest-3,type);
                mj[num][i]++; mj[num+1][i]++; mj[num+2][i]++;
                three++;
            }
            else return;
        }
        else return;
    }
}
*/

int main(){
    cin>>T;
    while(T--){
        three=4; two=1;
        for (int i=0;i<14;i++){
            char num,type;
            cin>>num>>type;
            if (type=='w') mj[num-'0'][1]++,mj[0][1]++;
            else if (type=='b') mj[num-'0'][2]++,mj[0][2]++;
            else if (type=='s') mj[num-'0'][3]++,mj[0][3]++;
            else if (type=='z') mj[num-'0'][4]++,mj[0][4]++;
        }
        for (int i=1;i<=4;i++){
            if (mj[0][i]%3==2 && two){
                //dfs(i,0,mj[0][i],1);
                for (int j=1;j<=9;j++){
                    int a=three,b=two;
                    int mj[10];
                    for (int k=1;k<=9;k++) mj[k]=mj[k][i];
                    if (mj[j][i]>=2){
                        two--;
                        mj[j][i]-=2;
                        mj[0][i]-=2;
                    }
                    for (int k=1;k<=9 && mj[0][i];k++){
                        if (mj[k][i]>=3){
                            three--;
                            mj[k][i]-=3;
                            mj[0][i]-=3;
                        }
                        if (mj[k+1][i]>0 && mj[k+2][i]>0 && k<=7 && three){
                            mj[k][i]--; mj[k+1][i]--; mj[k+2][i]--;
                            mj[0][i]-=3;
                            three--;
                        }
                    }
                    if (mj[0][i]==0) break;
                    else{
                        three=a; two=b;
                        for (int k=1;k<=9;k++) mj[k]=mj[k][i];
                    }
                }
                if (mj[0][i]!=0){
                    printf("Bad luck\n");
                    break;
                }
            }
            else if (mj[0][i]%3==0 && three) {
                //dfs(i,0,mj[0][i],0);
                 for (int k=1;k<=9 && mj[0][i];k++){
                    if (mj[k][i]>=3){
                        three--;
                        mj[k][i]-=3;
                        mj[0][i]-=3;
                    }
                    if (mj[k+1][i]>0 && mj[k+2][i]>0 && k<=7 && three){
                        mj[k][i]--; mj[k+1][i]--; mj[k+2][i]--;
                        mj[0][i]-=3;
                        three--;
                    }
                }
            }
            else{
                printf("Bad luck\n");
                break;
            }
        }
        if (!three && !two) printf ("Blessing of Heaven");
        else printf("Bad luck\n");
    }
}