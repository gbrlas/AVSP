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

main()
{
    cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
    //open();
    int tt;
    double C,F,X;
    cin>>tt;
    REP(_t,tt){
        cin>>C>>F>>X;
        //cout<<C<<" "<<F<<" "<<X<<endl;
        double res=X/2;
        double v=2;
        double r=0;
        do{
            r+=C/v;
            v+=F;
            if (r+X/v-res>0) {
                    //res=r+X/v;
                    break;
            }
            else res=r+(X/v);
        }
        while (true);
        cout<<"Case #"<<_t+1<<": ";
        //printf("%.7lf\n",res);
        cout << fixed << setprecision(7);
        cout<<res<<endl;
    }
}
