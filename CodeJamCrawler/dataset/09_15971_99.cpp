#include <algorithm>
#include <functional>
#include <utility>
#include <iostream>
#include <cmath>
#include <numeric>
#include <complex>

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>

#include <iomanip>
#include <sstream>

#include <cctype>
#include <cstring>
#include <string>

#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <set>
#include <map>

#include <ext/hash_map>
#include <ext/hash_set>

using namespace std;
using namespace __gnu_cxx;

typedef unsigned char uchar;
typedef short int sint;
typedef unsigned short int usint;
typedef unsigned int uint;
typedef long long i64;
typedef unsigned long long ui64;
typedef double dbl;
typedef long double ldbl;

#define pb push_back
#define mp make_pair

#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))

#define PRB "A"

vector<string> split(string pat) {
  vector<string> res;
  int i = 0;
  while(i < pat.length()) {
    if(pat[i] != '(') {
      string a;
      a += pat[i];
      res.pb(a);
      i++;
    }
    else {
      int p = pat.find(')', i + 1);
      res.pb(pat.substr(i + 1, p - i - 1));
      i += p - i + 1;
    }
  }
  return res;
}

bool match(string pat, string w) {
  vector<string> parts = split(pat);
  /*
  cerr << "Pattern: " << pat << endl;
  for(int i = 0; i < parts.size(); i++) {
    cerr << parts[i] << " ";
  }
  cerr << endl;
  */
  int n = w.length();
  for(int i = 0; i < n; i++) {
    if(parts[i].find(w[i]) == string::npos) return false;
  }
  return true;
}

int main() {
  freopen(PRB".in", "r", stdin);
  freopen(PRB".out", "w", stdout);
  int Case, L, D, N;
  cin >> L >> D >> N;
  vector<string> w;
  for(int i = 0; i < D; i++) {
    string t;
    cin >> t;
    if(find(w.begin(), w.end(), t) == w.end()) w.pb(t);
  }
  D = w.size();
  for(Case = 1; Case <= N; Case++) {
    int K = 0;
    string pat;
    cin >> pat;
    for(int i = 0; i < D; i++) {
      if(match(pat, w[i])) K++;
    }
    cout << "Case #" << Case << ": " << K << endl;
  }
  return 0;
}
