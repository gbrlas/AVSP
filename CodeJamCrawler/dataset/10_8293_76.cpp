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
#include "tabaityo/longint.h"
using namespace std;

typedef long long ll;

static const double EPS = 1e-9;
inline int ROUND(double x) { return (int)(x+0.5); }
inline bool ISINT(double x) { return fabs(ROUND(x)-x)<EPS; }
inline bool ISEQUAL(double x,double y) { return fabs(x-y)<EPS; }
#define INRANGE(x,a,b) ((a)<=(x)&&(x)<=(b))
#define ARRAY_NUM(a) (sizeof(a)/sizeof(a[0])) 
#define SZ(a) ((int)a.size())

int main(){

     freopen("_google_code_jam_input.txt","r",stdin);
	 freopen("_google_code_jam_output.txt","w",stdout);


	 int C;
	 scanf("%d ",&C);

	 for (int c=0;c<C;c++)
	 {
		int N;
		scanf("%d ",&N);

		vector <string> vs;
		for (int n=0;n<N;n++)
		{
			char str[1024];
			memset(str,0,sizeof(str));
			scanf("%s ",str);
			vs.push_back(str);
		}

		// 重複除去とソート
		sort(vs.begin(), vs.end());
		vs.resize(unique(vs.begin(),vs.end())-vs.begin());
		N = SZ(vs); // 長さも変わります

		vector <LINT> ls;
		for (int n=0;n<N;n++)
		{
			LINT tmp = lread((char*)vs[n].c_str());
			ls.push_back(tmp);
		}


		LINT zero = lset(0);
		LINT ret;

		if(N>=2)
		{
			vector <LINT> ls_diff(N-1);

			// ls[N-1]との差の絶対値ls_diffを求める
			for (int n=0;n<N-1;n++)
			{
				if(lcmp(ls[n],ls[N-1])==1)
				{
					ls_diff[n]=lsub(ls[n],ls[N-1]);
				}
				else
				{
					ls_diff[n]=lsub(ls[N-1],ls[n]);
				}
			}


			// それらの最大公約数gを求める
			LINT g = ls_diff[0];
			for (int n=1;n<N-1;n++)
			{
				g = lgcd(g,ls_diff[n]);
			}

			// いくら足せば、gの倍数になるか求める
			LINT mod = lmod(ls[0],g);

			if(lcmp(zero,mod)==0)
			{
				ret = zero;
			}
			else
			{
				ret = lsub(g,mod);
			}
		}
		else
		{
			ret = zero;
		}

		// 結果を出力
		printf("Case #%d: ",c+1);

		if(ret.len==0)
		{
			printf("0");
		}
		else
		{
			for(int i=ret.len;i>=1;i--)
			{
				if(i==ret.len)
				{
					printf("%d",ret.num[i]);
				}
				else
				{
					printf("%02d",ret.num[i]);
				}
			}

		}
		printf("\n");
	 }

	return 0;
}
