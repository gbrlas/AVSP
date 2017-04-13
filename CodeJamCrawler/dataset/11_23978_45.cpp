#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <time.h>
#include <math.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for (LL i=0; i<n; i++)
#define FOR(i,x,y) for (int i=x; i<=y; i++)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define filein "in.txt"

int main()
{
	freopen(filein,"rt",stdin);
	freopen("out.txt","wt",stdout);
	
	int t;
	cin>>t;

	FOR(test,1,t)
	{
		int n,tmp,xor=0,sum=0,Min=1000009;
		cin>>n;

		FOR(i,1,n)
		{
			cin>>tmp;
			sum += tmp;
			xor = xor^tmp;
			Min = min(Min,tmp);
		}
		if (xor) printf("Case #%d: NO\n",test);
		else printf("Case #%d: %d\n",test,sum-Min);
		
	}
	fcloseall();
	//system("pause");
}
