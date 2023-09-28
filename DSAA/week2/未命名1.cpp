#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;
#define ri register int
#define maxn 1000100
#define int long long 
struct SS
{
	int x;
	int y;
};
SS eve,neko;
SS ori[maxn];
int n;
long long change=0; 
long long cx,cy;
signed main()
{	
	cin>>eve.x;cin>>eve.y;
	cin>>neko.x;cin>>neko.y;
	cin>>n;
	ori[0]=neko;
	for(int i=1;i<=n;i++)
	{
		char s;
		cin>>s;
		ori[i]=ori[i-1];
		if(s=='U') ori[i].y++;
		if(s=='D') ori[i].y--;
		if(s=='L') ori[i].x--;
		if(s=='R') ori[i].x++;
	}
	cx=ori[n].x-ori[0].x;
	cy=ori[n].y-ori[0].y;
	if(eve.x==neko.x&&eve.y==neko.y)
	{
		cout<<"0";
		return 0;
	}
	else
	{
		
			long long zuo=0,you=9000000000000000ll,mid;
			long long xx;
			long long yy;
			while(zuo!=you)
			{
				mid=(zuo+you)>>1;
				long long terms=mid/n;
				long long wh=mid%n;
				xx=ori[wh].x+terms*cx;
				yy=ori[wh].y+terms*cy;
				if(abs(xx-eve.x)+abs(yy-eve.y)<=mid)
				{
					you=mid;
				}
				else
				{
					zuo=mid+1;
				}
			}
			mid=(zuo+you)>>1;
		if(mid==9000000000000000ll)
		{
			cout<<"-1"<<endl;
		}
		else
		{
			cout<<mid<<endl;
		} 
	}
	return 0;
}
/*
0 0 
4 6
4
RURU

1 1
5 7
3
DDD

0 0
0 2
16
RRDDDDLLLLUUUURR
*3

0 0
0 1
1
U
*-1

0 0
2 2
2
DR
*3
0 0
3 3
12
UUURRRDDDLLL
*9

0 0
4 3
1
D

*/
