
// {{{
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef long  double LD;
typedef long long LL;
typedef pair<LD,LD> PD;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<VI> VII;
typedef vector<string> VS;

#define VAR(v,n) __typeof(n) v=(n)
#define REP(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define FORD(i,a,b) for(int i=(a); i>=(b); i--)
#define FORE(i,c) for(VAR(i,(c).begin()); i!=(c).end(); i++)

#define ALL(x) x.begin(),x.end()
#define CLR(A,v) memset((A),v,sizeof((A)))
#define FI first
#define MP make_pair
#define PB push_back
#define SE second
#define SIZE(x) ((int)(x).size())
// }}}



// POINT {{{
#define POINTT long double // Dla wspolrzednych punktu (int,LL,long double)
#define POINTR long double  // Dla wynikow operacji - pole, iloczyn wektorowy (LL lub long double)
struct POINT {
	POINTT x,y;
	POINT(POINTT wx, POINTT wy) : x(wx), y(wy) {}
	POINT():x(0),y(0){}
	

	/* Operatory porownawcze */
	#define OPER1(op) bool operator op (const POINT &b) const
	OPER1(==) {
		return x==b.x && y==b.y;
	}
	OPER1(<) {
		if (x==b.x)
			return y<b.y;
		return x<b.x;
	}
	OPER1(>) { return b<*this; } /* Wymaga < */
	OPER1(<=) { return !(b<*this); } /* Wymaga < */
	OPER1(>=) { return !(*this<b); } /* Wymaga < */
	OPER1(!=) { return !(*this==b); } /* Wymaga == */
	/* Operatory POINT & POINTT */
	#define OPER2a(op) POINT& operator op (POINTT b)
	OPER2a(*=) {
		x*=b;
		y*=b;
		return *this;
	}
	OPER2a(/=) {
		x/=b;
		y/=b;
		return *this;
	}
	#define OPER3a(op) POINT operator op(POINTT b) const {POINT w=*this; w op ## = b; return w; }
	OPER3a(*); /* Wymaga *= */
	OPER3a(/); /* Wymaga /= */
	
	/* Operatory POINT & POINT */
	#define OPER2(op) POINT& operator op (const POINT &b)
	OPER2(+=) {
		x+=b.x;
		y+=b.y;
		return *this;
	}
	OPER2(-=) {
		x-=b.x;
		y-=b.y;	
		return *this;
	}
	#define OPER3(op) POINT operator op(const POINT &b) const {POINT w=*this; w op ## = b; return w; }
	OPER3(+); /* Wymaga += */
	OPER3(-); /* Wymaga -= */
};
inline POINTR det(const POINT &a,const POINT &b,const POINT &c){
	return (POINTR)(a.x-c.x)*(b.y-c.y)-(POINTR)(b.x-c.x)*(a.y-c.y);
}
inline POINTR dot(const POINT &a,const POINT &b,const POINT &c){
	return (POINTR)(a.x-c.x)*(b.x-c.x)+(POINTR)(a.y-c.y)*(b.y-c.y);
}

bool cmpXY(const POINT &a,const POINT &b){
	if (a.x == b.x) return a.y<b.y;
	return a.x<b.x;
}
bool cmpYX(const POINT &a,const POINT &b){
	if (a.y==b.y) return a.x<b.x;
	return a.y<b.y;
}
inline POINTR dis(const POINT &a, const POINT &b){
    return sqrtl( dot(a-b,a-b,POINT(0,0)));
}

// }}}
typedef vector<POINT> VP;
const POINT ZERO(0,0);

const long double EPS = 1e-9;
inline bool is_zero(long double x){
    return -EPS <= x && x <= EPS;
}

/* 
   -1 - puste przeciêcie
    0 - jedno w drugim
    1 - jeden punkt
    2 - trzy punkty
*/

// circle_cross(P a, ra, P b, rb) {{{ 
pair<int,VP> circle_cross(POINT a,POINTR ra,POINT b,POINTR rb){
#define PW(x) ((x)*(x))
    VP r;
    POINT p=b-a;
    POINTR d=sqrtl(dot(p,p,ZERO));
    if(d > ra+rb) return MP(-1,r);   // puste przeciêcie
    if((is_zero(p.x) && is_zero(p.y)) || ( d+ra < rb ) || ( d+rb < ra ) ) return MP(0,r);
    p/=d;
    if(is_zero(ra+rb-d)){
        r.PB(a+p*ra);
        return MP(1,r);
    }
    POINTR t1 = (PW(ra) - PW(rb) + PW(d))/(2*d);
    POINTR t2 = sqrtl(PW(ra)-PW(t1));
    r.PB(a+p*t1 + POINT(p.y*t2,-p.x*t2));
    r.PB(a+p*t1 + POINT(-p.y*t2,p.x*t2));
    return MP(2,r);
}
// }}}


const int nmx=43;
int n;
POINT P[nmx];
long double R[nmx];



bool ok(long double r){
    vector<POINT> ts;
    REP(i,n) ts.PB( P[i] );
    pair<int,VP> p;
    REP(i,n) if(R[i] >= r) return 0;
    REP(a,n)
        FOR(b,a+1,n-1){
            p=circle_cross(P[a],r-R[a],P[b],r-R[b]);
            FORE(i,p.SE) ts.PB(*i);            
        }
    int m=SIZE(ts);
//    REP(i,m) printf("%d  %lf %lf\n",i,ts[i].x,ts[i].y);
    REP(a,m)
        FOR(b,a,m){
            POINT ap=ts[a],bp=ts[b];
           
            bool ok=1;
            REP(i,n){
                if( (dis(ap, P[i]) + R[i] > r +EPS)  && (dis(bp, P[i]) + R[i] > r+EPS) ){ ok=0; break;}    
            }
            if(ok){
                return 1;
            }
        }
    return 0;
}   


int main()
{
    int z; scanf("%d",&z);
    REP(zz,z)
    {
        // ---- Cleaning !!! ----
            scanf("%d",&n);
            long double x,y;
            REP(i,n){
                scanf("%Lf%Lf%Lf",&x,&y,R+i);
                P[i].x=x,P[i].y=y;
            }
        // ----------------------
        fprintf(stderr,"Working on %d / %d\n",zz+1,z);
        long double l=0,r=100000;
        REP(i,100){
            long double s=(l+r)/2;
            if(ok(s)) r=s;
            else l=s;
        }
        printf("Case #%d: %.8Lf\n",zz+1,l);
    }
    return 0;
}
