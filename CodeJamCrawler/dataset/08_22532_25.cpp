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
  
string S;
int K;
  
int perm[20];

int count_groups(vector<char>& ns) {
  int nb = 1;
  for (int i = 1 ;i < ns.size() ;i++) {
    if (ns[i] != ns[i-1]) nb++;
  }
  return nb;
}

int min_groups() {
  for (int i = 0 ; i < K ; i++) perm[i] = i;
  int best = 1000000;
  do {
    vector<char>ns(S.size());
    for (int start = 0 ; start < S.size() ; start += K) {
      for (int i = 0 ; i < K ; i++) {
	ns[i + start] = S[ perm[i] + start ];
      }
    }
    best = min(best, count_groups(ns));
  } while(next_permutation(perm, perm + K));
  return best;
}

int main() {
  int N;
  cin>>N;
  for (int tt = 1 ; tt <= N ; tt++) {
    cin>>K; cin.ignore();
    cin>>S;
    int res = min_groups();
    cout << "Case #"<<tt<<": "<<res<<endl;
  }

  return 0;
}
