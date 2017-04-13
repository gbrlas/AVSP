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

using namespace std;

int main()
{
    freopen("_google_code_jam_input.txt","r",stdin);
	freopen("_google_code_jam_output.txt","w",stdout);

	int T;
	scanf("%d ",&T);

	for (int t=0;t<T;t++)
	{
		ll N,PD,PG;
		cin >> N >> PD >> PG;

		bool possible = false;

		if ( (PD==0&&PG==100) || 
			 (0<PD&&PD<100&&(PG==0||PG==100)) ||
			 (PD==100&&PG==0)
		   )
		{
			// ‚Þ‚è

		}
		else
		{
			// ‚Å‚«‚é‚¾‚¯¬‚³‚¢D‚ð’T‚·
			ll D,DWIN;
			for(D=1LL;D<=min(N,100LL);D++)
			{
				if((PD*D)%100LL==0)
				{
					DWIN = (PD*D)/100LL;
					if(INRANGE(DWIN,0,N))
					{
						possible = true;
						break;
					}
				}
			}

			if(possible)
			{
				possible = false;
				// G‚ð’T‚·
				for(ll G=D;G<=100000;G++)
				{
					if((PG*G)%100LL==0)
					{
						ll GWIN = (PG*G)/100LL;
						if(GWIN>=DWIN && G-D>=GWIN-DWIN)
						{
							possible = true;
							break;
						}
					}
				}
			}
		}

		if(possible)
		{
			printf("Case #%d: Possible\n",t+1);
		}
		else
		{
			printf("Case #%d: Broken\n",t+1);

		}
	 }

	return 0;
}
