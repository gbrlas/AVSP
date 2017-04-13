#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  int c, d, n;
  int cas = 1;
  while (t--) {
    cin >> c;
    vector<string> cs;
    string str;
    for (int i = 0; i < c; ++i) {
      cin >> str;
      cs.push_back(str);
    }
    cin >> d;
    vector<string> ds;
    for (int i = 0; i < d; ++i) {
      cin >> str;
      ds.push_back(str);
    }
    cin >> n;
    string nstr;
    cin >> nstr;
    vector <char> temp;
    for (int i = 0; i < nstr.size(); ++i) {
      int f = 0;
      char ch = nstr[i];
      if (temp.size() >= 1) {
        int tn = temp.size();
        for (int j = 0; j < cs.size(); ++j) {
          if (ch == cs[j][0] && temp[tn -1] == cs[j][1] || ch == cs[j][1] && temp[tn -1] == cs[j][0]) {
            temp[tn -1] = cs[j][2];
            f = 1;
            break;
          }
        }
      }
      if (f == 0) 
      for (int j = 0; j < ds.size(); ++j) {
        char cha;
        int ff = 0;
        if (ch == ds[j][0]) { ff = 1; cha = ds[j][1]; } 
        if (ch == ds[j][1]) { ff = 1; cha = ds[j][0]; } 
        if (ff == 1) {
          for (int k = 0; k < temp.size(); ++k) {
            if (temp[k] == cha) {
              temp.clear();
              f = 1;
              break;
            }
          }
        }
      }
      if ( f == 0) {
        temp.push_back(ch);
      }
    }
    cout << "Case #" << cas << ": [";
    cas++;
    for (int i = 0; i < temp.size(); ++i) {
      cout << temp[i];
      if (i != temp.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
  }
  return 0;
}
