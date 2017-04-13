//
// Problem D for round 2 in Google Code Jam 2008
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int N, k;
string s;
vector<int> nums;

int main() {
  freopen("perm.in", "r", stdin);
  freopen("perm.out", "w", stdout);
  cin >> N;
  for (int c = 1; c <= N; ++c) {
    cin >> k;
    cin >> s;
    nums.clear();
    for (int i = 0; i < k; ++i) nums.push_back(i);
    int best = 10000;
    do {
      string ts = "";
      int size = s.size() / k;
      for (int i = 0; i < size; ++i) {
	string tmp = "";
	for (int j = 0; j < k; ++j) {
	  tmp += s[i * k + nums[j]];
	}
	ts += tmp;
      }
      //cout << ts << endl;
      int len = 0;
      char last = '~';
      for (int i = 0; i < (int) ts.size(); ++i) {
	if (ts[i] != last) {
	  ++len;
	  last = ts[i];
	}
      }
      best = (len < best) ? len : best;
    } while (next_permutation(nums.begin(), nums.end()));

    cout << "Case #" << c << ": " << best << endl;
  }

  return 0;
}
