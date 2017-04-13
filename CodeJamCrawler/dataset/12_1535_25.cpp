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

#define GI              ({int t;scanf("%d\n",&t);t;})
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

int main()
{	
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-practice.out","w",stdout);
   
    char s[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
	string inp,ans; 
	int Kase=GI;
    FOR(kase,1,Kase+1)
    {
        getline(cin,inp);
        int n=SZ(inp);
        REP(i,n)
        {
            if(inp[i]==' ') ans[i]=' ';
            else ans[i]=s[inp[i]-'a'];
        }
     	printf("Case #%d: ",kase);
     	REP(i,n) cout<<ans[i];
     	cout<<endl;
    }
//while(1);
return 0;
}
