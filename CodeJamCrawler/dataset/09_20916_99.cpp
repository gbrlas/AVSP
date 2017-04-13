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
#include <sstream>
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

const string pat = "welcome to code jam";
const int l = 19;
const int mod = 10000;

char str[510];
int dp[l+2];

string play(string s) {
   int r = s.length(), sol = 0;
   REP(x, l+2) dp[x] = 0;
   REP(x, r) {
      if (s[x] == pat[l-1]) sol = (sol + dp[l-2]) % mod;
      FORD(y, l - 2, 1) if (s[x] == pat[y]) {
         dp[y] = (dp[y] + dp[y-1]) % mod;
      }
      if (s[x] == pat[0]) dp[0] = (dp[0] + 1) % mod;
   }
   stringstream ss;
   ss << sol;
   ss >> s;
   if (s.length() < 4) s.insert(0, 4-s.length(), '0');
   return s;
}

int main() {
   ios_base::sync_with_stdio(0);
   int n;
   string s;
   cin >> n;
   cin.ignore();
   REP(x, n) {
      cin.getline(str, 510);
      s = str;
      cout << "Case #" << x+1 << ": " << play(s) << endl;
   }
   return 0;
}
