#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#include<string.h>
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
int n,k;
int a[maxn];
int main()
{
	read(n);read(k);
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
	}
//	sort(a+1,a+1+n);
	soort(a,1,n);
	cout<<a[k];
	return 0;
}

