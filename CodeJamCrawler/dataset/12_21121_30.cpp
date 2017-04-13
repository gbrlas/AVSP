#include<algorithm>
#include<cassert>
#include<complex>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define fup FOR
#define fdo FORD
#define VAR(v,i) __typeof(i) v=(i)
#define FORE(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((int)(x).size())
#define SZ SIZE
#define CLR memset((x),0,sizeof (x))
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SQR(a) ((a)*(a))

#define DEBUG 1
#define debug(x) {if(DEBUG) cerr << #x << " = " << x << endl;}
#define debugv(x) {if(DEBUG) {cerr << #x << " = "; FORE(it,(x)) cerr << *it << " . "; cerr  <<endl;}}

using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef VI vi;
typedef LL lli;

const int inf = 1000000000;
string a = "oieastbg";
string b = "01345789";

int sb(int x) {
    REP(i, 8) if (a[i] == x) return b[i];
    return 0;
}

char mp[256][256];
int sr[256];
int sc[256];
void solve(int tcase) {
    string s;
    int k;
    cin >> k;
    cin >> s;
    REP(i, 256) REP(j, 256) mp[i][j] = 0;
    printf("Case #%d: ", tcase);
    if (k != 2) {
        printf("\n");
        return;
    }
    int n = SZ(s);
    REP(i, n-1) {
        int x = s[i], y= s[i+1];
        int xx = sb(x) , yy = sb(y);
        mp[x][y] = 1;
        if (xx) mp[xx][y] = 1;
        if (yy) mp[x][yy] = 1;
        if (xx && yy) mp[xx][yy] = 1;
    }
    REP(i, 256) {
        sr[i] = 0;
        REP(j, 256) sr[i] += mp[i][j];
    }
    REP(j, 256) {
        sc[j] = 0;
        REP(i, 256) sc[j] += mp[i][j];
    }
    int t = 0;
    int u = 0;
    REP(i, 256) {
        t += abs(sc[i] - sr[i]);
        u += sc[i];
    }
    if (t == 0) printf("%d\n", u+1);
    else printf("%d\n", u+t/2);
}

int main() {
    int t;
    cin >> t;
    REP(i, t) solve(i+1);
    return 0;
}
