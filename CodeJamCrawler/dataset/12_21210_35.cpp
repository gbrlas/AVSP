// GCJ 2012
// A

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

int main() {
  int tc;
  string s;
  string m = "yhesocvxduiglbkrztnwjpfmaq";
  string res = "";
  
  cin >> tc;
  getline(cin, s);
  for(int t = 1; t <= tc; ++t) {
    getline(cin, s);
    res = "";
    for(int i = 0; i < s.size(); ++i) {
      if(s[i] == ' ') {
        res += ' ';
        continue;
      }
      res += m[s[i]-'a'];
    }
    printf("Case #%d: %s\n", t, res.c_str());
  }
  
  return 0;
}

