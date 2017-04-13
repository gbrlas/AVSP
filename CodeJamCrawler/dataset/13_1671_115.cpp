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

vector<long long> results;

bool isPalindrome(long long num) {
   char buf[20];
   sprintf(buf, "%lld", num);
   int len = strlen(buf);
   for (int i = 0, j = len-1; i < j; ++i, --j)
      if (buf[i] != buf[j]) return false;
   return true;
}

void prepare() {
   int cnt = 0;
   for (long long i = 1; i <= 10000000LL; ++i) {
      if (isPalindrome(i)) {
         long long square = i * i;
         if (isPalindrome(square)) {
            results.pb(square);
            cnt++;
         }
      }
   }
}

void show() {
   fori(it, results) {
      cout << *it << endl;
   }
}

int getCount(long long A, long long B) {
   vector<long long>::iterator iter1, iter2;
   iter1 = lower_bound(all(results), A);
   iter2 = upper_bound(all(results), B);
   return distance(iter1, iter2);
}

int main() {
    int caseN;
    scanf("%d", &caseN);

    prepare();
#if 0
    show();
    printf(" %d", getCount(1, 4));
    printf(" %d", getCount(1, 9));
    printf(" %d", getCount(1, 8));
    printf(" %d", getCount(1, 100000000000000LL));
    printf(" %d", getCount(121, 121));
    printf(" %d", getCount(120, 120));
    printf(" %d", getCount(3, 10000));
#endif

    for (int cc = 1; cc <= caseN; ++cc) {
        printf("Case #%d:", cc);

        long long A, B;
        cin >> A >> B;
        printf(" %d", getCount(A, B));

        printf("\n");
    }

    return 0;
}

