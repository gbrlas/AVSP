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

		vector <int> vi;
		for(int i=0;i<N;i++)
		{
			int tmp;
			scanf("%d ",&tmp);
			vi.push_back(tmp);
		}

		sort(vi.begin(),vi.end());

		int sum = 0;
		int xor = 0;
		for(int i=0;i<SZ(vi);i++)
		{
			if(i!=0)
			{
				sum += vi[i];
			}
			xor ^= vi[i];
		}
		if(xor==0)
		{
			printf("Case #%d: %d\n",t+1,sum);
		}
		else
		{
			printf("Case #%d: NO\n",t+1);
		}
	 }

	return 0;
}
