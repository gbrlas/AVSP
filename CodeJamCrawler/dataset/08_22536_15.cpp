#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <set>
#include <numeric>

using namespace std;
int C;
int H,W,R;
bool rocks[200][200];

int dyna[200][200];
int dir[2][2] = {{2,1},{1,2}};
int calc(int r, int c) {
  if (rocks[r][c]) return 0;
  if (r==H && c == W) {
    return 1;
  }
  int &num = dyna[r][c];
  if (num != -1) return num;
  num = 0;
  for (int d = 0 ; d < 2 ; d++) {
    int nr = r + dir[d][0];
    int nc = c + dir[d][1];
    if (nr > H || nc > W) continue;
    num += calc(nr, nc);
  }
  num %= 10007;
  return num;
}

int main() {
  cin>>C;
  for (int tt = 1 ; tt <= C ; tt++) {
    cin>>H>>W>>R;   
    fill(*rocks, *rocks + 200*200, false);
    fill(*dyna, *dyna + 200*200, -1);
    for (int i = 0 ; i < R ; i++) {
      int r,c;
      cin>>r>>c;
      rocks[r][c] = true;
    }

    int res = calc(1, 1);
    cout << "Case #"<<tt<<": "<<res<<endl;
  }
  return 0;
}
