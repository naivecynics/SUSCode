#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#include<string.h>
#include<vector>
using namespace std;
#define ri register int
#define maxn 1000010
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
int n;
int a[maxn],ans[maxn];
void merge(int arry[],int left,int mid,int right)
{
	int leftarry[mid-left+1];
	int rightarry[right-mid];
	for(int i=1;i<=mid-left+1;i++)
	{
		leftarry[i]=arry[left+i-1];
	}
	for(int i=1;i<=right-mid;i++)
	{
		rightarry[i]=arry[mid+i];
	}
	int zuo=1,you=1,wh=left;
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
void soort(int arry[],int left,int right)
{
	if(left<right)
	{
		int mid=(left+right)>>1;
		soort(arry,left,mid);
		soort(arry,mid+1,right);
		merge(arry,left,mid,right);
	} 
	return ;
}
int main()
{
	read(n);
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
	}
//	sort(a+1,a+1+n,cmp);
	soort(a,1,n);
	cout<<a[n/3+1]<<endl;
	for(int i=1;i<=n/3*3;i++)
	{
		if(i%3==1)
		{
			ans[i]=a[i/3+1];
		}
		else if(i%3==2)
		{
			ans[i]=a[n/3+1+2*(i/3)];
		}
		else
		{
			ans[i]=a[n/3+1+2*((i-1)/3)+1];
		}
	}
	for(int i=(n/3)*3+1;i<=n;i++)
	{
		ans[i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",ans[i]);
	}
	return 0;
}
/*
6
1 6 4 5 2 3
11
1 2 3 4 5 6 7 8 9 10 11
15
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
*/

