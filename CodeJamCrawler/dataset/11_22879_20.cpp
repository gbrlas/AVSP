#include <cstdio>

int T,PD,PG;
long long N;

int gcd(int a, int b)
{
		if (a < b)
			return gcd(b,a);
		else if (b == 0)
			return a;
		else 
			return gcd(b,a%b);
}

bool ok()
{
	int minpd;
	if (PD < 100 && PG == 100 || PD > 0 && PG == 0)
		return false;
	minpd = 100 / gcd(PD, 100);
	if (minpd > N)
		return false;
	return true;
	
}

int main (int argc, char * const argv[]) 
{
	freopen("/Users/danglu/Projects/GCJ/A-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&T);
	for (int i = 1; i <=T; i++) 
	{
		scanf("%lld%d%d",&N,&PD,&PG);
		bool tag = ok();
		printf("Case #%d: %s\n", i, tag?"Possible":"Broken");
	}
}
