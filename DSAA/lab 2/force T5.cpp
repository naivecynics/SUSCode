#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define maxn 100010
int n=10;
int a[maxn],pd[maxn];
int ans,b[maxn];
void dfs(int num)
{
	if(num==0)
	{
		for(int i=1+n;i<=2*n;i++)
		{
			a[i]=a[i-n];
		}
		int temp=n;
		for(int i=1;i<=n;i++)
		{
			int tt[4];
			tt[1]=a[i];tt[2]=a[i+1];tt[3]=a[i+2];
			sort(tt+1,tt+1+3);
			temp=min(temp,tt[2]);
		}
		if(temp>ans)
		{
			ans=temp;
			for(int i=1;i<=n;i++)
			{
				b[i]=a[i];
			}
		}
		else if(temp==ans)
		{
			int tag=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==b[i]) continue;
				if(a[i]>b[i])
				{
					tag=1;
					break;
				}
				else
				{
					tag=2;
					break;
				}
			}
			if(tag==2)
			{
				for(int i=1;i<=n;i++)
				{
					b[i]=a[i];
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(pd[i]==0)
		{
			pd[i]=1;
			a[n-num+1]=i;
			dfs(num-1);
			pd[i]=0;
		}
	}
	return ;
}
int main()
{
	cin>>n;
	dfs(n);
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}

