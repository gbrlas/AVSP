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

const int MAX = 105;

int N, M;
int board[MAX][MAX];
int rowMax[MAX], colMax[MAX];

void read() {
   cin >> N >> M;
   forn(i, N) {
      forn(j , M) {
         cin >> board[i][j];
      }
   }
}

void show() {
   cout << endl;
   forn(i, N) {
      forn(j , M) {
         cout << board[i][j] << " ";
      }
      cout << endl;
   }
}

void record() {
   fill_n(rowMax, N, 0);
   fill_n(colMax, M, 0);

   forn(i, N) {
      forn(j, M) {
         rowMax[i] = max(rowMax[i], board[i][j]);
         colMax[j] = max(colMax[j], board[i][j]);
      }
   }
}

bool test() {
   forn(i, N) {
      forn(j, M) {
         if (board[i][j] != min(rowMax[i], colMax[j])) return false;
      }
   }
   return true;
}

int main() {
   int caseN;
   scanf("%d", &caseN);

   for (int cc = 1; cc <= caseN; ++cc) {
      printf("Case #%d: ", cc);

      read();
      //show();
      record();
      if (test()) cout << "YES";
      else cout << "NO";

      printf("\n");
   }

   return 0;
}

