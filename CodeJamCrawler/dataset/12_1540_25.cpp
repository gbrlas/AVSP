#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <string.h>
#include <list>
#include <bitset>
#include <sstream>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cctype>
#include <fstream>
using namespace std;

#define GI              ({int t;scanf("%d",&t);t;})
#define GL              ({LL t;scanf("%lld",&t);t;})
#define GD              ({double t;scanf("%lf",&t);t;})
#define FOR(i,a,b)      for(int i=a;i<b;i++)
#define REP(i,n)        FOR(i,0,n)
#define FOREACH(i,a)    for(typeof((a).begin()) i=(a).begin();i!=(a).end();i++)
#define SZ(a)           (int)(a.size())
#define ALL(a)          a.begin(),a.end()
#define SORT(a)         sort(ALL(a));
#define REVERSE(a)      reverse(ALL(a))
#define UNIQUE(a)       SORT(a),(a).resize(unique(ALL(a))-(a).begin())
#define fill(x,a)       memset(x, a, sizeof(x))
#define pb              push_back
#define mp              make_pair
#define INF             (int)1e9
#define EPS             double(1e-9)
#define abs(a)          ((a)<0?-(a):(a))
#define dbg(x)          (cerr << #x << ":" << (x) << endl)

typedef long long LL;
typedef vector< int > VI;
typedef vector< string > VS;
typedef pair< int, int > PII;

int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;} 
template<class T> string toString(T n){ostringstream ost;ost<<n;ost.flush();return ost.str();}


int main()
{	
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small.out","w",stdout);
    bool done[1005];	
	int Kase=GI;
	string a,b;
    FOR(kase,1,Kase+1)
	{
        fill(done,false);
        cin>>a>>b;
        int na=toInt(a), nb=toInt(b), ans=0;
        int dig=SZ(a);
        if(dig==1) ans=0;
        else
        {
            string sc,sd,se;
            int nd,ne;
            FOR(i,na,nb+1)
            {
                sc=toString(i);
                sc+=sc;
                if(dig==2)
                {
                    sd=sc.substr(1,2);
                    nd=toInt(sd);
                    if(nd>=na && nd<=nb && nd!=i && !done[nd]) {done[i]=true; ans++;}
                }
                else if(dig==3)
                {
                    sd=sc.substr(1,3);
                    se=sc.substr(2,5);
                    nd=toInt(sd);
                    ne=toInt(se);
                    if(nd>=na && nd<=nb && nd!=i) ans++;
                    if(ne>=na && ne<=nb && ne!=i && ne!=nd) ans++;
                }
            }
        }
        printf("Case #%d: %d\n",kase,ans);
    }
//while(1);
return 0;
}
