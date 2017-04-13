#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

long long n;
int d,g,ans; 

int gcd(int a,int b)
{
	int x,y,z;
	x=a; y=b; z=a%b;
	while (z!=0) {
		x=y; y=z; z=x%y;
	}
	return y;
}

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int t=0,tt; scanf("%d",&tt);
	while (++t<=tt) {
		printf("Case #%d: ",t);
		scanf("%I64d%d%d",&n,&d,&g);
		if (g==0) {
			if (d==0) printf("Possible\n"); else printf("Broken\n");
			continue;
		}
		if (g==100) {
			if (d==100) printf("Possible\n"); else printf("Broken\n");
			continue;
		}
		ans=100/gcd(d,100);
		if (ans<=n) printf("Possible\n"); else printf("Broken\n");
	}
	return 0;
}

