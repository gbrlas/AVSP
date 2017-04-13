#include <map>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {
  int test = 0, tc;
  string res;
  for (cin >> tc; test < tc; ++test) {
    map<pair<char, char>, char> combines;
    map<char, string> opposites; 
    map<char, int> exists;
    string current;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i){
      string s;
      cin >> s;
      combines[make_pair(s[0], s[1])] = combines[make_pair(s[1], s[0])] = s[2];
    }
    cin >> n;
    for (int i = 0; i < n; ++i){
      string s;
      cin >> s;
      opposites[s[0]] += s[1];
      opposites[s[1]] += s[0];
    }
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
      if (current == "") {
        exists[s[i]]++;
        current += s[i];
        continue;
      }
      char last = current[current.size() - 1];
      if (combines.find(make_pair(last, s[i])) != combines.end()) {
        exists[last]--;
        current[current.size() - 1] = combines[make_pair(last, s[i])];
        continue;
      }
      bool cleared = false;
      for (int j = 0; j < opposites[s[i]].size(); ++j) {
        char o = opposites[s[i]][j];
        if (exists[o] > 0) {
          exists.clear();
          current = "";
          cleared = true;
          break;
        }
      }
      if (!cleared) {
        exists[s[i]]++;
        current += s[i];
      }
    }
    res = "[";
    for (int i = 0; i < current.size(); i++) {
      if (i) res += ", ";
      res += current[i];
    }
    res += "]";
    cout << "Case #" << test + 1 << ": " << res << endl;
  }
  return 0;
}
