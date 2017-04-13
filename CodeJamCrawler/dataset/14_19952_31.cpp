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
  int cap;
  vector<int> v;
};
typedef int Output;

Output solve(Input in) {
  sort(in.v.begin(), in.v.end());
  vector<bool> taken(in.v.size(), false);
  int res = 0, en = in.v.size()-1;
  for(int i = 0; i < (int)in.v.size(); ++i) {
    if(taken[i]) continue;
    res++;
    while(en > i && in.v[en] + in.v[i] > in.cap) en--;
    if(en > i && in.v[en] + in.v[i] <= in.cap) { taken[en] = true; en--; }
  }
  return res;
}

Input read() {
  int n;
  Input in;
  cin >> n >> in.cap;
  in.v = vector<int>(n);
  for(int i = 0; i < n; ++i) cin >> in.v[i];
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
