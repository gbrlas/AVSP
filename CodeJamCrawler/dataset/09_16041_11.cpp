#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>

using namespace std;

int a[40];
int N;
typedef long long ll;

map<string,bool> f;

ll solve() {
  ll ans = 0;
  f.clear();
  queue<string> q;
  string cur;
  for(int i = 0; i < N; i++) {
    cur += i + '0';
  }
  q.push(cur);
  f[cur] = true;
  while(!q.empty()) {
    int sz = q.size();
    while(sz--) {
      cur = q.front();
      q.pop();
      // solved ???
      bool ok = true;
      for(int i = 0; i < N; i++) {
        int row = cur[i] - '0';
        // must a[row] <= i
        if(a[row] > i) {
          ok = false;
          break;
        }
      }
      if(ok) return ans;
      
      // spawn states
      for(int i = 0; i < N - 1; i++) {
        char t = cur[i];
        cur[i] = cur[i+1];
        cur[i+1]=t;
        if(!f[cur]) {
          q.push(cur);
          f[cur] = true;
        }
        t = cur[i];
        cur[i] = cur[i+1];
        cur[i+1]=t;
      }
    }
    ans++;
  }
  return ans;
}

int main() {
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  int T;
  cin >> T;
  for(int cs = 1; cs <= T; cs++) {
    cin >> N;
    string t;
    for(int i = 0; i < N; i++) {
      cin >> t;
      int r = 0;
      for(int j = N - 1; j >= 0; j--) {
        if(t[j] > '0') {
          r = j;
          break;
        }
      }
      a[i] = r;
    }
    cout << "Case #" << cs << ": " << solve() << endl;
    
  }
  return 0;
}

