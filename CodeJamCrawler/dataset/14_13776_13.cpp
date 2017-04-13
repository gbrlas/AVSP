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

#define bit(i) ((ull)1 << i)
//-----------------------------------------------------------
//#define DBG
#define MAXN 11000
int N;

int n[MAXN];
bool b[MAXN];
int X;

int ans;

int main() {
	int cases;
	int casenum = 1;
	freopen("input", "r", stdin);
	//freopen("output", "w", stdout);

	scanf("%d", &cases);
	while (cases--) {

		ans = 0;
		scanf("%d%d", &N, &X);
		forn(i, N) {
			scanf("%d", &n[i]);
			b[i] = false;
		}

		sort(n, n + N);

		int count = 0;
		while(count < N) {
			int c = X;
			int limit = 2;
			ans++;
			for(int i = N - 1; i >= 0; i--) {
				if(c >= n[i] && b[i] == false) {
					//printf("%d %d\n", c, n[i]);
					c -= n[i];
					b[i] = true;
					count++;
					limit--;
				}
				if(limit == 0) break;
			}
		}


		//fflush(stdout);

		printf("Case #%d: %d\n", casenum++, ans);
		fflush(stdout);
	}
	return 0;
}
