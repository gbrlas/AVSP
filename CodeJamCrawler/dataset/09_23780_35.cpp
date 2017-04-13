#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int T;
  cin >> T;

  string line;
  for (int i=1;i<=T;++i) {
    cin >> line;
    cout << "Case #" << i << ": ";
    vector<char> vc;
    for (int i=0;i<line.length();++i)
      vc.push_back(line[i]);
    if (next_permutation(vc.begin(), vc.end())) {
        for (int i=0;i<vc.size();++i)
          cout << vc[i];
    } else {
      //if (vc[0]=='0') {
        vc.clear();
        vc.push_back('0');
        for (int i=0;i<line.length();++i)
          vc.push_back(line[i]);
        if(next_permutation(vc.begin(), vc.end())) {
          for (int i=0;i<vc.size();++i)
            cout << vc[i];
        }
      //}
      /*else {
        for (int i=0;i<vc.size();++i) {
         if (i==1)
           cout << '0';
          cout << vc[i];
        }
      }
      */
    }
    cout << endl;
  }
  return 0;
}

