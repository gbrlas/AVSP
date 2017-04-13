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
		int C,gomi;
		scanf("%d %d ",&C,&gomi);
		double D = gomi;

		vector <double> base_pos;
		for(int c=0;c<C;c++)
		{
			int P,V;
			scanf("%d %d ",&P,&V);
			
			for(int k=0;k<V;k++)
			{
				base_pos.push_back(P);
			}
		}

		double answer = 0.0;
		if(SZ(base_pos)>=2)
		{
			double lo = 0.0;
			double hi = 1e14;

			for(int binary_loop=0;binary_loop<200;binary_loop++)
			{
				const double time = lo+(hi-lo)/2.0;
				bool ok = true;
				vector <double> pos(base_pos);

				const int N = SZ(pos);
				int left = 0;
				int right = N-1;

				// まず、左端と右端のやつをおもいっきり端まで移動
				pos[left] -= time;
				pos[right] += time;
				left++;
				right--;

				for(int left=1;left<SZ(pos)-1;left++)
				{
					if(pos[left]-pos[left-1]>D)
					{
						pos[left] = max(pos[left-1]+D,pos[left]-time);
					}
					else
					{
						if(fabs((pos[left]+time)-pos[left-1])<D)
						{
							ok = false;
							break;
						}
						pos[left] = pos[left-1]+D;
					}
				}

				if(fabs(pos[right]-pos[right+1])<D)
				{
					ok = false;
				}

				if(ok)
				{
					hi=time;
				}
				else
				{
					lo=time;
				}
//				cout << time << endl;
			}
			answer = lo+(hi-lo)/2.0;
		}

		printf("Case #%d: %.13f\n",t+1,answer);
	}

	return 0;
}
