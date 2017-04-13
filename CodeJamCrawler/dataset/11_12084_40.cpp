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

int main()
{
	freopen("_google_code_jam_input.txt","r",stdin);
	freopen("_google_code_jam_output.txt","w",stdout);

	int T;
	scanf("%d ",&T);

	for (int t=0;t<T;t++)
	{
		int R,C;
		scanf("%d %d",&R,&C);

		vector <string> vs;
		for(int i=0;i<R;i++)
		{
			char str[256];
			scanf("%s",str);
			vs.push_back(string(str));
		}

		for(int y=0;y<SZ(vs)-1;y++)
		{
			for(int x=0;x<SZ(vs[y])-1;x++)
			{
				if(vs[y][x]=='#'&&vs[y+1][x]=='#'&&vs[y][x+1]=='#'&&vs[y+1][x+1]=='#'&&INRANGE(y+1,0,R-1)&&INRANGE(x+1,0,C-1))
				{
					vs[y][x]='/';
					vs[y+1][x]='\\';
					vs[y][x+1]='\\';
					vs[y+1][x+1]='/';
				}
			}
		}

		bool ok = true;
		for(int y=0;y<SZ(vs);y++)
		{
			for(int x=0;x<SZ(vs[y]);x++)
			{
				if(vs[y][x]=='#')
				{
					ok = false;
					break;
				}
			}
		}

		fprintf(stderr,"Case #%d:\n",t+1);
		printf("Case #%d:\n",t+1);
		if(ok)
		{
			for(int y=0;y<SZ(vs);y++)
			{
				printf("%s\n",vs[y].c_str());
			}
		}
		else
		{
			printf("Impossible\n");
		}
	}

	return 0;
}
