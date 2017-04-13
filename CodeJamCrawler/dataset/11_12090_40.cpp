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

	int TEST;
	scanf("%d ",&TEST);

	for (int test=0;test<TEST;test++)
	{
		ll L,t,N,C;
		scanf("%lld %lld %lld %lld",&L,&t,&N,&C);

		vector <ll> mini_dist;
		for(int c=0;c<C;c++)
		{
			ll tmp;
			scanf("%lld ",&tmp);
			mini_dist.push_back(tmp);
		}

		vector <ll> all_dist;
		vector <ll> sum_dist;
		ll sum = 0;
		for(int n=0;n<N;n++)
		{
			all_dist.push_back(mini_dist[n%C]);
			sum += mini_dist[n%C];
			sum_dist.push_back(sum);
		}

		ll best_time = (ll)BIG*(ll)BIG;

		if(L==2)
		{
			for(int a=0;a<N;a++)
			{
				for(int b=a+1;b<N;b++)
				{
					ll time = 0;
					// シミュレート

					// ブーストaの手前までとぶ
					if(a>=1)
					{
						time += sum_dist[a-1]*2LL;
					}
					// ブーストa使用。ただし、完成が間に合わないときや、途中で完成ケースもあるので注意
					if(time>=t)
					{
						// フルでつかえる
						time += all_dist[a];
					}
					else if (time+all_dist[a]*2LL<t)
					{
						// ブーストまったく使えず
						time += all_dist[a]*2LL;
					}
					else
					{
						// dtたったら、途中からブースト可能
						ll dt = t-time;
						time += dt + (all_dist[a]-dt/2);
					}

					// ブーストbの手前まで飛ぶ
					time += (sum_dist[b-1]-sum_dist[a])*2LL;

					// ブーストb使用
					if(time>=t)
					{
						// フルでつかえる
						time += all_dist[b];
					}
					else if (time+all_dist[b]*2LL<t)
					{
						// ブーストまったく使えず
						time += all_dist[b]*2LL;
					}
					else
					{
						// dtたったら、途中からブースト可能
						ll dt = t-time;
						time += dt + (all_dist[b]-dt/2);
					}

					// ゴールまで飛ぶ
					time += (sum_dist[N-1]-sum_dist[b])*2LL;

					// ゴール
					best_time = min(best_time,time);
				}
			}
		}
		else if (L==1)
		{
			for(int a=0;a<N;a++)
			{
				ll time = 0;
				// シミュレート

				// ブーストaの手前までとぶ
				if(a>=1)
				{
					time += sum_dist[a-1]*2LL;
				}
				// ブーストa使用。ただし、完成が間に合わないときや、途中で完成ケースもあるので注意
				if(time>=t)
				{
					// フルでつかえる
					time += all_dist[a];
				}
				else if (time+all_dist[a]*2LL<t)
				{
					// ブーストまったく使えず
					time += all_dist[a]*2LL;
				}
				else
				{
					// dtたったら、途中からブースト可能
					ll dt = t-time;
					time += dt + (all_dist[a]-dt/2);
				}


				// ゴールまで飛ぶ
				time += (sum_dist[N-1]-sum_dist[a])*2LL;

				// ゴール
				best_time = min(best_time,time);
			}
		}
		else if (L==0)
		{
			best_time = sum_dist[N-1]*2LL;
		}

		printf("Case #%d: %d\n",test+1,best_time);
		fprintf(stderr,"Case #%d: %d\n",test+1,best_time);
	}

	return 0;
}
