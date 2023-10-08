#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define maxn 100010
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
long long n=5,p,q;
int main()
{
	freopen("T6.in","w",stdout);
	srand(time(0));
	p=rand()%21;
	q=rand()%n;
	cout<<n<<" "<<p<<" "<<q<<endl; 
	for(int i=1;i<=n;i++)
	{
		cout<<1ll*rand()*rand()%n+1<<" "<<1ll*rand()*rand()%n+1<<endl;
	}
	return 0;
}

