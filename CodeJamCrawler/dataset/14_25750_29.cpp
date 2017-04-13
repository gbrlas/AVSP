#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;

int power(int x, int y) {
  int ans = 1;
  for(int i = 0; i < y; i++) ans *= x;
  return ans;
}

int trie(vector<string> vs) {
  set<string> st;
  int n = vs.size();
  rep(i, n) {
    int m = vs[i].size();
    for(int j = 0; j <= m; j++) {
      st.insert(vs[i].substr(0, j));
    }
  }
  return st.size();
}

void solve(int N, vector<string> S) {

  int maxNode = 0;
  int numAnswer = 0;

  int M = S.size();

  rep(mask, power(N, M)) {
    //cerr << "mask = " << mask << endl;
    vector<vector<string> > vvs(N);
    rep(i, M) {
      //cerr << (mask / power(N, i)) % N << endl;
      vvs[(mask / power(N, i)) % N].push_back(S[i]);
    }
    int tmp = 0;
    rep(i, N) {
      //cerr << "A";
      tmp += trie(vvs[i]);
      //cerr << "B" << endl;
    }
    if(tmp > maxNode) {
      maxNode = tmp;
      numAnswer = 1;
    }
    else if(tmp == maxNode) {
      numAnswer++;
    }
  }

  cout << maxNode << " " << numAnswer << endl; 
}

int main() {

  //cerr << trie({"AAA", "AAB", "AB", "B"}) << endl;
  //return 0;

  int T;
  cin >> T;

  rep(t, T) {
    int M, N;
    cin >> M >> N;
    vector<string> S(M);
    rep(i, M) {
      cin >> S[i];
    }

    cout << "Case #" << (t+1) << ": ";
    solve(N, S);
  }

  return 0;
}
