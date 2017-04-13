#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <bitset>
#include <sstream>

using namespace std;
//-----------------------------------------------------------
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const ull inf64 = ((ull)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
//-----------------------------------------------------------

#define MAXN 10100
int N;
ll E, R;
ll v[MAXN];

int main()
{
	int cases;
	int casenum = 1;
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);

	scanf("%d", &cases);
	while(cases--)
	{

		scanf("%lld%lld%d", &E, &R, &N);
		forn(i, N){
			scanf("%lld", &v[i]);
		}

		ll g = 0;
		ll c = E;

		forn(i, N){
			//printf("(%d: %d) %d now\n", i, v[i], c);

			// use? use how many?
			int tmpi = 0;
			ll tmpc = R;
			ll tmpn = 0;
			ll need = 0;

			for(int j = i + 1; j < N; j++){
				// 1. 下個高峰前，必須用掉一些 or用不滿
				// 2. 沒有下個高峰，用完
				if( v[i] <= v[j] ){
					tmpn = v[j];
					tmpi = j;

					need = tmpc + c - E;
					if( need < 0 ) need = 0;
					break;
				}
				tmpc += R;
				if( tmpc > E ) break;
			}

			if(tmpn == 0){
				// case 2.

				g += c * v[i];
				//printf("[2]: %lld, g = %lld\n", c, g);
				c = 0;
			} else {
				// case 1.

				g += (need) * v[i];
				//printf("[1]: %lld, g = %lld\n", need, g);
				c -= need;
			}
			c += R;
		}


		printf("Case #%d: %lld\n", casenum++, g);

	}
	return 0;
}

