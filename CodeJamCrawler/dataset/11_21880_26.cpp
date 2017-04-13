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

const int maxn = 1000500;
int a[maxn];
bool rr[maxn];

int main() {
        int T; scanf("%d", &T);
        Eo(T);
        for(int _=0; _<T; _++) {
                Eo(_);
                int x, s, r, t, n; scanf("%d %d %d %d %d", &x, &s, &r, &t, &n);
                for(int i=0; i<x; i++) {
                        a[i] = s;
                        rr[i] = false;
                }
                for(int i=0; i<n; i++) {
                        int b, e, v; scanf("%d %d %d", &b, &e, &v);
                        for(int j=b; j<e; j++) a[j] += v;
                }

                real tt =t ;
                real res = 0;
                while(tt > eps) {
                        int mn = inf;
                        for(int j=0; j<x; j++) if(!rr[j] && (mn == inf || a[j] < a[mn])) {
                                /*real left = 0;
                                for(int k=j-1; k>=0; k++)
                                        if(rr[k]) left += 1.0/real(a[k]);
                                        else break;
                                int right = 0;
                                for(int k=j+1; k<x; k++)
                                        if(rr[k]) right += 1.0/real(a[k]);
                                        else break;*/
                                //if(left+1.0+right < t) {
                                        mn = j;
                                //}
                        }
                        if(mn == inf) break;
                        rr[mn] = true;
                        a[mn] += r-s;
                        real tmpres = 1.0/real(a[mn]);
                        if(tmpres > tt) {
                                tmpres = tt + real(1.0 - a[mn]*tt)/(a[mn] -= r-s);
                                tt = 0;
                        }
                        //Eo(mn);
                        res += tmpres;
                        tt -= tmpres;
                }

                real curt = 0, allt=0;
                for(int i=0; i<x; i++) if(!rr[i]) {
                        int curv = a[i];
                        real curres = 1.0/real(curv);
                        res += curres;
                }
                printf("Case #%d: %.10lf\n", _+1, double(res));
        }

        return 0;
}
