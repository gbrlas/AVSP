#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

void solve(int test) {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > g(n, vector<int> (m));
    vector<bool> lines(n, true);
    vector<bool> columns(m, true);
    int cs = m, ls = n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> g[i][j];
    bool not_changed = false;
    while (!not_changed && ls > 0 && cs > 0) {
        int minh = 101;
        not_changed = true;
        for (int i = 0; i < n; ++i) {
            minh = min(minh, *min_element(g[i].begin(), g[i].end()));
        }
        for (int i = 0; i < n; ++i)
            if (lines[i]) {
                bool eq = true;
                for (int j = 0; j < m; ++j)
                    if (columns[j])
                        eq = eq && minh == g[i][j];
                if (eq) {
                    lines[i] = false;
                    ls--;
                    not_changed = false;
                    for (int j = 0; j < m; ++j)
                        g[i][j] = 101;
                }
            }
        for (int j = 0; j < m; ++j)
            if (columns[j]) {
                bool eq = true;
                for (int i = 0; i < n; ++i)
                    if (lines[i])
                        eq = eq && minh == g[i][j];
                if (eq) {
                    columns[j] = false;
                    cs--;
                    not_changed = false;
                    for (int i = 0; i < n; ++i)

                        g[i][j] = 101;
                }
            }
    }
    if (cs == 0 || ls == 0)
        cout << "Case #" << test << ": YES" << endl;
    else
        cout << "Case #" << test << ": NO" << endl;
    return;
}

int main() {
    freopen("B-small-attempt1.in", "r", stdin);

    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    /*  if (!(cin >> t))
      {
          cout << 123;
          return 0;
      }*/
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }
    cout.flush();
    return 0;
}
