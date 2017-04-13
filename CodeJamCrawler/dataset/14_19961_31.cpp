#include <algorithm>
#include <cassert>
#include <cstring>
#include <future>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

struct Input {
  vector<int> v;
};
typedef int Output;

Output solve(Input in) {
  int res = 0, n = in.v.size();
  for(int turn = 0; turn < n; turn++) {
    int pos = 0;
    for(int i = 0; i < n-turn; i++) if(in.v[i] < in.v[pos]) pos = i;
    res += min(pos, n-turn-1-pos);
    in.v.erase(in.v.begin()+pos);
  }
  return res; 
}

Input read() {
  int n;
  Input in;
  cin >> n;
  in.v = vector<int>(n);
  for(int i = 0; i < n; i++) cin >> in.v[i];
  return in;
}

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	vector<future<Output>> result(T);
	for (int cs = 0; cs < T; ++cs) {
		result[cs] = async(launch::async, solve, read());
	}
	for (int cs = 0; cs < T; ++cs) {
		cout << "Case #" << cs+1 << ": " << result[cs].get() << endl;
	}
	return 0;
}
