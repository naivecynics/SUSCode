#include<bits/stdc++.h>
#include<windows.h>
#include<unistd.h>
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
int main()
{
	while(1)
	{
		system("T6data.exe");
		sleep(0.3);
		system("F.exe");
		sleep(0.3);
		system("T6.exe");
		sleep(0.3);
		if(system("fc T6.out force.out"))
		{
			cout<<"fuck";
			exit(0);
		}
		else
		{
			cout<<"ac"<<endl;
		}
	}
	return 0;
}

