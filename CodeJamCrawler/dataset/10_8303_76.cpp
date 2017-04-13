// topcoder.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

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

static const double EPS = 1e-9;
inline int ROUND(double x) { return (int)(x+0.5); }
inline bool ISINT(double x) { return fabs(ROUND(x)-x)<EPS; }
inline bool ISEQUAL(double x,double y) { return fabs(x-y)<EPS; }
#define INRANGE(x,a,b) ((a)<=(x)&&(x)<=(b))
#define ARRAY_NUM(a) (sizeof(a)/sizeof(a[0])) 
#define SZ(a) ((int)a.size())

using namespace std;

int main(){

     freopen("_google_code_jam_input.txt","r",stdin);
	 freopen("_google_code_jam_output.txt","w",stdout);

	 int T;
	 scanf("%d ",&T);

	 for (int t=0;t<T;t++)
	 {
		ll ret = 0L;
		int R,k,N;
		scanf("%d %d %d ",&R,&k,&N);

		vector <ll> g(N);
		for(int i=0;i<N;i++)
		{
			int tmp;
			scanf("%d ",&tmp);
			g[i] = tmp;
		}

		vector <ll> bonus(N);
		vector <int> next(N);
		for(int i=0;i<N;i++)
		{
			ll sum = 0L;
			int j;
			for(j=0;j<N;j++)
			{
				if(sum+g[(i+j)%N]>k)
				{
					break;
				}
				else
				{
					sum += g[(i+j)%N];
				}
			}
			bonus[i] = sum;
			next[i]=(i+j)%N;
		}

		vector <ll> last_ret(N);
		vector <int> last_r(N,-1);
		bool hasyotta = false;

		int now = 0;
		for(int r=0;r<R;r++)
		{
			if(!hasyotta && last_r[now]!=-1)
			{
				// このグループは先頭にくるのが2回目
				int r_syuki = r-last_r[now];
				ll ret_syuki = ret-last_ret[now];

				int syu = (R-r)/r_syuki;
				ret += ret_syuki* syu;
				r   += r_syuki  * syu;
				r--;
				hasyotta = true;
			}
			else
			{
				last_r[now]=r;
				last_ret[now]=ret;
				ret += bonus[now];
				now = next[now];
			}
		}


		printf("Case #%d: %lld\n",t+1,ret);
	 }

	return 0;
}
