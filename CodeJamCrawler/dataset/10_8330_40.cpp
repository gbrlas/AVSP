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



int func16(char c)
{
	if('A'<=c && c<='F')
	{
		return c-'A'+10;
	}
	else
	{
		return c-'0';
	}
}

int main()
{
	freopen("_google_code_jam_input.txt","r",stdin);
	freopen("_google_code_jam_output.txt","w",stdout);

	int T;
	scanf("%d ",&T);

	for (int t=0;t<T;t++)
	{
		int M,N;
		scanf("%d %d ",&M,&N);

		vector < vector < int > > field;
		for(int i=0;i<M;i++)
		{
			char str[10000];
			scanf("%s ",str);

			vector < int > tmp1;

			for(int k=0;k<N/4;k++)
			{
				tmp1.push_back(func16(str[k])&8 ? 1 : 0);
				tmp1.push_back(func16(str[k])&4 ? 1 : 0);
				tmp1.push_back(func16(str[k])&2 ? 1 : 0);
				tmp1.push_back(func16(str[k])&1 ? 1 : 0);
			}
			field.push_back(tmp1);
		}

		vector < vector < int > > square_size(field);

		vector < int > maisu(1000);

		while(1)
		{
			for(int y=0;y<SZ(square_size);y++)
			{
				for(int x=0;x<SZ(square_size[y]);x++)
				{
					if(field[y][x]!=-1)
					{
						square_size[y][x]=1;
					}
					else
					{
						square_size[y][x]=0;
					}
				}
			}

			for(int y=1;y<SZ(field);y++)
			{
				for(int x=1;x<SZ(field[y]);x++)
				{
					if( (field[y][x]==1&&field[y-1][x]==0&&field[y][x-1]==0&&field[y-1][x-1]==1) ||
						(field[y][x]==0&&field[y-1][x]==1&&field[y][x-1]==1&&field[y-1][x-1]==0) 
						)
					{
						square_size[y][x]= min(square_size[y-1][x-1], min(square_size[y-1][x], square_size[y][x-1]))+1;
					}
				}
			}

			int biggest = 0;
			int big_x = -1;
			int big_y = -1;

			for(int y=0;y<SZ(square_size);y++)
			{
				for(int x=0;x<SZ(square_size[y]);x++)
				{
					if(square_size[y][x]>biggest)
					{
						biggest=square_size[y][x];
						big_x = x;
						big_y = y;
					}
				}
			}

			if(biggest>=1)
			{
				maisu[biggest]++;

				for(int y=0;y<biggest;y++)
				{
					for(int x=0;x<biggest;x++)
					{
						field[big_y-y][big_x-x]=-1;
					}
				}
			}
			else
			{
				break;
			}
		}

		int ret = 0;
		for(int i=SZ(maisu)-1;i>=1;i--)
		{
			if(maisu[i]>=1)
			{
				ret++;
			}
		}
		fprintf(stderr, "Case #%d: %d\n",t+1,ret);
		printf("Case #%d: %d\n",t+1,ret);
		for(int i=SZ(maisu)-1;i>=1;i--)
		{
			if(maisu[i]>=1)
			{
				printf("%d %d\n",i,maisu[i]);
			}
		}

	}

	return 0;
}