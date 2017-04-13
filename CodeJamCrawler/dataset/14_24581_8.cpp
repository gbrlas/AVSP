#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
typedef long long LL;
typedef pair<int,int> pii;
#define ALL(a) a.begin(),a.end()
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
int t;

int main()
{
	scanf("%d", &t);
	for(int i=1;i<=t;i++){
		LL a,b;
		scanf("%lld/%lld", &a, &b);
		LL fpb = __gcd(a,b);
		a/=fpb;
		b/=fpb;
		printf("Case #%d: ",i);
		if(__builtin_popcount(b)!=1)
		{
			puts("impossible");
			continue;
		}
		else
		{
			int cou = 0;
			while(b>a)
			{
				b>>=1;
				cou++;
			}
			printf("%d\n",cou);
		}
	}
	return 0;
}	
