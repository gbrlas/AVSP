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

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
//-----------------------------------------------------------

#define MAXN 110

int N, M;
int m[ MAXN ][ MAXN ];

vector<int> x[ MAXN ];
vector<int> y[ MAXN ];

int main()
{
	int cases;
	int casenum = 1;
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);

	scanf("%d", &cases);
	while(cases--)
	{
		scanf("%d%d", &N, &M);

		bool isPossible = true;

		// init
		forn(i, MAXN){
			x[ i ].clear();
			y[ i ].clear();
		}

		// read
		forn(i, N){
			forn(j, M){
				scanf("%d", &m[i][j]);
				x[ m[i][j] ].pb(i);
				y[ m[i][j] ].pb(j);
			}
		}

		//printf("");

		// search
		forn(n, MAXN){
			forn(k, x[n].size()){
				int row = x[n][k];
				int col = y[n][k];
				int rc = 0;
				int cc = 0;

				for(rc = 0; rc < N; rc++){
					//printf("r: %d %d\n", m[rc][col] , m[row][col]);
					if( m[rc][col] > m[row][col] ) break;
				}
				for(cc = 0; cc < M; cc++){
					//printf("c: %d %d\n", m[row][cc] , m[row][col]);
					if( m[row][cc] > m[row][col] ) break;
				}
				//printf("[%d %d]: %d ==> r%d c%d\n", row, col, m[row][col], rc, cc);

				if( rc != N && cc != M ) {
					isPossible = false;
					break;
				}
			}
		}

		printf("Case #%d: %s\n", casenum++, (isPossible ? "YES" : "NO"));
	}
	return 0;
}

