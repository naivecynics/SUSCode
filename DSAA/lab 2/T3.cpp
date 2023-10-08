#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#include<string.h>
using namespace std; 
#define ri register int
#define maxn 100010
#define int long long
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
int t,n;
long long a[maxn];
long long ans=0;
long long root=1;
long long tl[maxn*4],tr[maxn*4],val[maxn*4];
void pushup(int node)
{
	val[node]=val[tl[node]]+val[tr[node]];
	return;
}
void insert(int l,int r,int node,int wh)
{
	if(l>r) return;
	if(l==r)
	{
		val[node]++;
		return;
	}
	int mid=(l+r)>>1;
	if(wh<=mid)
	{
		if(!tl[node])
		{
			tl[node]=++root;
		}
		insert(l,mid,tl[node],wh);
	}
	else
	{
		if(!tr[node])
		{
			tr[node]=++root;
		}
		insert(mid+1,r,tr[node],wh);
	}
	pushup(node);
}
int ask(int l,int r,int node,int ll,int rr)
{
	if(l>rr||r<ll||(!node)) return 0;
	if(ll<=l&&r<=rr)
	{
		return val[node];
	}
	int mid=(l+r)>>1;
	return ask(l,mid,tl[node],ll,rr)+ask(mid+1,r,tr[node],ll,rr);
}
signed main()
{
	read(t);
	while(t--)
	{
		read(n);
		for(int i=1;i<=n;i++)
		{
			read(a[i]);
			a[i]+=2147483647ll+2;
		} 
		for(int i=n;i>=1;i--)
		{
			insert(1,2147483647ll+2147483647+2,1,a[i]);
			ans+=ask(1,2147483647ll+2147483647+2,1,1,a[i]-1);
		}
		root=1;
		memset(tl,0,sizeof(tl));
		memset(tr,0,sizeof(tr));
		memset(val,0,sizeof(val));
		memset(a,0,sizeof(a));
		
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}

