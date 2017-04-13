#include <iostream>
using namespace std;
#define max(a,b) ((a)>(b)?(a):(b))
int Pd,Pg,N;
int md,mg;
int gcd(int a,int b)
{
	while(b)
	{
		a^=b^=a^=b;
		b=b%a;
	}
	return a;
}
int main()
{
	//freopen("A-small-attempt0.in","r",stdin);
	//freopen("A-small-attempt0.out","w",stdout);
	int T,Case=0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&N,&Pd,&Pg);
		if(Pd!=0&&Pg==0)
		{
			printf("Case #%d: Broken\n",++Case);
			continue;
		}
		if(Pd!=100&&Pg==100)
		{
			printf("Case #%d: Broken\n",++Case);
			continue;
		}
		int d=gcd(Pd,100);
		Pd/=d;
		md=100/d;
		if(N<md)
		{
			printf("Case #%d: Broken\n",++Case);
			continue;
		}
		printf("Case #%d: Possible\n",++Case);
	}
	return 0;
}
