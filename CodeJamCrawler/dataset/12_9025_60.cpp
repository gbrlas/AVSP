#include <algorithm>
#include <cassert>
#include <cstdio>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define ASSERT_ for (;;) {}
#define PII pair<int, int>
using namespace std;

int main() {
  int T, S, p, N;
  cin >> T;
  for (int testcase = 1; testcase <= T; testcase++) {
    cin >> N >> S >> p;
    vector<int> v;
    for (int i = 0; i < N; i++) {
      int tmp;
      cin >> tmp;
      v.push_back(tmp);
    }
    sort(v.begin(), v.end(), greater<int>());
    //cout << v[0] << v[1] << endl;
    //for_each(v.begin(), v.end(), ) // zmień na ładnego foreacha
    int res = 0;
    for (unsigned i = 0; i < v.size(); i++) {
      if (v[i] >= p + 2*max(p-1, 0))
        res++;
      else if (v[i] >= p + 2*max(p-2, 0) && S > 0) {
        S--;
        res++;
      }
    }
    cout << "Case #" << testcase << ": " << res << endl;
  }

  return 0;
}
