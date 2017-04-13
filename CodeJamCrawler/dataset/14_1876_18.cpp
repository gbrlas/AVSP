#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()

template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }
template <class _T> inline istream& operator << (istream& is, const _T& a) { is.putback(a); return is; }

// Types
typedef long double ld;
typedef signed   long long i64;
typedef signed   long long ll;
typedef unsigned long long u64;
typedef unsigned long long ull;
typedef set < int > SI;
typedef vector < ld > VD;
typedef vector < int > VI;
typedef vector < bool > VB;
typedef vector < string > VS;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

//#define debug(...)
#define debug printf

int N;

struct Token {
  char ch;
  int cnt;

  Token(char tch, int tcnt): ch(tch), cnt(tcnt) {}
};

vector<vector<Token>> words;

vector<Token> convert(string& s) {
  vector<Token> result;

  char ch = s[0];
  int cnt = 1;
  for (unsigned i = 1; i < s.size(); ++i) {
    if (s[i] == ch) {
      cnt++;
    } else {
      result.push_back(Token(ch, cnt));
      ch = s[i];
      cnt = 1;
    }
  }
  result.push_back(Token(ch, cnt));

  return result;
}

void dump(const vector<Token>& word) {
  for (auto t : word) {
    cout << "(" << t.ch << " " << t.cnt << ")";
  }
  cout << endl;
}

bool ok() {
  unsigned L = words[0].size();

  for (int i = 1; i < N; ++i) {
    if (words[i].size() != L) return false;

    for (unsigned j = 0; j < L; ++j) {
      if (words[i][j].ch != words[0][j].ch) return false;
    }
  }

  return true;
}

int solve() {
  unsigned L = words[0].size();

  int total_action = 0;
  int cnt;
  for (unsigned i = 0; i < L; ++i) {
    cnt = 0;
    for (int j = 0; j < N; ++j) {
      cnt += words[j][i].cnt;
    }

    int min_action = INT_MAX;
    int min_l = cnt / N;
    int max_l = cnt / N + 1;

    for (int l = min_l; l <= max_l; ++l) {
      int action = 0;
      for (int j = 0; j < N; ++j) {
        action += abs(l - words[j][i].cnt);
      }
      min_action = min(min_action, action);
    }

    total_action += min_action;
  }

  return total_action;
}

int main() {
    int caseN;
    scanf("%d", &caseN);

    for (int cc = 1; cc <= caseN; ++cc) {
        printf("Case #%d: ", cc);

        cin >> N;
        words.clear();
        words.resize(N);

        string s;
        for (int i = 0; i < N; ++i) {
          cin >> s;
          words[i] = convert(s);
        }

        if (!ok()) {
          cout << "Fegla Won";
        } else {
          cout << solve();
        }

        printf("\n");
    }

    return 0;
}
