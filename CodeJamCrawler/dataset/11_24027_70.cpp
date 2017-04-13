#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cassert>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;
#define DB(x) { cerr << #x << ": " << x << " "; }
#define forn(i, n)  for (int i = 0; i < (int)(n); ++i)
#define sqr(x) ((x)*(x))
typedef long double ld;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int,int> pii;
const ld PI = acos(-1.0);

const int N = 26;
char replaces[N][N];
int bad[N][N];

vector<char> solve() {
  memset(replaces, 0, sizeof replaces);
  memset(bad, 0, sizeof bad);

  int n;
  cin >> n;
  forn(i, n) {
    string s;
    cin >> s;
    replaces[s[0]-'A'][s[1]-'A'] = s[2];
    replaces[s[1]-'A'][s[0]-'A'] = s[2];
  }

  cin >> n;
  forn(i, n) {
    string s;
    cin >> s;
    bad[s[0]-'A'][s[1]-'A'] = 1;
    bad[s[1]-'A'][s[0]-'A'] = 1;
  }

  string s;
  cin >> n >> s;
  vector<char> ret;
  forn(i, s.size()) {
    ret.push_back(s[i]);
    while (ret.size() >= 2) {
      char ch = replaces[ret[ret.size() - 2] - 'A'][ret[ret.size() - 1] - 'A'];
      if (ch) {
        ret.pop_back();
        ret.pop_back();
        ret.push_back(ch);
      } else
        break;
    }
    forn(k, ret.size()) forn(t,ret.size())
      if (bad[ret[k] - 'A'][ret[t] - 'A'])
        ret.clear();
  }
  return ret;
}

int main() {
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);
  //ios_base::sync_with_stdio(0);

  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    vector<char> s = solve();
    cout << "[";
    for (int i = 0; i < s.size(); i++) {
      if (i) cout << ", ";
      cout << s[i];
    }
    cout << "]" << endl;
  }
  return 0;
}

