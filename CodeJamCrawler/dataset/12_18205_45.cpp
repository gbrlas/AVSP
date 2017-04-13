
#include<algorithm>
#include<assert.h>
#include<bitset>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<deque>
#include<iostream>
#include<map>
#include<memory.h>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<utility>
#include<vector>

using namespace std;

#define LL long long int

typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VLL> VVLL;
typedef vector<VD> VVD;
typedef vector<VS> VVS;
typedef pair<int,int> PI;
typedef vector<pair<int,int> > VPI;
typedef pair<double,double> PD;

#define SI ({int _x; scanf("%d",&_x); _x;})
#define SC ({char _x; scanf("%c",&_x); _x;})
#define SLL ({LL _x; scanf("%lld",&_x); _x;})
#define SLF ({double _x; scanf("%lf",&_x); _x;})
#define lc(i) (i<<1)
#define rc(i) ((i<<1)+1)
#define iscan(n) scanf("%d",&n)
#define cscan(n) scanf("%c",&n)
#define llscan(n) scanf("%lld",&n)
#define lfscan(n) scanf("%lf",&n)
#define sscan(n) scanf("%s",n)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FORD(i,a,b) for(int i=b-1;i>=a;--i)
#define REP(i,b) for(int i=0;i<b;++i)
#define REPD(i,b) for(int i=b-1;i>=0;--i)
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define FILL(a,b) memset(a,b,sizeof a)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)<0?-(a):(a))
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define TR(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 

int main()
{
	int T = SI;
	REP(zz,T)
	{
		int A = SI, B = SI, cnt = 0;
		set<PI> s;
		set<PI>::iterator it;

		if(B < 10)
		{
			printf("Case #%d: 0\n", zz+1);
			continue;
		}
		else if(A < 10)
		{
			A = 10;
		}

		FOR(y,A,B+1)
		{
			VI v;
			int x = y;
			while(x)
			{
				v.PB(x%10);
				x /= 10;
			}

			int sz = v.size();
			for(int i=0, j=sz-1; i<j; ++i,--j)
			{
				swap(v[i], v[j]);
			}

			FOR(i,1,sz)
			{
				int x = 0;
				FOR(j,i,sz+i)
				{
					x = x*10 + v[j%sz];
				}
				
				if(y != x && A <= x && x <= B)
				{
					PI p = MP(min(y,x), max(y,x));
					it = s.find(p);
					if(it == s.end())
					{
						s.insert(p);
						++cnt;
					}
				}
			}
		}

		printf("Case #%d: %d\n", zz+1, cnt);
	}
	return 0;
}
