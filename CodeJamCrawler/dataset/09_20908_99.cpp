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

int tab[110][110];
char val[110][110];
VI g[110][110];
const int kier[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };

void play(int tnr) {
   int h, w;
   cin >> h >> w;
   REP(x, h) REP(y, w) {
      cin >> tab[x][y];
      val[x][y] = 0;
      g[x][y] = VI(4, 0);
   }
   REP(x, h) REP(y, w) {
      int fk = -1, f = INF, nx, ny;
      REP(k, 4) {
         nx = x+kier[k][0]; ny = y+kier[k][1];
         if (nx>=0 && ny>=0 && nx<h && ny<w && min(tab[x][y],f)>tab[nx][ny]) {
            fk = k;
            f = tab[nx][ny];
         }
      }
      if (fk != -1) {
         nx = x+kier[fk][0]; ny = y+kier[fk][1];
         g[x][y][fk] = g[nx][ny][3-fk] = 1;
      }
   }
   PII qu[h*w];
   int b, e;
   char c='a';
   REP(x, h) REP(y, w) if (val[x][y] == 0) {
      val[x][y] = c;
      qu[b = e = 0] = MP(x, y);
      while (b<=e) {
         int px=qu[b].ST, py=qu[b].ND;
         b++;
         REP(k, 4) if (g[px][py][k]) {
            int nx = px+kier[k][0], ny = py+kier[k][1];
            if (val[nx][ny] == 0) {
               val[nx][ny] = c;
               qu[++e] = MP(nx, ny);
            }
         }
      }
      c++;
   }
   cout << "Case #" << tnr << ":" << endl;
   REP(x, h) {
      REP(y, w)
         cout << val[x][y] << " ";
      cout << endl;
   }
}


int main() {
   ios_base::sync_with_stdio(0);
   int t;
   cin >> t;
   REP(x, t) play(x + 1);
   return 0;
}
