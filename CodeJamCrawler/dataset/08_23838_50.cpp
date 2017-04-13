#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

#define INF (INT_MAX)
#define REP(i,n) for(int i = 0; i < n; i ++)
#define FOR(i,s,n) for(int i = s; i < n; i ++)
#define pb push_back

void solve() {
  int s, q, ans  = 0;
  static int kase = 0; kase++;
  scanf("%d\n", &s);
  
  vector<string> search;
  map<string, int> Loc;
  REP(i, s) {
    string temp; getline(cin, temp); 
    search.pb(temp);
    Loc[temp] = i;
  }
  
  scanf("%d\n", &q);
  vector<string> queries;
  REP(i, q) {
    string qu; getline(cin, qu);
    queries.push_back(qu);
  }
  
  if(q == 0) {
    printf("Case #%d: 0\n", kase);
    return;
  }
  int pos[200];
  string sch = queries[0];
  REP(i, q) {
    string curr = queries[i];
    if(curr == sch) { 
      REP(j, s) pos [j] = INF;
      FOR(j, i, q) pos[Loc[queries[j]]] <?= j;
      int next = -1;
      REP(j, s) if(pos[j] > next) {
        next = pos[j];
        sch = search[j];
      }
      ans ++;
    }
  }
  
  cout << "Case #" << kase << ": " << ans-1 << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--) { solve(); }
  return 0;
}