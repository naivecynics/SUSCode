    #include <iostream>
    #include <cstring>

    using namespace std;

    int T;
    int mj[100][40];
    int three,two;
    int fig;


    int main(){
        cin>>T;
        while(T--){
            three=4; two=1; fig=1;
            memset (mj,0,sizeof(mj));

            for (int i=0;i<14;i++){
                char num,type;
                cin>>num>>type;
                if (type=='w') mj[num-'0'][1]++,mj[0][1]++;
                else if (type=='b') mj[num-'0'][2]++,mj[0][2]++;
                else if (type=='s') mj[num-'0'][3]++,mj[0][3]++;
                else if (type=='z') mj[num-'0'][4]++,mj[0][4]++;
            }
            
            for (int i=1;i<=4;i++){
                if (mj[0][i]%3==2){
                    //dfs(i,0,mj[0][i],1);
                    for (int j=1;j<=9;j++){
                        int a=three,b=two;
                        int m[10];
                        for (int k=0;k<=9;k++) m[k]=mj[k][i];
                        if (mj[j][i]>=2){
                            two--;
                            mj[j][i]-=2;
                            mj[0][i]-=2;

                            for (int k=1;k<=9 && mj[0][i];k++){
                                if (mj[k][i]>=3){
                                    three--;
                                    mj[k][i]-=3;
                                    mj[0][i]-=3;
                                    k--;
                                }
                                else if (mj[k][i]>0 && mj[k+1][i]>0 && mj[k+2][i]>0 && k<=7 && three && i!=4){
                                    mj[k][i]--; mj[k+1][i]--; mj[k+2][i]--;
                                    mj[0][i]-=3;
                                    three--;
                                    k--;
                                }
                            }
                            if (mj[0][i]==0) break;
                            else{
                                three=a; two=b;
                                for (int k=0;k<=9;k++) mj[k][i]=m[k];
                            }
                        }

                    }
                    if (mj[0][i]!=0){
                        printf("Bad luck\n");
                        fig=0;
                        break;
                    }
                }
                else if (mj[0][i]%3==0 ) {
                    //dfs(i,0,mj[0][i],0);  
                    for (int k=1;k<=9 && mj[0][i];k++){
                        if (mj[k][i]>=3){
                            three--;
                            mj[k][i]-=3;
                            mj[0][i]-=3;
                            k--;
                        }
                        else if (mj[k][i]>0 && mj[k+1][i]>0 && mj[k+2][i]>0 && k<=7 && three && i!=4){
                            mj[k][i]--; mj[k+1][i]--; mj[k+2][i]--;
                            mj[0][i]-=3;
                            three--;
                            k--;
                        }
                    }
                    if (mj[0][i]!=0){
                        printf("Bad luck\n");
                        fig=0;
                        break;
                    }
                }
                else if (three || two){
                    printf("Bad luck\n");
                    fig=0;
                    break;
                }
            }
            if (!three && !two){
                printf ("Blessing of Heaven\n");
            }else if (fig){
                printf("Bad luck\n"); 
            }
        }
    }