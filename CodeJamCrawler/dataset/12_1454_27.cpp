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

#define MAX 2010

int N;
int x[MAX]; // 1 based
int h[MAX];

// i > ca * a + cb * b
class Rule {
    public:
        Rule(int ti, int ta, int tb, double tca, double tcb) {
            i = ti;
            a = ta;
            b = tb;
            ca = tca;
            cb = tcb;
        }
        int i, a, b;
        double ca, cb;
};

vector<Rule> rules;

int main() {
    int caseN;
    scanf("%d", &caseN);

    for (int cc = 1; cc <= caseN; ++cc) {
        printf("Case #%d:", cc);

        cin >> N;
        forn(i, N-1) cin >> x[i+1];
        rules.clear();

        //debug("%d\n", N);
        // test.
        bool ok = true;
        for (int i = 1; i <= N-1; ++i) {
            int h = x[i];
            for (int j = i + 1; j < h; ++j)
                if (x[j] > h) {
                    ok = false;
                    break;
                }
        }

        if (!ok) cout << " Impossible";
        else {
            for (int i = 1; i <= N-1; ++i) {
                int h = x[i];
                rules.push_back(Rule(h, i, i, 1.0, 0));

                // before
                for (int j = i + 1; j < h; ++j) {
                    double ratio = double(h - i) / (j - i);
                    rules.push_back(Rule(h, j, i, ratio, 1.0 - ratio));
                }
                // after
                for (int j = h + 1 ; j <= N; ++j) {
                    double ratio = double(h - i) / (j - i);
                    rules.push_back(Rule(h, j, i, ratio, 1.0 - ratio));
                }
            }
#if 0
            printf("\n");
            for (int i = 0; i < rules.size(); ++i) {
                Rule &r = rules[i];
                printf("h(%d) > %f * h(%d) + %f * h(%d)\n",
                        r.i, r.ca, r.a, r.cb, r.b);
            }
#endif

            // guess.
            fill_n(h, N+1, 1);

            bool solved = false;
            while (!solved) {
                bool tmp = true;
                for (int ri = 0; ri < rules.size(); ++ri) {
                    Rule &r = rules[ri];
                    double right = r.ca * h[r.a] + r.cb * h[r.b];
                    if (h[r.i] <= right) {
                        h[r.i] = ceil(right + 1);
                        tmp = false;
                        break;
                    }
                }
                if (tmp) solved = true;
            }

            for (int i = 1; i <= N; ++i)
                cout << " " << h[i];

        }

        printf("\n");
    }

    return 0;
}

