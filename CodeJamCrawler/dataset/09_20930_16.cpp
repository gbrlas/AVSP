#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>
#include <set>
#include <bitset>
#include <map>
#include <queue>
using namespace std;
typedef vector<int> VI;
typedef long long LL;
typedef long double LD;
typedef vector<VI> VVI;
typedef vector<LL> VLL;
typedef vector<double> VD;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
//#define DEBUG
#ifdef DEBUG
#define printd(args...) printf(args)
#else
#define printd(args...)
#endif
#define scand(args...) if(scanf(args) == EOF) { \
   fprintf(stderr, "FATAL ERROR: unexpected end of file\n"); \
   exit(1); \
}
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(),(c).end()
#define SIZE(x) ((int)(x).size())
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define PB push_back
#define ST first
#define ND second
#define PF push_front
#define MP make_pair
const int INF = 1000000001;
const double EPS = 10e-9;

char T[50][50];

int play(int n) {
   int sol = 0;
   VI a, b;
   REP(x, n) {
      int y = n-1;
      while (y > 0 && T[x][y] == '0') y--;
      a.PB(y);
   }
   REP(x, n) b.PB(x);
   REP(x, n) {
      //REP(z, n) cout << b[z] << " "; cout << endl;
      int v = -1;
      FOR(y, x, n-1) if (a[b[y]] <= x) {
         v = y;
         break;
      }
      //cout << "sol += " << v-x << endl;
      sol += v-x;
      int w = b[v];
      FORD(y, v-1, x) b[y+1] = b[y];
      b[x] = w;
   }
   return sol;
}

int main() {
   int t;
   cin >> t;
   REP(x, t) {
      int n;
      cin >> n;
      cin.ignore();
      REP(y, n) {
         cin.getline(T[y], n+3);
      }
      cout << "Case #" << x+1 << ": " << play(n) << endl;
   }
   return 0;
}
