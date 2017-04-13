#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  int t;
  cin>>t;
  for (int tt = 1; tt <= t; ++tt) {
    int n;
    cin>>n;
    queue< int > gq;
    vector< queue< int > > q(2);
    for (int i = 0; i < n; ++i) {
      int x;
      char ch;
      cin>>ch>>x;
      int p = (ch == 'O') ? 0 : 1;
      gq.push(p);
      q[p].push(x);
    }
    int ct = 0;
    vector< int > p(2, 1);
    for (; !gq.empty(); ++ct) {
      bool pop = false;
      for (int i = 0; i < q.size(); ++i) {
        if (!q[i].empty()) {
          if (q[i].front() == p[i]) {
            if (gq.front() == i) {
              pop = true;
            }
          } else {
            p[i] += (q[i].front() - p[i]) / abs(q[i].front() - p[i]);
          }
        }
      }
      if (pop) {
       q[gq.front()].pop();
       gq.pop();
      }
    }
    cout<<"Case #" << tt << ": " <<ct<<endl;
  }
  return 0;
}
