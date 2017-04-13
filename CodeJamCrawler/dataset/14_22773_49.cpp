#include<algorithm>
#include<bitset>
#include<cassert>
#include<complex>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<vector>
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#define X first
#define Y second 
#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define dprintf(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef vector<int> VI;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.X << ", " << pair.Y << ")";}

bool ok[16][1<<15];
void solve(int tc) {
    cout << "Case #" << tc << ": ";
    int n;
    cin >> n;
    vector<char> op(n);
    VI id(n);
    map<int,int> M;
    REP(i,n) {
        cin >> op[i] >> id[i];
        if (id[i]) M[id[i]] = 0;
    }
    int c = 1;
    for (auto &m : M) {
        m.Y = c;
        ++c;
    }
    if (tc == 6) debug(E);
    M[0] = 0;
    REP(i,n) id[i] = M[id[i]];
    int N = 1<<n;
    REP(i, n+1) REP(msk, N) ok[i][msk] = false;
    REP(msk, N) ok[0][msk] = true;
    REP(i,n) {
        REP(msk, N) {
            if (!ok[i][msk]) continue;
            if (id[i] > 0) {
                int d = id[i]-1;
                if (op[i] == 'E' && (msk&(1<<(d))) == 0) {
                    ok[i+1][msk^(1<<d)] = true;
                } else if (op[i] == 'L' && (msk&(1<<(d))) != 0) ok[i+1][msk^(1<<d)] = true;
            } else {
                if (op[i] == 'E') {
                    REP(d, n) if ((msk&(1<<d)) == 0) {
                        ok[i+1][msk^(1<<d)] = true;
                    }
                } else {
                    REP(d, n) if ((msk&(1<<d)) != 0) {
                        ok[i+1][msk^(1<<d)] = true;
                    }
                }
            }
        }
    }
    int bst = n+1;
    REP(i,N) if (ok[n][i]) mini(bst, __builtin_popcount(i));
    if (bst == n+1) cout << "CRIME TIME" << endl;
    else cout << bst  << endl;

}


int main(){
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    int T;
    cin >> T;
    REP(i,T) solve(i+1);



    return 0;
}

