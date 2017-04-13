#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int T;
  cin >> T;

  vector<int> gs;
  vector<int> sum_mem;
  vector<int> p_delta_mem;
  for (int tcase = 1; tcase <= T; tcase++) {
    int R, seats, groups;
    cin >> R >> seats >> groups;

    gs.resize(groups);
    sum_mem.clear();
    sum_mem.resize(groups);
    p_delta_mem.clear();
    p_delta_mem.resize(groups);
    for (int i = 0; i < groups; i++) {
      cin >> gs[i];
    }

    long long res = 0;
    int p = 0;
    for (int r = 0; r < R; r++) {
      int& sum = sum_mem[p];
      int& delta = p_delta_mem[p];
      if (sum == 0) {
        for (int g = 0; sum + gs[p] <= seats && g < gs.size(); g++) {
          sum += gs[p++];
          p %= gs.size();
          delta++;
        }

      } else {
        p += delta;
        p %= gs.size();
      }
      res += sum;
    }
    cout << "Case #" << tcase << ": " << res << endl;
  }
  return 0;
}
