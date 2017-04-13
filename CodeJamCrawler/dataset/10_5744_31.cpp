#include<iostream>
#include<sstream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<utility>
#include<iterator>
#include<functional>

#include<cstdio>
#include<cstdlib>
#include<climits>

using namespace std;

#define FOR(i,a,n) for(int i = (int)(a); i < (int)(n); i++)
#define REP(i,n) FOR(i,0,n)
#define FOR_EACH(i,v) for(__typeof((v).begin())i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(), (v).end()
#define MP make_pair

int tab[11][1<<11][11];
int tickets[11][1<<11];
int must[1<<11];
const int MAXVAL = 1000000000;
int dfs(const int &p, int idx, int depth = 0, int buy = 0){
  if(depth >= p){
    //    cerr << idx << " " << buy << " " << must[idx] << endl;
    int ret;
    if(must[idx] <= buy) ret = 0;
    else ret = MAXVAL;
    //    cerr << " " << ret << endl;
    return ret;
  }
  else if(tab[depth][idx][buy] >= 0) return tab[depth][idx][buy];
  int& ret = tab[depth][idx][buy];
  ret = MAXVAL;
  return ret = min(ret, 
		   min(dfs(p, idx*2, depth+1, buy) + dfs(p, idx*2+1, depth+1, buy),
		       dfs(p, idx*2, depth+1, buy+1) + dfs(p, idx*2+1, depth+1, buy+1) 
		       + tickets[p - (depth + 1)][idx]));
    
}
int main(){
  int t; cin >> t;
  REP(case_no, t){
    memset(tab, -1, sizeof(tab));
    int p; cin >> p;
    REP(i, 1<<p) {cin >> must[i]; must[i] = p - must[i]; }
    //    REP(i, 1<<p) cerr << must[i] << " " ; cerr << endl;
    REP(i, p){
      REP(j, 1<<(p - i - 1)) cin >> tickets[i][j];
    }
    cout << "Case #" << case_no+1 << ": " << dfs(p, 0) << endl;;
  }
  return 0;
}
