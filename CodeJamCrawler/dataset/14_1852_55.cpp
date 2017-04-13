#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()
#define For(i, st, en)  for(int i=(st); i<=(int)(en); i++)
#define Forn(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)

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
set<double> naomi, ken;

int normal(set<double> w1, set<double> w2) {
  int score = 0;
  for (double w : w1) {
    auto it = upper_bound(w2.begin(), w2.end(), w);
    if (it != w2.end()) {
      w2.erase(it);
    } else {
      w2.erase(w2.begin());
      score++;
    }
  }
  return score;
}

int cheat(set<double> w1, set<double> w2) {
  int score = 0;
  for (double w : w1) {
    if (w < *w2.begin()) {
      w2.erase(prev(w2.end()));
    } else {
      w2.erase(w2.begin());
      score++;
    }
  }
  return score;
}

int main() {
    int caseN;
    scanf("%d", &caseN);

    double weight;
    for (int cc = 1; cc <= caseN; ++cc) {
        printf("Case #%d:", cc);

        naomi.clear();
        ken.clear();
        cin >> N;
        for (int i = 0; i < N; ++i) {
          cin >> weight;
          naomi.insert(weight);
        }
        for (int i = 0; i < N; ++i) {
          cin >> weight;
          ken.insert(weight);
        }

        cout << " " << cheat(naomi, ken) << " " << normal(naomi, ken);
        printf("\n");
    }

    return 0;
}
