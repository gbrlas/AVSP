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
#include <cassert>

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

char board[5][6];

void read() {
   forn(i, 4) {
      scanf("%s", board[i]);
      //fgets(board[i], 5, stdin);
   }
}

void show() {
   printf("\n");
   forn(i, 4) {
      printf("%s\n", board[i]);
   }
}

enum Result {
   X_WON,
   O_WON,
   FULL,
   EMPTY,
};

Result testLine(int sr, int sc, int vr, int vc) {
   int numX, numO, numT, numEmpty;
   numX = numO = numT = numEmpty = 0;

   for (int i = 0, r = sr, c = sc; i < 4; ++i, r += vr, c += vc) {
      switch (board[r][c]) {
         case 'X': numX += 1; break;
         case 'O': numO += 1; break;
         case 'T': numT += 1; break;
         case '.': numEmpty += 1; break;
         default: assert(0);
      }
   }

   if (numX + numT == 4) return X_WON;
   if (numO + numT == 4) return O_WON;
   if (numEmpty) return EMPTY;
   return FULL;
}

int vec[10][5] = {
   {0, 0, 0, 1}, // row
   {1, 0, 0, 1}, // row
   {2, 0, 0, 1}, // row
   {3, 0, 0, 1}, // row
   {0, 0, 1, 0}, // col
   {0, 1, 1, 0}, // col
   {0, 2, 1, 0}, // col
   {0, 3, 1, 0}, // col
   {0, 0, 1, 1}, // diagnal1
   {3, 0, -1, 1}, // diagnal2
};

Result test() {
   bool has_empty = false;
   Result result;

   forn(i, 10) {
      result = testLine(vec[i][0], vec[i][1], vec[i][2], vec[i][3]);
      if (result == X_WON) return X_WON;
      if (result == O_WON) return O_WON;
      if (result == EMPTY) has_empty = true;
   }

   if (has_empty) return EMPTY;
   return FULL;
}

int main() {
   //freopen("a-sample.in", "r", stdin);

   int caseN;
   scanf("%d\n", &caseN);

   for (int cc = 1; cc <= caseN; ++cc) {
      printf("Case #%d:", cc);

      read();
      //show();
      switch (test()) {
         case X_WON: printf(" X won"); break;
         case O_WON: printf(" O won"); break;
         case FULL: printf(" Draw"); break;
         case EMPTY: printf(" Game has not completed"); break;
         default: assert(0);
      }

      printf("\n");
   }

   return 0;
}

