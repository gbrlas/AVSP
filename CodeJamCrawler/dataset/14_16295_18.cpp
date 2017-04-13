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
int b[1000][1000];
main()
{
    cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
    //open();
    int t,n,res;
    cin>>t;
    REP(_t,t){
        map<string,int> m;
        cin>>n;
        string s,ss;
        FOR(i,1,n){
         cin>>s;
         ss="";
         ss+=s[0];
         int t=0;
         b[i][0]=1;
         REP(j,s.length())
          if (j!=0){
            if (s[j]==s[j-1]) b[i][t]++;
            else {
                ss+=s[j];
                t++;
                b[i][t]=1;
            }
          }
         m[ss]++;
        }
        if (m.size()>1) cout<<"Case #"<<_t+1<<": Fegla Won"<<endl;
        else{
            res=0;
            REP(j,ss.length())
            {
                int t=0;
                FOR(i,1,n) t+=b[i][j];
                t/=n;
                FOR(i,1,n)
                 res+=abs(t-b[i][j]);
            }
            cout<<"Case #"<<_t+1<<": "<<res<<endl;
        }
    }
}
