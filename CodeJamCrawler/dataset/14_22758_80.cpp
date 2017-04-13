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

const LL P = 1e9+7;
struct node{
    int own;
    int total;
    map<char, node*> sons;

};

int m;
const int MX = 210;
LL binom[MX][MX];

LL go(node* cur) {
    VI chld;
    LL res = 1;
    REP(i,cur->own) chld.PB(1);
    for (auto s : cur->sons) {
        chld.PB(min(m,s.Y->total));
        res = (res * go(s.Y)) % P;
    }
    sort(ALL(chld));
    reverse(ALL(chld));
    int v = 0;
    if (cur->total < m) {
        for (int c : chld) {
            res = (res * binom[c+v][c]) % P;
            v += c;
        }
    } else if (chld[0] == m) {
        chld.erase(chld.begin());
        for (int c : chld) {
            res = (res*binom[m][c]) % P;
        }
    } else {
        vector<vector<LL>> dp(SZ(chld)+1, vector<LL>(m+1));
        dp[0][0] = 1;
        REP(i, SZ(chld)) {
            FOR(j, chld[i], m) {
                FOR(jj, j-chld[i], j) {
                    LL mul = (dp[i][jj]*binom[j][jj])%P;
                    dp[i+1][j] = (dp[i+1][j] + mul*binom[jj][j-chld[i]])%P;
                }
            }
        }

        res = (res * dp[SZ(chld)][min(m, cur->total)]) % P;
    }
        assert(res >= 0);
    return res;
}

void solve(int tc) {
    cout << "Case #" << tc << ": ";
    int n;
    cin >> n >> m;
    LL cnt = 0;
    node* root = new node();
    REP(i,n) {
        string s;
        cin >> s;
        node* cur = root;
        if (cur->total < m) ++cnt;
        cur->total++;
        REP(j, SZ(s)) {
            char c = s[j];
            if (cur->sons.find(c) == cur->sons.end()) cur->sons[c] = new node();
            cur = cur->sons[c];
            if (cur->total < m) ++cnt;
            cur->total++;
        }
        cur->own++;
    }
    cout << cnt << " " << go(root) << endl;




}


int main(){
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    int T;
    cin >> T;
    binom[0][0] = 1;
    FOR(i, 1, 200) {
        binom[i][0] = 1;
        FOR(j, 1, 200) binom[i][j] = (binom[i-1][j] + binom[i-1][j-1]) % P;
    }
    REP(i,T) solve(i+1);


    return 0;
}

