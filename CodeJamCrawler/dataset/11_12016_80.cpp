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
		char str[256];
		static char combine[256][256];
		memset(combine,0,sizeof(combine));
		static char opposed[256][256];
		memset(opposed,0,sizeof(opposed));

		int C,D,N;
		scanf("%d ",&C);
		for(int i=0;i<C;i++)
		{
			scanf("%s ",str);
			combine[str[0]][str[1]]=
			combine[str[1]][str[0]]=str[2];
		}

		scanf("%d ",&D);
		for(int i=0;i<D;i++)
		{
			scanf("%s ",str);
			opposed[str[0]][str[1]]=
			opposed[str[1]][str[0]]=1;
		}

		scanf("%d ",&N);
		scanf("%s ",str);

		string s;
		for(int i=0;i<N;i++)
		{
			s += str[i];
			if(SZ(s)>=2)
			{
				const char cb = combine[s[SZ(s)-1]][s[SZ(s)-2]];
				if(cb!=0)
				{
					s = s.substr(0,SZ(s)-2);
					s += cb;
				}
				else
				{
					for(int k=0;k<=SZ(s)-2;k++)
					{
						if(opposed[s[k]][s[SZ(s)-1]])
						{
							s.clear();
							break;
						}
					}
				}
			}
		}

		printf("Case #%d: [",t+1);
		for(int i=0;i<SZ(s);i++)
		{
			printf("%c",s[i]);
			if(i!=SZ(s)-1)
			{
				printf(", ");
			}
		}
		printf("]\n");
	 }

	return 0;
}
