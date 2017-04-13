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
int C,M,N;

int grille[100][100];
int dyna[1<<12][100];  

int calc(int mask, int i) {
  if (i == -1) return 0;
  int& best = dyna[mask][i];
  if (best != -1) return best;
  best = 0;
  for (int m = 0 ; m < (1<<N) ; m++) {
    if ((m & mask) != 0) continue;
    int cnt = 0;
    bool ok = true;
    int new_mask = 0;
    for (int j = 0 ; j < N ; j++) {
      int cur = ((m>>j)&1);
      int next = ((m>>(j+1)&1));
      if (cur && next) ok = false;      
      if (cur && grille[i][j] == 'x') ok = false;
      cnt += cur;
      if (cur && j > 0) new_mask |= (1<<(j-1));	
      if (cur && j < N-1) new_mask |= (1<<(j+1));
    }
    if (ok) {
      best = max(best, cnt + calc(new_mask, i-1));
    }
  }
  return best;
}

int main() {
  cin>>C;
  for (int tt = 1 ; tt <= C ; tt++) {
    cin>>M>>N;
    fill(*dyna, *dyna + 100*(1<<12), -1);
    cin.ignore();
    for (int i = 0 ; i < M ; i++) {
      for (int j = 0 ;j < N ; j++) {
	char c;
	cin.get(c);
	grille[i][j] = c;
      }
      cin.ignore();
    }
    int res = calc(0, M-1);
    cout << "Case #"<<tt<<": "<<res<<endl;
  }
  return 0;
}
