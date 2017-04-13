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
typedef vector<long double> vld;
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
        int N;
		cin >> N;
		vld a,b;
		FOR(j,0,N)
		{
		    ld x;
			cin >> x ; 
			a.push_back(x);
		}
		FOR(j,0,N)
		{
		    ld x;
			cin >> x ; 
			b.push_back(x);
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		int bstA=0, bstB=0;
		//DBV(a);
		//DBV(b);
		vld aa = a;
		vld bb = b;
		FOR(k,0,N)
		{
		//DB(k);
			//	DBV(aa);DBV(bb);
		   if( aa[0] < bb[0] )
		   {
		        aa.erase(aa.begin());
				bb.erase(bb.begin());
				
		        continue;
		    }
			else 
			{
			     vld::iterator it = bb.begin(); 
				 for(; *it <=aa[0]  && it != bb.end(); it++) 
				     ;
			     if( it == bb.end() ) 
				{
				    bstB += aa.size(); 
					break;
 				 }
				 else {
				    bb.erase(it);
					aa.erase(aa.begin());
				 }
			}
		}
		
		
		aa=a;
		bb=b;
		FOR(k,0,N)
		{
		//DB(k);
	    //DBV(aa);DBV(bb);
		    if(aa[0] >= bb[bb.size()-1] ) 
			{
			     bstA += aa.size();
			     break;
			}else 
			{
			   if( aa[0] > bb[0] )
			   {
			     aa.erase(aa.begin());
				 bb.erase(bb.begin());
				 bstA ++;
			   }
			   else
			   {
			   aa.erase(aa.begin());
			   bb.erase(bb.end()-1); 
			   }
			}
		}
    	cout<<"Case #"<<(i+1)<<": "<<bstA<<" " <<bstB <<endl; 
  }
 
}