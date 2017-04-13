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

const char* S = "welcome to code jam";
const int MOD = 10000, MAX = 505, N = 19;
char s[MAX];
int n, mem[MAX][N];

int go(int p, int P)
{
  if(p >= n || P >= N) return 0;
  int& ret = mem[p][P];
  if(ret != -1) return ret;
  ret = go(p+1, P);
  if(S[P] == s[p])
    ret += (P+1 == N) + go(p+1, P+1), ret %= MOD;
  return ret;
}

int main() {
  cin.sync_with_stdio(false);
  cout.fill('0');
  int T;
  cin>>T;
  cin.ignore(INT_MAX, '\n');
  REP1(run, T)
  {
    CLR(mem, -1);
    cin.getline(s, MAX);
    n = cin.gcount()-1; if(s[n]) ++n;
    int ret = go(0, 0);
    cout<<"Case #"<<run<<": "<<setw(4)<<ret<<endl;
  }
  return 0;
}
