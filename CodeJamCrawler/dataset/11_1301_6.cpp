#include <iostream>

using namespace std;

int main() {
  int t;
  cin>>t;
  for (int tt = 1; tt <= t; ++tt) {
    int d, pd, pg;
    cin>>d>>pd>>pg;
    bool ans = false;
    if (!(((pd > 0) && (pg == 0)) || ((pd < 100) && (pg == 100)))) {
      for (int i = 1; i <= d; ++i) {
        if (((i * pd) % 100) == 0) {
          ans = true;
        }
      }
    }
    cout<<"Case #"<<tt<<": "<<(ans ? "Possible" : "Broken")<<endl;
  }
  return 0;
}
