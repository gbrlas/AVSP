#include <iostream>
#include <vector>
#include <utility>

using namespace std;

long long solve(int r, int k, vector<int>& g) {
  int n = g.size(), pos = 0;
  vector<pair<int, long long> > history(n);
  long long ret = 0;
  bool done = false;
  for(int i = 0; i != r; ++i) {
    long long people = 0;
    int start_pos = pos;
    while(people + g[pos] <= k) {
      people += g[pos++];
      if (pos == n)
	pos = 0;
      if (pos == start_pos)
	break;
    }
    ret += people;

    if (!done) {
      if (pos == 0 || history[pos].first) {
	done = true;
	int length = i + 1 - history[pos].first;
	int cycles = (r - i - 1)/length;
	i += cycles*length;
	ret += (ret - history[pos].second)*cycles;
      } else {
	history[pos] = make_pair(i + 1, ret);
      }
    }
  }
  return ret;
}

int main(int argc, char** argv) {
  int t;
  cin >> t;
  for(int i = 0; i != t; ++i) {
    int r, k, n;
    cin >> r >> k >> n;
    vector<int> g(n);
    for(int j = 0; j != n; ++j) {
      int gj;
      cin >> gj;
      g[j] = gj;
    }
    cout << "Case #" << (i + 1) << ": " << solve(r, k, g) << endl;
  }
}
