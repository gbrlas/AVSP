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
typedef pair<int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const ull inf64 = ((ull) 1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
//-----------------------------------------------------------

#define MAXN 110
int A, N;
int m[ MAXN ];

int main() {
	int cases;
	int casenum = 1;
	freopen("input", "r", stdin);
	//freopen("output", "w", stdout);

	scanf("%d", &cases);
	while (cases--) {

		scanf("%d%d", &A, &N);
		forn(i, N) {
			scanf("%d", &m[ i ]);
		}

		sort(m, m + N);

		int left = N;
		int ans = INT_MAX;
		int a = A;
		int o = 0;
		forn(i, N) {
			// delete or insert
			if( m[i] >= a ){

				if( a > 1 ){
					// 1. insert
					int maxa = a;
					int cana = 0;
					while( maxa <= m[i] ){
						maxa = maxa + maxa - 1;
						cana++;
					}
					//printf("%d => can %d\n", m[i], cana);

					// 2. delete
					ans = min( ans, o + left );

					a = maxa + m[i];
					o += cana;
				} else {
					o++;
				}
				////////
			}
			// absorb
			else if( m[i] < a ){
				a += m[i];
			}
			left--;
			//printf("%d => %d\n", a, o);
			//printf("%d ", m[ i ]);
		}

		ans = min( ans, o );

		printf("Case #%d: %d\n", casenum++, ans);

	}
	return 0;
}
