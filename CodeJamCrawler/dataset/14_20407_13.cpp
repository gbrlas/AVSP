#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
#include <cctype>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define VAR(a,b)        __typeof(b) a=(b)
#define REP(i,n)        for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b)      for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b)     for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c)   for(VAR(it,(c).begin());it!=(c).end();++it)
#define ALL(c)          (c).begin(),(c).end()
#define TRACE(x)        cerr << "TRACE(" #x ")" << endl;
#define DEBUG(x)        cerr << #x << " = " << x << endl;
#define eprintf(...)    fprintf(stderr, __VA_ARGS__)

typedef long long               ll;
typedef long double             ld;
typedef unsigned long           ulong;
typedef unsigned long long      ull;
typedef vector<int>             VI;
typedef vector<char>            VC;

int s[11234];

int main() {
    //freopen("input",  "r", stdin);
    //freopen("output", "w", stdout);
    int TN, N, X;
    scanf("%d", &TN);
    FOR(TI,1,TN) {
        scanf("%d%d", &N, &X);
        REP(i,N)
            scanf("%d", &s[i]);
        int num = 0;
        sort(s, s+N);
        for (int i = 0; i < N; ++i) {
            ++num;            
            while (i != N-1 && s[i] + s[N-1] > X) {
                --N;
                ++num;
            }
            if (i != N-1 && s[i]+s[N-1] <= X)
                --N;            
        }
        printf("Case #%d: %d\n", TI, num);
    } // next test
    return 0;
}
