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
#include <queue>
#include <sstream>
#include <fstream>
#include <numeric>
using namespace std;

typedef long long  ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll,ll> llll;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<string,string> ss;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef pair<char,char> cc;

#define sz(v) int((v).size())
#define FOR(i, a, b) for (int i(a), _b(b); i < _b; ++i)
#define REP(i, n) for (int i(0), _n(n); i < _n; ++i)
#define ALL(C) (C).begin(), (C).end()
#define INF numeric_limits<int>::max()
#define MINF numeric_limits<int>::min()
#define DODEB 1
#define DB(C) if(DODEB){std::cout<<#C <<" = "<< (C)<<std::endl;}
#define DBV(C) if(DODEB){std::cout<<#C <<" = "; for(__typeof((C).begin()) i = (C).begin(); i != (C).end(); i++){ cout<<*i<<" "; } cout<<endl;}
#define LET(i,e) __typeof(e) i = (e)
#define iter(c)  __typeof((c).begin())
#define PRESENT(c,x) ((c).find(x) != (c).end())
#define CPRESENT(c,x) (find(ALL(c),x) != (c).end())
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define REPD(i, n) for (int i((n)-1); i >= 0; --i)
#define SORT(C) sort(ALL(C))
#define MIN(C) *min_element(ALL(C))
#define MINPOS(C) (int)(min_element(ALL(C)) - (C).begin())
#define MAX(C) *max_element(ALL(C))
#define MAXPOS(C) (int)(max_element(ALL(C)) - (C).begin())
#define SUM(C) accumulate(ALL(C), 0)
#define BE(C) ((C).begin())
#define EN(C) ((C).end())
#define CLEAR(x,with) memset(x,with,sizeof(x))
#define FOREACH(c, i)  if ((c).begin() != (c).end()) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define pb push_back
#define Fi(xy) ((xy).first)
#define Se(xy) ((xy).second)
#define mp make_pair
#define CLC(act,val) (*({act; static __typeof(val) CLCR; CLCR = (val); &CLCR;}))
#define FIRSTP(k,a,b,cond) CLC(LET(k, a); for(; k < (b); ++k) if(cond) break, k)
#define LASTP(k,a,b,cond) CLC(LET(k, b); while((a) <= (--k)) if(cond) break, k)
#define EXISTS(k,a,b,cond) (FIRSTP(k,a,b,cond) < (b))
#define ALLMEET(k,a,b,cond) (!EXISTS(k,a,b,!(cond)))
main()
{
  int c =0; 
  cin >> c; 
  FOR(i,0, c)
  { 
      ld C,F,X;
	  cin >> C  >> F >> X;
	  ld T=0.0, nowSum = 0.0, nowSpeed = 2.0;
	 int n = 0;
	 for(; (X-C)/(2.0+n*F) > X/(2.0+(n+1)*F) ; n++)
	 {
	 }
	 int c=0; 
	 while (c<n)
	 {
	     T+= C/nowSpeed;
		 nowSpeed += F;
		 c++;
	 }
	 T+= X/nowSpeed;
	      cout.precision(15);
	      cout<<"Case #"<<(i+1)<<": " <<T<<endl; 
  }
 
}