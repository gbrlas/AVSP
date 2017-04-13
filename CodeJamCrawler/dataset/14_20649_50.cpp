#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define FORD(i,h,l) for(int i=(h);i>=(l);--i)

//#define coutpoint5 setiosflags(ios::fixed)<<setprecision(5)

#define maxn 100000
//#define maxm 1000000
//#define MM 1000000007

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

int a[maxn];

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	//ios_base::sync_with_stdio(false);
	
	int T;
	scanf("%d",&T);
	FOR(TT,1,T)
	{
		printf("Case #%d: ",TT);
		int n,x;
		scanf("%d%d",&n,&x);
		FOR(i,1,n)
			scanf("%d",a+i);
		sort(a+1,a+n+1);
		int l=1,r=n;
		int ans=0;
		while (l<=r)
		{
			if (l==r)
			{
				ans++;
				break;
			}
			if (a[l]+a[r]<=x)
			{
				l++;
				r--;
				ans++;
			}
			else
			{
				r--;
				ans++;
			}
		}
		printf("%d\n",ans);
	}

	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
