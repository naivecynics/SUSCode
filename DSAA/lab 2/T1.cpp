#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;
#define ri register int
#define maxn 200010
template< typename T >inline void read(T &x)
{
	char c=getchar();x=0;int f=0;
	for(;!isdigit(c);c=getchar()) f|=(c=='-');
	for(;isdigit(c);c=getchar()) x=((x<<3)+(x<<1)+(c^48));
	x=f?-x:x;
}
template< typename T >inline void write(T x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10^48);
}
int t;
int a,b;
int aa[maxn],bb[maxn];
int ans[maxn];
int main()
{
	read(t);
	while(t--)
	{
		read(a);read(b);
		for(int i=1;i<=a;i++)
		{
			read(aa[i]);
		}
		for(int i=1;i<=b;i++)
		{
			read(bb[i]);
		}
		int taga=1;
		int tagb=1;
		for(int i=1;i<=a+b;i++)
		{
//			cout<<i<<" f "<<taga<<" "<<tagb<<endl;
			if(tagb==b+1)
			{
				ans[i]=aa[taga];
				taga++;
			}
			else if(taga==a+1)
			{
//				cout<<"hello";
				ans[i]=bb[tagb];
				tagb++;
			}
			else if(aa[taga]<=bb[tagb])
			{
				ans[i]=aa[taga];
				taga++;
			}
			else
			{
				ans[i]=bb[tagb];
				tagb++;
			}
			printf("%d ",ans[i]);
		}
		cout<<endl;
	}
	return 0;
}

