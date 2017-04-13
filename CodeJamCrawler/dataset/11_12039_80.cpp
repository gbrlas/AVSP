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

// 完全順列の数（モンモール数）
// 全部バラバラに射影される順列の数。
// (1,2,3)だったら(2,3,1) (3,1,2)の2通り。nofixedperm[3]=2となります。
const int MAX_N = 1005;
static double nofixedperm[MAX_N];
void init_no_fixed_point_permutation()
{
	memset(nofixedperm,0,sizeof(nofixedperm));
	nofixedperm[0]=1.0;
	nofixedperm[1]=0.0;
	for(int i=2;i<MAX_N;i++)
	{
		nofixedperm[i] = ((i-1.0)*(nofixedperm[i-1]+nofixedperm[i-2]));
	}
}

// 組み合わせ
static double combi[MAX_N][MAX_N];
void init_combination()
{
	memset(combi,0,sizeof(combi));
	combi[1][0]=1.0;
	combi[1][1]=1.0;
	for(int i=2;i<MAX_N;i++)
	{
		combi[i][0]=1.0;
		for(int k=1;k<MAX_N;k++)
		{
			combi[i][k]=(combi[i-1][k]+combi[i-1][k-1]);
		}
	}
}

// 階乗
static double fact[MAX_N];
void init_fact()
{
	memset(fact,0,sizeof(fact));
	fact[0] = 1.0;
	fact[1] = 1.0;
	for(int i=2;i<MAX_N;i++)
	{
		fact[i] = fact[i-1]*i;
	}
}



int main()
{
    freopen("_google_code_jam_input.txt","r",stdin);
	freopen("_google_code_jam_output.txt","w",stdout);

	init_no_fixed_point_permutation();
	init_combination();
	init_fact();

	double goro[MAX_N];	// ゴロソートで全部バラバラのやつをそろえるまでの回数
	goro[0] = 0.0;
	goro[1] = 0.0;
	goro[2] = 2.0;
	for(int i=3;i<MAX_N;i++)
	{
		goro[i] = 0.0;
		for(int k=0;k<i;k++)
		{
			// ゴロソートしたのに、まだk個バラバラなパターンの数
			// 

			goro[i] += goro[k]*combi[i][i-k]*nofixedperm[k];
		}
		goro[i] += fact[i];
		goro[i] /= (fact[i]-nofixedperm[i]);
	}

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
			vi.push_back(tmp-1);
		}

		vector <bool> used(N);

		double ret = 0.0;
		for(int start=0;start<N;start++)
		{
			if(!used[start])
			{
				int now = start;
				int cycle = 0;
				do
				{
					used[now]=true;
					now = vi[now];
					cycle++;
				} while(now!=start);

				ret += goro[cycle];
			}
		}


		printf("Case #%d: %.16f\n",t+1,ret);
	 }

	return 0;
}
