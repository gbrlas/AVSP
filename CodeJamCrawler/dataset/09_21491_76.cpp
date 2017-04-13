#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

int L, D, N;
vector<string> v;

void do_test (int no) {
  string pattern;
  cin >> pattern;
  vector<vector<bool> > vt;
  int start = 0;
  for (int i = 0; i < L; ++i) {
    vector<bool> t (26, 0);
    if (pattern[start] != '(') {
      t[pattern[start] - 'a'] = true;
      ++start;
    } else {
      ++start;
      while (pattern[start] != ')') {
        t[pattern[start] - 'a'] = true;
        ++start;
      }
      ++start;
    }
    vt.push_back (t);
  }

  int sum = 0;
  for (int i = 0; i < D; ++i) {
    bool is_match = true;
    for (int j = 0; j < L; ++j) {
      if (!vt[j][v[i][j]-'a']) {
        is_match = false;
        break;
      }
    }
    if (is_match)
      ++sum;
  }
  cout << "Case #" << no << ": " << sum << endl;
}


int main (int argc, char **argv) {
  cin >> L >> D >> N;
  for (int i = 0; i < D; ++i) {
    string temp;
    cin >> temp;
    v.push_back (temp);
  }

  for (int i = 1; i <= N; ++i)
    do_test (i);
}
