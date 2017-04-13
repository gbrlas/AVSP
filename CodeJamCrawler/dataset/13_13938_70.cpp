#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 105;

int n, m;
int a[maxn][maxn];
int maxR[maxn], maxC[maxn];

bool check() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if ((a[i][j] < maxR[i]) && (a[i][j] < maxC[j])) return false;
  return true;
}

void solve(int t) {
  cout << "Case #" << t + 1 << ": ";
  for (int i = 0; i < n; i++) maxR[i] = 0;
  for (int i = 0; i < m; i++) maxC[i] = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) 
      maxR[i] = max(maxR[i], a[i][j]);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      maxC[i] = max(maxC[i], a[j][i]);
  if (check()) cout << "YES" << endl;
  else cout << "NO" << endl;
}

int main() {
  int test;
  cin >> test;
  for (int t = 0; t < test; t++ ) {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> a[i][j];
    solve(t);
  }
  return 0;
}
