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

int w,h;
vector<VI> tab(w, VI(h,1));

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool empty(int xx, int yy, int ph) {
    if (xx < 0 || yy < 0 || xx >= w || yy >= h) return false;
    if (tab[xx][yy] < ph) return false;
    return true;
}

bool go(int x, int y, int dir, int ph) {
   // debug(ph);
    while(true) {
        tab[x][y] = ph;
      //  debug(MP(MP(x,y),dir));
        int xx = x+dx[dir];
        int yy = y+dy[dir];
        if (empty(xx, yy, ph)) {
            x = xx;
            y = yy;
            dir = (dir+3)%4;
        } else {
            if (yy < 0) return false;
            if (yy >= h) return true;
            dir = (dir+1)%4;
        }
    }
    assert(false);
}

const int INF = 1e9;
void solve(int tc) {
    cout << "Case #" << tc << ": ";
    int b;
    cin >> w >> h >> b;
    tab = vector<VI>(w, VI(h,INF));
    REP(i,b) {
        int x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        FOR(x, x1, x2) FOR(y, y1, y2) tab[x][y] = 0;
    }
    int ph = 1;
    int res = 0;
    REP(i,w) {
        if (tab[i][0] != INF) continue;
        bool ok = go(i, 0, 0, ph);
        if (ok) ++res;
        ++ph;
    }
    cout << res << endl;



}


int main(){
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    int T;
    cin >> T;
    REP(i,T) solve(i+1);


    return 0;
}

