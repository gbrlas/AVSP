#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <set>
#include <numeric>

using namespace std;
  
#define SS 150
#define QQ 1100

int dyna[SS][QQ];

int S;
vector<string> engines;
int Q;
vector<string> queries;
  
int nb_switches(int e, int q) {
  if (q == Q) return 0;
  int& best = dyna[e][q];
  if (best != -1) return best;
  best = 1000000000;
  for (int ne = 0 ; ne < S ; ++ne) {
    if (engines[ne] == queries[q]) continue;
    best = min(best, nb_switches(ne, q+1) + (e != ne));
  }
  return best;
}

int main() {
  int N;
  cin>>N;
  for (int tt = 0 ; tt < N ; tt++) {
    cin>>S;
    cin.ignore();
    engines.clear();
    for (int i = 0 ; i < S ; i++) {
      string s;
      getline(cin, s);
      engines.push_back(s);
    }
    cin>>Q;
    cin.ignore();
    queries.clear();
    for (int i = 0 ; i < Q ; i++) {
      string s;
      getline(cin, s);
      queries.push_back(s);
    }
    fill(*dyna, *dyna + SS*QQ, -1);
    int res = nb_switches(SS-1, 0) - 1;
    if (res < 0) res = 0;
    cout << "Case #" << tt+1 << ": " << res << endl;
  }

  return 0;
}
