#include "cstdio"
#include "iostream"
#include "cmath"
#include "cstring"
#include "algorithm"
#include "queue"
#include "set"
#include "deque"
#include "stack"
#include "map"
#include "vector"
#include "ctime"
#include "cassert"
#include "cctype"
#include "cstdlib"
#include "bitset"
#include "iomanip"
#include "list"
#include "sstream"
#include "utility"
#include "limits"

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <string> vs;

#define FOR(i,a,b) for (int i=(a);i<=(b); i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,a) for (int i=0; i<(a); i++)
#define REPD(i,a) for (int i=((a)-1); i>=0; i--)
#define FIT(it,v) for (typeof ((v).begin())it=(v).begin(); it!=(v).end(); ++it);
#define FITD(it,v) for (typeof ((v).rbegin())it=(v).rbegin(); it!=(v).end(); ++it);

#define PF push_front
#define PB push_back
#define MP make_pair
#define F first
#define S second

template<typename T> T gcd (T a, T b) {return (b==0) ? abs (a) : gcd (b,a%b); }
template<typename T> inline T sqr(T x) {return x*x; }


inline void open()
{
    freopen("test.inp","r",stdin);
    freopen("test.txt","w",stdout);
}
int process()
{
    int u,v;
    int a[5][5],b[5][5];
    cin>>u;
    FOR(i,1,4)
    FOR(j,1,4)
     cin>>a[i][j];
    cin>>v;
    FOR(i,1,4)
    FOR(j,1,4)
     cin>>b[i][j];
    int t=0;
    int r=0;
    FOR(i,1,4)
    FOR(j,1,4)
     if (a[u][i]==b[v][j])
        {
            t++;
            r=a[u][i];
            if (t==2) return(-1);
        }
    if (t==1) return(r);
    return(0);
}

main()
{
    cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
    //open();
    int r,tt;
    cin>>tt;
    REP(_t,tt){
        cout<<"Case #"<<_t+1<<": ";
        int r=process();
        if (r==0) cout<<"Volunteer cheated!";
        else if (r==-1) cout<<"Bad magician!";
         else cout<<r;
        cout<<endl;
    }
}
