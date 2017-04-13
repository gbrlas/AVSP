// Tomasz Kociumaka
#include<cassert>
#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<string>
#include<cstring>
#define FORE(it, c) for(__typeof((c).begin()) it = (c).begin(); it!=(c).end();++it)
#define FC(aa, bb) FORE(bb, aa)
#define debug(x) cerr << #x << " = " << x << endl;
#define fup(i, a, b) for(int i = (a); i <= b; ++i)
#define fdo(i, a, b) for(int i = (a); i >= b; --i)
#define FOR fup
#define FORD fdo
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define CLR(x) memset((x), 0, sizeof(x))
#define MP make_pair
#define PB push_back
#define siz(a) ((int)(a).size())
#define SZ siz
#define FI first
#define SE second

using namespace std;
typedef long long lli;
typedef lli LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

struct point {
    point(int x=0, int y=0) : x(x), y(y) {}
    point(PII p) : x(p.FI), y(p.SE) {}
    int x, y;

    LL operator * (point const & p) const{
        return (LL) x * p.y - (LL) y * p.x;
    }
    point operator - (point const & p) const {
        return point(x-p.x, y-p.y);
    }
    bool operator == (point const &p) const {
        return x == p.x && y == p.y;
    }
};
struct segment {
    segment(point a, point b) : a(a), b(b) {}
    point a,b;
    void print() {
        fprintf(stderr, "[(%d, %d), (%d, %d)]", a.x, a.y, b.x, b.y);
    }
    bool operator < (segment const& s) const;
};

inline LL Det(point const &p1,point const& p2, point const &w) {
    return LL(p2.x-p1.x)*LL(w.y-p1.y)-LL(p2.y-p1.y)*LL(w.x-p1.x);
}
inline int sgn(LL x){
    return (x==0)?0:(x < 0 ? -1 : 1);
}
inline bool  PointInRect(point const& p1, point const& p2, point const& p3) {
    return min(p1.x,p2.x) <= p3.x && min(p1.y,p2.y) <= p3.y && max(p1.x,p2.x) >= p3.x && max(p1.y,p2.y) >= p3.y;
};
inline bool PointInSegment(segment const& s, point const& l) {
    if (s.a == l || s.b == l) return false; 
    return Det(s.a,s.b,l)==0 && PointInRect(s.a,s.b,l);
}
inline bool SegmentCross(segment const& s, segment const& t) {
    return sgn(Det(s.a,s.b,t.a))*sgn(Det(s.a,s.b,t.b)) == -1 && sgn(Det(t.a,t.b,s.a))*sgn(Det(t.a,t.b,s.b)) == -1;
}
inline bool SegmentTouch(segment const&s, segment const&t) {
    return SegmentCross(s,t) || PointInSegment(s,t.a) || PointInSegment(s,t.b) || PointInSegment(t,s.a) || PointInSegment(t, s.b);
}

bool verify(vector<point> p) {
    int n = SZ(p);
    vector<segment> S;
    REP(i,2*n) S.PB(segment(p[i%n], p[(i+1)%n]));
    REP(i, n) FOR(j, i+1, i+n-1) if(SegmentTouch(S[i], S[j])) return false;
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<point> p;
    vector<int> perm(n,0);
    REP(i, n) {
        int x,y;
        cin >> x >> y;
        p.PB(point(x,y));
        perm[i] = i;
    }
    long double best = -1;
    VI bst;
    do {
        vector<point> q = p;
        REP(i, n) q[i] = p[perm[i]];
        q.PB(q[0]);
        if (verify(q)) {
            long double a = 0;
            REP(i, n) a += (q[i+1].x-q[i].x)*(q[i+1].y+q[i].y);
            if (a > best) {
                best = a;
                bst = perm;
            } 

        }

    } while(next_permutation(ALL(perm)));
    REP(i, n) {
        cout << " " << bst[i];
    }
    cout << endl;

}

int main(){
	ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    REP(i,t) {
        cout << "Case #" << (i+1) << ":";
        solve();
    }
	return 0;
}

