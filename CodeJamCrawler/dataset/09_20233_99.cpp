#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <set>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < int(b); i++)
#define FOREQ(i, a, b) for(int i = (a); i <= int(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define REP1(i, n) FOREQ(i, 1, n)
#define CLR(a, x) memset(a, x, sizeof(a))

const int MAXD = 5000, MAXL = 20, SZ = 26;
int trie[MAXD*MAXL][SZ], nt;
int L;

set<int> w[MAXL];
int mem[MAXL][MAXD*MAXL];
int go(int p, int t)
{
  if(t == -1) return 0;
  if(p == L) return 1;
  int& ret = mem[p][t];
  if(ret != -1) return ret;
  ret = 0;
  const set<int>& x = w[p];
  for(set<int>::const_iterator it = x.begin(); it != x.end(); ++it)
    ret += go(p+1, trie[t][*it]);
  return ret;
}

int main() {
  cin.sync_with_stdio(false);
  int D, T;
  char c;
  
  CLR(trie, -1);
  nt = 1;
  
  cin>>L>>D>>T;
  REP(j, D)
  {
    int x = 0;
    REP(i, L)
    {
      cin>>c;
      int y = c - 'a';
      if(trie[x][y] == -1) trie[x][y] = nt++;
      x = trie[x][y];
    }
  }
  REP1(run, T)
  {
    cout<<"Case #"<<run<<": ";
    CLR(mem, -1);
    REP(i, L)
    {
      w[i].clear();
      cin>>c;
      if(c != '(') w[i].insert(c - 'a');
      else while(cin>>c && c != ')') w[i].insert(c - 'a');
    }
    cout<<go(0, 0)<<endl;
  }
  return 0;
}
