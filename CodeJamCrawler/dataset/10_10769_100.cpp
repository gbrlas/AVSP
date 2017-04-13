#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define all(v) v.begin(), v.end()
#define forint(i, a, b) for (int i = a; i != b; ++i)
#define foreach(i, v) typedef typeof(v) i##_##c;\
  for (i##_##c::iterator i = v.begin(); i != v.end(); ++i)

struct Negative {
  bool operator()(int i) {
    return i < 0;
  }
};

int swaps(vector<int>& x, vector<int>& v, int k, int t) {
  int n = x.size();
  vector<int> cost(n);
  for(int i = n-1; i >= 0; --i) {
    int j = i, c = 0;
    while (j != n - 1) {
      if (t*(v[i] - v[j+1]) <= (x[i] - x[j+1]))
	++j;
      else if (cost[j + 1] == -1) {
	++j;
	++c;
      } else {
	cost[i] = c + cost[j+1];
	break;
      }
    }
    if (j == n - 1) {
      if (t*v[i] >= x[i])
	cost[i] = c;
      else
	cost[i] = -1;
    }
  }
  vector<int>::iterator end = remove_if(all(cost), Negative());
  int left = end - cost.begin();
  if (left < k)
    return -1;
  sort(cost.begin(), end);
  int sum = 0;
  forint(i, 0, k)
    sum += cost[i];
  return sum;
}

int main() {
  int c, n, k, b, t;
  cin >> c;
  for(int i = 0; i != c; ++i) {
    cin >> n >> k >> b >> t;
    vector<int> x, v;
    int y;
    for(int j = 0; j != n; ++j) {
      cin >> y;
      x.push_back(b - y);
    }
    for(int j = 0; j != n; ++j) {
      cin >> y;
      v.push_back(y);
    }
    int s = swaps(x, v, k, t);
    cout << "Case #" << (i+1) << ": ";
    if (s == -1)
      cout << "IMPOSSIBLE";
    else
      cout << s;
    cout << endl;
  }
}
