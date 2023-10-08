#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#include<string.h>
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
void merge(long long arry[],long long left,long long mid,long long right)
{
	long long leftarry[mid-left+1];
	long long rightarry[right-mid];
	for(int i=1;i<=mid-left+1;i++)
	{
		leftarry[i]=arry[left+i-1];
	}
	for(int i=1;i<=right-mid;i++)
	{
		rightarry[i]=arry[mid+i];
	}
	long long zuo=1,you=1,wh=left;
	while(zuo<=mid-left+1&&you<=right-mid)
	{
		if(leftarry[zuo]<=rightarry[you])
		{
			arry[wh]=leftarry[zuo];
			zuo++;
			wh++;
		}
		else
		{
			arry[wh]=rightarry[you];
			you++;
			wh++;
		}
	}
	while(zuo<=mid-left+1)
	{
		arry[wh]=leftarry[zuo];
		zuo++;
		wh++;
	}
	while(you<=right-mid)
	{
		arry[wh]=rightarry[you];
		you++;
		wh++;
	}
	return ;
}
void soort(long long arry[],long long left,long long right)
{
	if(left<right)
	{
		long long mid=(left+right)>>1;
		soort(arry,left,mid);
		soort(arry,mid+1,right);
		merge(arry,left,mid,right);
	} 
	return ;
}
struct SS
{
	long long h;
	long long s;
	long long gap;
	long long num;
};
SS a[maxn];
SS b[maxn];
long long n,ans;
long long p,q;
long long cnt;
long long nousesum,usesum1,usesum2;
long long pd[maxn];
bool cmp(SS t1,SS t2)
{
	if(t1.gap!=t2.gap)
	{
		return t1.gap>t2.gap;
	}
	else
	{
		return t1.s<=t2.s;
	}
}
int main()
{
	freopen("T6.in","r",stdin);
	freopen("force.out","w",stdout);
	read(n);read(p);read(q);
	for(ri i=1;i<=n;i++)
	{
		read(a[i].h);
		read(a[i].s);
		a[i].num=i;
		a[i].gap=a[i].h-a[i].s;
	}
	if(q)
	{
		for(int i=1;i<=n;i++)
		{
			cnt=0;
			long long temp=0,qq=q;
			for(int j=1;j<=n;j++)
			{
				if(i!=j)
				{
					cnt++;
					b[cnt]=a[j];
				}
			}
			sort(b+1,b+1+cnt,cmp);
			if(a[i].h*(1ll<<p)>a[i].s)
			{
				qq--;
				temp=a[i].h*(1ll<<p);
			} 
			else
			{
				temp=a[i].s;
			}
//			cout<<"temp1 "<<temp<<endl;
			for(int j=1;j<=cnt;j++)
			{
				if(qq)
				{
					if(b[j].gap>0)
					{
						qq--;
						temp+=b[j].h;
					}
					else
					{
						temp+=b[j].s;
					}
				}
				else
				{
					temp+=b[j].s;
				}
			}
//			cout<<"temp2 "<<temp<<endl;
			ans=max(ans,temp);
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			ans+=a[i].s;
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
2 1 1
10 8
6 1
*/
