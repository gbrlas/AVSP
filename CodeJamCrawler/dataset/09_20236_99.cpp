#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < int(b); i++)
#define FOREQ(i, a, b) for(int i = (a); i <= int(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define REP1(i, n) FOREQ(i, 1, n)
#define CLR(a, x) memset(a, x, sizeof(a))

const int DR[4] = {-1, 0, 0, 1};
const int DC[4] = {0, -1, 1, 0};

const int MAX = 101;
int g[MAX][MAX], nr, nc;
char b[MAX][MAX], cur;

inline bool valid(const int r, const int c) { return r >= 0 && r < nr && c >= 0 && c < nc; }

char go(const int r, const int c)
{
  if(!valid(r, c)) return '-';
  else if(b[r][c]) return b[r][c];
  b[r][c] = '_';
  int br = r, bc = c;
  REP(d, 4)
  {
    const int tr = r+DR[d], tc = c+DC[d];
    if(valid(tr, tc) && g[tr][tc] < g[br][bc])
      br = tr, bc = tc;
  }
  return b[r][c] = (r == br && c == bc ? cur++ : go(br, bc));
}

void go()
{
  CLR(b, 0);
  cur = 'a';
  REP(r, nr) REP(c, nc) if(!b[r][c]) go(r, c);
}

int main() {
  cin.sync_with_stdio(false);
  int T;
  cin>>T;
  REP1(run, T)
  {
    cin>>nr>>nc;
    REP(r, nr) REP(c, nc) cin>>g[r][c];
    cout<<"Case #"<<run<<':'<<endl;
    go();
    REP(r, nr) REP(c, nc) cout<<b[r][c]<<(c+1 < nc ? ' ' : '\n');
  }
  return 0;
}
