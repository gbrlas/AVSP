// I may use the MPIR library. Its website is this,
// http://www.mpir.org/

#include <stdio.h>
#include <tchar.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;

typedef long long ll;

static const double EPS = 1e-6;
inline int ROUND(double x) { return (int)(x+0.5); }
inline bool ISINT(double x) { return fabs(ROUND(x)-x)<EPS; }
inline bool ISEQUAL(double x,double y) { return fabs(x-y)<EPS; }
#define INRANGE(x,a,b) ((a)<=(x)&&(x)<=(b))
#define ARRAY_NUM(a) (sizeof(a)/sizeof(a[0])) 
#define SZ(a) ((int)a.size())
#define NG (-1)
#define BIG (987654321)

using namespace std;

// 最大公約数（ユークリッドの互除法）
ll gcd(ll x, ll y)
{
	ll t;

	while(y!=0)
	{
		t = x%y;
		x = y;
		y = t;
	}
	return x;
}

// 最小公倍数
ll lcm(ll x, ll y)
{
	return x*y/gcd(x,y);
}

int main()
{
	freopen("_google_code_jam_input.txt","r",stdin);
	freopen("_google_code_jam_output.txt","w",stdout);

	int T;
	scanf("%d ",&T);

	for (int t=0;t<T;t++)
	{
		ll N,L,H;
		scanf("%lld %lld %lld ",&N,&L,&H);
		vector <ll> vi;
		for(int n=0;n<N;n++)
		{
			int tmp;
			scanf("%d ",&tmp);
			vi.push_back(tmp);
		}


		ll res = NG;
		for(int a=L;a<=H;a++)
		{
			bool ok = true;
			for(int i=0;i<SZ(vi);i++)
			{
				if(!(a%vi[i]==0||vi[i]%a==0))
				{
					ok = false;
					break;
				}
			}
			if(ok)
			{
				res = a;
				break;
			}
		}

		if(res!=NG)
		{
			printf("Case #%d: %d\n",t+1,res);
			fprintf(stderr,"Case #%d: %d\n",t+1,res);
		}
		else
		{
			printf("Case #%d: NO\n",t+1);
			fprintf(stderr,"Case #%d: NO\n",t+1);
		}

	}

	return 0;
}
