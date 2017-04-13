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

		vector < pair <int, int> > orange_dest;
		vector < pair <int,int>  > blue_dest;

		for(int i=0;i<N;i++)
		{
			char str[256];
			int tmp;
			scanf("%s %d ",str,&tmp);
			if(str[0]=='O')
			{
				orange_dest.push_back(make_pair(tmp,i));
			}
			else if (str[0]=='B')
			{
				blue_dest.push_back(make_pair(tmp,i));
			}
		}


		int orange_pos = 1;
		int blue_pos = 1;
		int orange_order = 0;
		int blue_order = 0;
		int order = 0;
		int time = 0;
		while(order<N)
		{
			time++;

			bool orange_push = false;
			bool blue_push = false;

			if(orange_order<SZ(orange_dest) && orange_dest[orange_order].first==orange_pos && orange_dest[orange_order].second == order)
			{
				orange_order++;
				order++;
				orange_push = true;
			}
			else if (blue_order<SZ(blue_dest) && blue_dest[blue_order].first==blue_pos && blue_dest[blue_order].second == order)
			{
				blue_order++;
				order++;
				blue_push = true;
			}

			if(!orange_push && orange_order<SZ(orange_dest))
			{
				if(orange_dest[orange_order].first<orange_pos)
				{
					orange_pos--;
				}
				else if (orange_dest[orange_order].first>orange_pos)
				{
					orange_pos++;
				}
			}

			if(!blue_push && blue_order<SZ(blue_dest))
			{
				if(blue_dest[blue_order].first<blue_pos)
				{
					blue_pos--;
				}
				else if (blue_dest[blue_order].first>blue_pos)
				{
					blue_pos++;
				}
			}
		}

		printf("Case #%d: %d\n",t+1,time);
	 }

	return 0;
}
