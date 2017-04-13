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
#pragma warning(disable : 4996)
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
#define PRINTF(fmt, ...) printf(fmt, __VA_ARGS__); fprintf(stderr, fmt, __VA_ARGS__);

using namespace std;

int main()
{
	freopen("_google_code_jam_input.txt","r",stdin);
	freopen("_google_code_jam_output.txt","w",stdout);

	int TTT;
	scanf("%d ",&TTT);

	for (int t=0;t<TTT;t++)
	{
		double X,S,R,T;
		int N;
		scanf("%lf %lf %lf %lf %d",&X,&S,&R,&T,&N);
		vector <double> b;
		vector <double> e;
		vector < pair <double, int> > wp;

		double ret = 0.0;


		for(int n=0;n<N;n++)
		{
			double tmp[3];
			scanf("%lf %lf %lf",&tmp[0],&tmp[1],&tmp[2]);
			b.push_back(tmp[0]);
			e.push_back(tmp[1]);
			wp.push_back(make_pair(tmp[2],n));
		}

		// ‚Ü‚¸•½’n‚ð‘–‚ê
		double flat = X;
		for(int n=0;n<N;n++)
		{
			flat -= e[n]-b[n];
		}

		b.push_back(0);
		e.push_back(flat);
		wp.push_back(make_pair(0,N));
		
		// w‚ª¬‚³‚¢
		sort(wp.begin(),wp.end());

		for(int n=0;n<N+1;n++)
		{
			int i = wp[n].second;
			double x = e[i]-b[i];
			double walk_dist = max(0.0,x-T*(R+wp[n].first));
			double run_dist = x-walk_dist;
			double walk_time = walk_dist/(S+wp[n].first);
			double run_time = run_dist/(R+wp[n].first);

			ret += walk_time+run_time;
			T -= run_time;

//			printf("x=%f wd=%f rd=%f wt=%f rt=%f i=%d n=%d ret=%f T=%f\n",x,walk_dist,run_dist,walk_time,run_time,i,n,ret,T);

		}
	


		PRINTF("Case #%d: %.16f\n",t+1,ret);
	}

	return 0;
}
