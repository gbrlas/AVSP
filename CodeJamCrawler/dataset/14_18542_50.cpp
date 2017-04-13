#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <deque>
#include <complex>
#include <string>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <valarray>
#include <iterator>
using namespace std;
typedef long long int lli;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define RREP(i,x) for(int i=(x);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();i++)
#define ALL(container) container.begin(), container.end()
#define SZ(container) ((int)container.size())

const int INF = 1<<28;
const double EPS = 1e-8;
const int MOD = 1000000007;


int T, n;

int mergecount(vector<int> &a) {
  int count = 0;
  int n = a.size();
  if (n > 1) {
    vector<int> b(a.begin(), a.begin() + n/2);
    vector<int> c(a.begin() + n/2, a.end());
    count += mergecount(b);
    count += mergecount(c);
    for (int i = 0, j = 0, k = 0; i < n; ++i)
      if (k == c.size())       a[i] = b[j++];
      else if (j == b.size())  a[i] = c[k++];
      else if (b[j] <= c[k])   a[i] = b[j++];
      else                   { a[i] = c[k++]; count += n/2 - j; }
  }
  return count;
}

main(){
	cin >> T;
	REP(t, T){
		int N;
		cin >> N;
		vector<int> x(N);
		REP(i, N) cin >> x[i];
		int mx = *max_element(ALL(x));
		int ans = INF;
		REP(i, 1<<N){
			vector<int> y1(N);
			REP(j, N){
				y1[j] = ( x[j] == mx || ((i>>j)&1) ) ? x[j] : 2*mx - x[j];
			}
			ans = min(ans, mergecount(y1));
		}
		printf("Case #%d: %d\n", t+1, ans);
	}
	return 0;
}
