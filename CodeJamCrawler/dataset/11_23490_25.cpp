#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <cstring>
#include <cctype>
#include <queue>
#include <list>
#include <cstdlib>
#include <cmath>
#include <deque>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VII;
typedef vector<string> VS;
typedef pair<int,int> para;

#define FOREACH(i,n) for(__typeof((n).begin()) i=((n).begin());i!=(n).end();++i)
#define REP(a,n) for(int a=0;a<(n);a++)
#define PB push_back
#define ALL(v) v.begin(),v.end()
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define MP make_pair
#define F first
#define S second

char buf[3000];

int dupa;

void go(){
  int nc, no, n;
  map<pair<char, char>, char> comp;
  vector<char> op[300];
  map <char,int> counter;

  dupa = scanf("%d",&nc);
  REP(i,nc){
    dupa = scanf("%s",buf);
    char a = buf[0], b = buf[1];
    comp[MP(a,b)] = buf[2];
    comp[MP(b,a)] = buf[2];
  }
  dupa = scanf("%d",&no);
  REP(i,no){
    dupa = scanf("%s",buf);
    char a = buf[0], b = buf[1];
    op[(int)a].PB(b);
    op[(int)b].PB(a);
  }
  dupa = scanf("%d",&n);
  dupa = scanf("%s",buf);
  vector<char> res;
  REP(i,n){
    char a = buf[i];
    if(!res.empty() && comp.count(MP(a,res.back()))>0){
      // comb
      counter[(int)res.back()]--;
      char nextchar = comp[MP(a,res.back())];
      res.pop_back();
      counter[nextchar]++;
      res.PB(nextchar);
    }
    else{
      // opp 
      bool clear = false;
      FOREACH(it, op[(int)a])
        if (counter[*it] > 0){
          clear = true;
          break;
        }
      if (clear){
        res.clear();
        counter.clear();
      }
      else{
        res.PB(a);
        counter[a]++;
      }
    }
  }
  bool next = false;
  printf("[");
  FOREACH(it, res){
    if (next)
      printf(", ");
    printf("%c",*it);
    next = true;
  }
  printf("]\n");
}

int main()
{
  int D;
  dupa = scanf("%d",&D);
  FOR(I,1,D){
    printf("Case #%d: ",I);
    go();
  }
	return 0;
}
