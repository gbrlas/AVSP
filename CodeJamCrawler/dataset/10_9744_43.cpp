#include <cstdio>
#include <algorithm>
#include <cmath>

#define LL long long

using namespace std;

LL pot(int n)
{
	if(n==0) return 1;
	LL a=0ll;
	if(n%2) return 2*pot(n-1);
	else a=pot(n/2);
	return a*a;
}

int main()
{
	int tst;
	scanf("%d", &tst);
	for(int w=0; w<tst;++w)
	{
		
		int n;
		LL k;
		scanf("%d%lld", &n, &k);
		LL tmp=pot(n)-1;
		//printf("%lld\n",pot(n));
		
		
		while(k-tmp>1) k-=(tmp+1);
		printf("Case #%d: ", w+1);
		if(k==tmp) printf("ON\n");
		else printf("OFF\n");
	}
	return 0;
}
