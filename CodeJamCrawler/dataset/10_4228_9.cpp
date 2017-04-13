#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
using namespace std;

typedef long long  ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ld> vld;
typedef vector<vld> vvld;
typedef pair<ld,ld> ldld;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll,ll> llll;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<string,string> ss;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef pair<char,char> cc;

typedef set<int> si;
typedef set<int>::iterator siit;
typedef set<char> sc;
typedef set<char>::iterator scit;
typedef set<string> sstr;
typedef set<string>::iterator sstrit;

typedef map< pair<int, int> , int> mpii;
typedef map< pair<int, int> , int>::iterator mpiiiter;


#define sz(v) int((v).size())
#define FOR(i, a, b) for (int i(a), _b(b); i < _b; ++i)
#define REP(i, n) for (int i(0), _n(n); i < _n; ++i)
#define ALL(C) (C).begin(), (C).end()
#define INF numeric_limits<int>::max()
#define MINF numeric_limits<int>::min()
#define DODEB 1
#define db(C) {std::cout<<#C <<" = "<< (C)<<std::endl;}
#define dbv(C) {std::cout<<#C <<" = "; for(typeof((C).begin()) i = (C).begin(); i != (C).end(); i++){ cout<<*i<<" "; } cout<<endl;}
#define LET(i,e) __typeof(e) i = (e)
#define PRESENT(c,x) ((c).find(x) != (c).end())
#define CPRESENT(c,x) (find(all(c),x) != (c).end())
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define REPD(i, n) for (int i((n)-1); i >= 0; --i)
#define SORT(C) sort(ALL(C))
#define SORTD(C) sort(ALL(C))
#define REV(C)	reverse(ALL(C))
#define UN(v)	SORT(v), v.erase(unique( v.begin(), v.end()), v.end())
#define MIN(C) *min_element(ALL(C))
#define MINPOS(C) (int)(min_element(ALL(C)) - (C).begin())
#define MAX(C) *max_element(ALL(C))
#define MAXPOS(C) (int)(max_element(ALL(C)) - (C).begin())
#define SUM(C) accumulate(ALL(C), 0)
#define BE(C) ((C).begin())
#define EN(C) ((C).end())
#define CLEAR(x,with) memset(x,with,sizeof(x))
#define FORV(iter,c)  if ((c).begin() != (c).end()) for (typeof((c).begin()) iter = (c).begin(); iter != (c).end(); i++)
#define FORVV(i, j, c)  for (int  i = 0; i < (int)(c).size(); i++) for (int  j = 0; j < (int)(c[0]).size(); j++)
#define pb push_back
#define Fi(xy) ((xy).first)
#define Se(xy) ((xy).second)
#define SQ(x)	((x)*(x))
#define mp make_pair
#define CLC(act,val) (*({act; static typeof(val) CLCR; CLCR = (val); &CLCR;}))
#define FIRSTP(k,a,b,cond) CLC(LET(k, a); for(; k < (b); ++k) if(cond) break, k)
#define LASTP(k,a,b,cond) CLC(LET(k, b); while((a) <= (--k)) if(cond) break, k)
#define EXISTS(k,a,b,cond) (FIRSTP(k,a,b,cond) < (b))
#define ALLMEET(k,a,b,cond) (!EXISTS(k,a,b,!(cond)))
#define RMVAL(c,val)  while( find(ALL(c),val) != (c).end() ){ c.erase( find(ALL(c),val) );};
#define CLOCK cout<<"CLOCK "<< (double)clock()/CLOCKS_PER_SEC <<endl

const double pi=acos(-1.0);//NOTES:pi
const double eps=1e-10;//NOTES:eps

ll gcd(ll x, ll y)
{
    return x ? gcd(y%x,x) : y;
}
ll lcm(ll x, ll y)
{
    return x*(y/gcd(x,y));
}
string c2s(char c)
{
    string s="";
    s+=c;
    return s;
}

template<typename T> void remin(T& a, const T& b)
{
    if (b < a) a = b;
}
template<typename T> void remax(T& a, const T& b)
{
    if (b > a) a = b;
}
// should use like vi c= lenmin(a,b), not func(lenmin(a,b))
template<typename T> T lenmin( const T & a, const T & b)
{
    if ( (a.size()) < ( b.size()) )        return a;
    else if ( (a.size()) > ( b.size() ) )        return b;
    else    	return (a) < (b) ? (a) : (b);
}
template<typename T> T lenmax( const T & a, const T & b)
{
    if ( (a.size()) > ( b.size()) )        return a;
    else if ( (a.size()) < ( b.size() ) )        return b;
    else    	return (a) > (b) ? (a) : (b);
}


template<class T> string toString(T n)
{
    ostringstream ost;    //NOTES:toString
    ost<<n;
    ost.flush();
    return ost.str();
}
int toInt(string s)
{
    int r=0;    //NOTES:toInt(
    istringstream sin(s);
    sin>>r;
    return r;
}

template <typename T> vi n2vi(  T in, int base)
{
    char buff[200];
    itoa( in, buff, base);
    vi c;
    int l  = strlen(buff);
    for (int i = 0; i < l ; ++i  )
    {
        c.push_back( buff[i] - '0');
    };
    return c;
}

template <typename T> ll vi2n(  T in, int base)
{
    ll tic =1;
    ll sum = 0;
    int p ;

    for ( p = in.size()-1; p>=0; --p)
    {
        sum += in[p]* tic;
        tic*= base;
    }
    return sum;
}

int CN;
////////////////////////////////////////////////////////////////
// functions for 2d , coordinates
////////////////////////////////////////////////////////////////

template<typename T>  bool operator == ( const T a, const T b)
{
    T d = fabs(a - b);
    T s  = min( fabs(a), fabs(b));
    if ( s < eps )
    {
        return ( d < eps )? true: false;
    }
    else
    {
        return ( d/s < eps ) ? true: false;
    }
}

struct d2p
{
    ld x;
    ld y;
    d2p( ld _x=0.0, ld  _y = 0.0):x(_x), y(_y) { };
    ld sqrD()
    {
        return x*x+y*y;
    }
    ld abs()
    {
        return sqrt(sqrD());
    }
    // in degrees
    void rotate(ld deg)
    {
        ld ox = x;
        ld oy = y;
        x = ox*cos(deg*pi/180.0)-oy*sin(deg*pi/180.0);
        y = ox*sin(deg*pi/180.0)+oy*cos(deg*pi/180.0);
    }

};

struct d2l
{
    ld a;
    ld b;
    ld c;
};

struct d2c
{
    ld x;
    ld y;
    ld r;
};

bool operator <( const d2p &a, const d2p &b)
{
    return (a.x)<(b.x);
}


bool operator==( const d2p &a, const d2p &b)
{
    return (b.x)==(a.x)&&(b.y)==(a.y);
}
d2p operator + ( const d2p &a, const d2p &b)
{
    return d2p( b.x+a.x, b.y + a.y);
}
d2p operator - ( const d2p &a, const d2p &b)
{
    return d2p( a.x-b.x, a.y - b.y);
}
ld operator * ( const d2p &a, const d2p &b)
{
    return (b.x*a.x)+(b.y*a.y);
}
ld operator ^ ( const d2p &a, const d2p &b )
{
    return ( a.x*b.y - a.y * b.x);
}
d2p operator * ( const d2p &a, ld b)
{
    return d2p( a.x*b, a.y *b);
}
d2p operator / ( const d2p &a, ld b)
{
    return d2p( a.x/b, a.y /b);
}


ld lined2pdist (  d2p & a,  d2p & b,  d2p & c, bool isseg = false)
{
    ld dist= (((b-a)^(c-a)))/sqrt((b-a)*(b-a));
    if ( isseg)
    {
        ld d1 = (c-b)*(b-a);
        if( d1 > 0.0 ) return sqrt((b-c)*(b-c));
        ld d2 = (c-a)*(a-b);
        if(d2 > 0.0 ) return sqrt((a-c)*(a-c));
    };
    return fabs(dist);
}




d2l line2make( const d2p & a, const d2p & b)
{
    // return a line with a&b in form of ax+by =c, [a,b,c]
    d2l r;
    r.a=  (b.y-a.y);
    r.b=  (a.x-b.x);
    r.c=  (r.a*a.x + r.b*a.y );
    return r;
}

d2l line2perpmake( const d2p & a, const d2p & b)
{
    d2l r;
    d2p mid = (a+b)/2;
    d2l cut = line2make(a,b);
    r.a = cut.b * -1.0;
    r.b = cut.a;
    r.c = r.a*mid.x+r.b*mid.y;
    return r;
}


bool line2inter( const d2l & l1, const d2l & l2 , d2p & athere )
{
    // return the coordinates of the intersection, null if 2 lines are parrallel
    ld det = l1.a *l2.b - l2.a*l1.b;
    if ( det  == 0.0 )
        return false;
    else
    {
        athere.x = (l2.b*l1.c-l1.b*l2.c)/det;
        athere.y = (l1.a*l2.c - l2.a*l1.c)/det;
        return true;
    }
}

bool circle2make( const d2p & a, const d2p & b, const d2p & c, d2c & circleme)
{
    d2l la = line2perpmake(a,b);
    d2l lb = line2perpmake(b,c);
    d2p ctr;
    if ( line2inter(la,lb,ctr) )
    {
        circleme.x = ctr.x;
        circleme.y = ctr.y;
        circleme.r = (ctr-a).abs();
        return true;
    }
    else
        return false;
}


d2p line2reflect( d2l line, d2p p)
{
    d2l perp ;
    perp.a = line.b * -1.0;
    perp.b = line.a;
    perp.c = perp.a * p.x + perp.b * p.y ;
    d2p mid;
    line2inter(line,perp, mid);
    d2p r;
    r.x = 2.0* mid.x-p.x;
    r.y = 2.0 * mid.y - p.y;
    return r;
}

vector<d2p> convexhullmake( vector<d2p> & v)
{
    // not handle the colinear condition
    vector<d2p> rslt;
    int N = v.size();
    int pos = 0;
    for (int i =0; i<N; ++i)
    {
        if( v[i].x < v[pos].x)
            pos = i;
        else
        {
            if ( v[i].x == v[pos].x && v[i].y > v[pos].y )
                pos = i;
        }
    };

    int start = pos;
    rslt.push_back(v[pos]);
    do
    {
        int n = -1;
        for ( int i =0; i< N ; ++i )
        {
            if( i == pos )    continue;
            if ( -1 == n)   n = i;
            ld cross = (v[i]-v[pos])^(v[n]-v[pos]);
            if(cross < 0.0)  n = i;
        };
        pos = n;
        if( pos!= start) rslt.push_back(v[pos]);
    }
    while( start != pos);
    return rslt;
}


ld polyarea ( vector<d2p> vinput )
{
    vector<d2p> v = convexhullmake(vinput);
    int N = v.size();
    ld area = 0.0;
    for ( int i = 1; i +1 < N ;  ++i)
    {
        area += ( (v[i]-v[0])^(v[i+1]-v[0])) ;
    };
    return fabs(area)/2.0;
}
////////////////////////////////////////////////
// real work here
////////////////////////////////////////////////
int work(vi a,vi b)
{
    int N = sz(a);

    vector<d2l> connect;

    FOR( i, 0, N)
    {
        d2p le((double)0, (double)a[i]), ri((double)100,(double)b[i]);


    	connect.pb(line2make(le,ri));
    };

    ll cnt = 0;
    set<d2p> inter;
    FOR( i, 0, sz(connect))
    {
    	FOR( j, 0, sz(connect))
    	{
            if ( i != j)
            {
                d2p here;
                if ( line2inter( connect[i], connect[j] , here ))
                {
                    cnt++;
                    if ( here.x >= 0.0 && here.x <=100.0)
                    {
                            inter.insert(here);
                    };

                };
            };
    	};
    };


    return inter.size();
}

int main()
{
    ifstream infile ("GCJinput.txt");
    ofstream outfile ("GCJoutput.txt");
    string line;

    if (infile.is_open())
    {
        getline (infile,line);
        istringstream r(line);
        r>> CN;
        int cid = 0;

        do
        {
            cid++;
            // from here process the input content
            getline (infile,line);
            if (!(line.size () > 0))
                return 0;
            istringstream param(line);
            int p1,p2;
            param >> p1;
            outfile<<"Case #"<<(cid)<<": ";
            vi a;
            vi b;
            FOR( i, 0, p1)
            {
                getline (infile,line);
                istringstream data(line);

                int ta,tb;
                data>>ta;
                a.pb(ta);
                data>>tb;
                b.pb(tb);
            };
              outfile<<work(a,b)<<endl;

        }
        while (! infile.eof() );
        infile.close();
    };
    outfile.close();

    return 0;




}




//D:\G codejam\test_a\main.cpp
//D:\G codejam\test_a\GCJoutput.txt
