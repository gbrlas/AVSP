#include <algorithm>
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

typedef long double ld;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

// Types
typedef signed   long long i64;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < ld > VD;
typedef vector < int > VI;
typedef vector < bool > VB;
typedef vector < string > VS;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

//#define debug(...)
#define debug printf

int P;
int N;
int see[1025];
bool buy[1025];

int ticket(int team, int level) {
  int cnt = 0;
  forn(i, level) {
      cnt += 1 << (P - i - 1);
  }
  cnt += team >> (level + 1);
  return cnt;
}

int main() {
  int caseN;
  scanf("%d", &caseN);

  For(cc, 1, caseN) {
    printf("Case #%d: ", cc);

    cin >> P;
    int N = 1 << P;

    int tmp;
    forn(i, N) {
      cin >> tmp;
      see[i] = P - tmp;
//      cout << see[i] << " ";
    }
//    cout << endl;

    forn(i, N-1)
      cin >> tmp;

    clr(buy);
    int total = 0;

    forn(t, N) {
      // handle team see.
      if (see[t] <= 0) continue;

      // find highest available level.
      int level = P-1;
      while (buy[ticket(t, level)]) level--;
//      cout << see[t] << endl;
//      cout << t << " " << level << ": " << ticket(t, level) << endl;

      while (see[t] > 0) {
        // buy this ticket
        int start = t >> (level+1) << (level+1);
        int length = 1 << (level+1);
//        cout << start << " " << length << endl;
        forn(i, length) {
          see[start + i]--;
        }
        buy[ticket(t, level)] = true;
        total++;
        level--;
      }
    }


    // greedy.


    cout << total;

    printf("\n");
  }

  return 0;
}

