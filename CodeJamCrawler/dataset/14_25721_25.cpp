#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;

typedef long long ll;

template<class T> ostream& operator<<(ostream& os, vector<T> v) {
  for(T x : v) os << x << ", ";
  return os;
}

typedef vector<vector<int> > board_t;

string solve(int ans1, board_t board1, int ans2, board_t board2) {
  vector<int> l1 = board1[ans1-1];
  vector<int> l2 = board2[ans2-1];

  vector<int> cands;

  for(int i = 1; i <= 16; i++) {
    if(find(l1.begin(), l1.end(), i) != l1.end() && find(l2.begin(), l2.end(), i) != l2.end()) cands.push_back(i);
  }

  if (cands.empty()) {
    return "Volunteer cheated!";
  }
  if (cands.size() == 1) {
    stringstream ss;
    ss << cands[0];
    return ss.str();
  }
  return "Bad magician!";
}

int main() {

  int T;
  cin >> T;

  rep(t, T) {

    int ans1, ans2;
    board_t board1 = board_t(4, vector<int>(4));
    board_t board2 = board1;

    cin >> ans1;
    rep(i, 4) {
      rep(j, 4) {
	cin >> board1[i][j];
      }
    }

    cin >> ans2;
    rep(i, 4) {
      rep(j, 4) {
	cin >> board2[i][j];
      }
    }

    cout << "Case #" << (t+1) << ": " << solve(ans1, board1, ans2, board2) << endl;
  }

  return 0;
}
