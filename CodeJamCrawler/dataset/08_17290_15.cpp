#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <cmath>
using namespace std;

#define FOR(i, s, e)        for(__typeof((s)) i = (s) ; i < (e) ; ++i)
#define FORD(i, s, e)       for(__typeof((s)) i = (s) ; i > (e) ; --i)
#define REP(i, n)           for(__typeof((n)) i = 0 ; i < (n) ; ++i)
#define FOREACH(it, cont)   for(__typeof((cont).begin()) it = (cont).begin() ; it != (cont).end()  ; ++it)
#define ALL(cont)           (cont).begin(), (cont).end()
#define SIZE(x)             (int)(x).size()
#define IN(x, cont)         (std::find(ALL(cont), (x)) != (cont).end())
#define MAPIN(x, m)         ((m).find((x)) != (m).end())
#define SORT(cont)          (std::sort(ALL(cont)))
#define MIN(x, y)           ((x) < (y) ? x : y)
#define MAX(x, y)           ((x) < (y) ? y : x)

int main()
{
    int T;
    cin >> T;

    REP(i, T){
        int n;
        cin >> n;
        
        vector<long long> x(n), y(n);
        REP(j, n)
            cin >> x[j];
        REP(j, n)
            cin >> y[j];
        SORT(x); SORT(y);

        long long prod = 0;
        REP(j, n)
            prod += x[j] * y[n - j - 1];

        cout << "Case #" << (i + 1) << ": " << prod << endl;
    }

    return 0;
}
