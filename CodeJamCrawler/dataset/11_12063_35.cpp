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
		int N;
		scanf("%d ",&N);

		vector <string> vs;

		for(int n=0;n<N;n++)
		{
			char str[256];
			scanf("%s ",str);
			vs.push_back(string(str));
		}

		vector <double> wp(N);
		vector <double> owp(N);
		vector <double> oowp(N);
		vector <double> rpi(N);

		double ignwp[200][200];
		memset(ignwp,0,sizeof(ignwp));

		for(int y=0;y<N;y++)
		{
			double win = 0.0;
			double lose = 0.0;
			for(int x=0;x<N;x++)
			{
				if(vs[y][x]=='1')
				{
					win++;
				}
				else if (vs[y][x]=='0')
				{
					lose++;
				}
			}

			double match = win+lose;

			for(int x=0;x<N;x++)
			{
				if(vs[y][x]=='1')
				{
					ignwp[y][x]=(win-1)/(match-1);
				}
				else if (vs[y][x]=='0')
				{
					ignwp[y][x]=win/(match-1);
				}
				else
				{
					ignwp[y][x]=win/(match);
				}
			}
		}

		for(int y=0;y<N;y++)
		{
			wp[y] = ignwp[y][y];

			owp[y]=0;
			double match = 0;
			for(int x=0;x<N;x++)
			{
				if(vs[y][x]=='1' || vs[y][x]=='0' )
				{
					match++;
					owp[y]+=ignwp[x][y];
				}
			}
			owp[y] /= match;

		}

		for(int y=0;y<N;y++)
		{
			oowp[y]=0;
			double match = 0;
			for(int x=0;x<N;x++)
			{
				if(vs[y][x]=='1' || vs[y][x]=='0' )
				{
					match++;
					oowp[y]+=owp[x];
				}
			}
			oowp[y] /= match;
		}

		printf("Case #%d:\n",t+1);
		for(int y=0;y<N;y++)
		{
			rpi[y] =  0.25 * wp[y] + 0.50 * owp[y]+ 0.25 * oowp[y];
			printf("%.13f\n",rpi[y]);
		}
	}

	return 0;
}
