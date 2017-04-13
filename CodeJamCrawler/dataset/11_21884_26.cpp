#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>

#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>

using namespace std;

#define Eo(x) { cerr << #x << " = " << (x) << endl; }
#define sz(x) (int((x).size()))
#define foreach(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); i ++)

template<typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename C> ostream& operator<<(ostream& os, const vector<C>& v) { foreach(__it, v) os << *(__it) << ' '; return os; }

typedef double real;
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int, int> pip;

const int inf = 0x3f3f3f3f;
const real eps = 1e-5;

const int maxn = 512;
string s[maxn];
int f[maxn][maxn];

int main() {
        int T; scanf("%d", &T);
        Eo(T);
        for(int _=0; _<T; _++) {
                Eo(_);
                int r, c, d; cin >>r >> c >> d;
                for(int i=0; i<r; i++) cin >> s[i];
                for(int i=0; i<r; i++) for(int j=0; j<c; j++) f[i][j] = s[i][j] -'0';

                printf("Case #%d: ", _);
                bool ok = false;
                for(int k = min(r, c); k>=3 && !ok; k--) {
                        for(int i=0; i+k<=r && !ok; i++) for(int j=0; j+k<=c && !ok; j++) {
                                real row = 0, col = 0;
                                for(int ii = 0; ii<k; ii++) for(int jj=0; jj<k; jj++) {
                                        if((ii == 0 || ii == k-1) && (jj == 0 || jj == k-1)) continue;
                                        real drow = real(k)/2 - (ii+0.5);
                                        real dcol = real(k)/2 - (jj+0.5);
//                                      if(k == 5 && i == 3 && j == 3){Eo(ii); Eo(jj); Eo(drow); Eo(dcol);}
                                        row += drow*f[i+ii][j+jj];
                                        col += dcol*f[i+ii][j+jj];
                                }
                                if(abs(row) < eps && abs(col) < eps) {
                                        printf("%d\n", k);
                                        ok = true;
                                        break;
                                }
                        }
                }

                if(!ok) puts("IMPOSSIBLE");
        }

        return 0;
}
