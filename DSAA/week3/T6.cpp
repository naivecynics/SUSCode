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
	freopen("T6.out","w",stdout);
	read(n);read(p);read(q);
	for(ri i=1;i<=n;i++)
	{
		read(a[i].h);
		read(a[i].s);
		a[i].num=i;
		a[i].gap=a[i].h-a[i].s;
		if(a[i].gap>0)
		{
			cnt++;
			b[cnt]=a[i];
		}
		else
		{
			nousesum+=a[i].s;
		}
	}
	if(q)
	{
		sort(b+1,b+1+cnt,cmp);
		int duandian=min(cnt,q);
		for(int i=1;i<=duandian;i++)
		{
			usesum1+=b[i].h;
			pd[b[i].num]=1;
		}
		for(int i=duandian+1;i<=cnt;i++)
		{
			usesum2+=b[i].s;
		}
//		cout<<"fuck "<<nousesum<<" "<<usesum1<<" "<<usesum2<<endl; 
//		cout<<"pre "<<usesum1<<" "<<usesum2<<" "<<nousesum<<endl;
		for(int i=1;i<=n;i++)
		{
			if(a[i].gap>0)
			{
				if(pd[i]==1)
				{
					ans=max(ans,1ll*usesum1-a[i].h+usesum2+nousesum+(a[i].h*(1ll<<p)));
				}
				else 
				{
					ans=max(ans,1ll*usesum1-b[duandian].h+b[duandian].s+usesum2-a[i].s+nousesum+(a[i].h*(1ll<<p)));
				}	
			}
			else
			{
				if(q>cnt)
				{
					ans=max(ans,1ll*usesum1+usesum2+nousesum-a[i].s+(a[i].h*(1ll<<p)));
					ans=max(ans,1ll*usesum1+usesum2+nousesum);
				}
				else
				{
					ans=max(ans,1ll*usesum1-b[duandian].h+b[duandian].s+usesum2+nousesum-a[i].s+(a[i].h*(1ll<<p)));
					ans=max(ans,1ll*usesum1-b[duandian].h+b[duandian].s+usesum2+nousesum);
				}
				
			}
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
