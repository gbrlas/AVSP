#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <cstring>
#include <cctype>
#include <queue>
#include <list>
#include <cstdlib>
#include <cmath>
#include <deque>
using namespace std;

typedef long long LL;
typedef pair<int,int> para;
typedef vector<int> VI;
typedef vector<vector<int> > VII;
typedef vector<string> VS;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define fore(a,n) for(typeof(n.begin())a=n.begin();a!=n.end();++a)
#define REP(a,n) for(int a=0;a<(n);a++)
#define ALL(x) x.begin(),x.end()

int D;
int t,na,nb;

struct pol{
	para dt,at;
	int dir;//direction 0:A->B or 1:B->A
}x,tpol[207];

multiset<para> rt[2];//ready trains at A and B

inline void popraw(para & x){
	if(x.S >= 60){
		x.S-=60;
		x.F++;
	}
}

bool por(const pol & a, const pol & b){
	return a.dt<b.dt;
}

int main()
{
	scanf("%d",&D);
	REP(I,D){
		scanf("%d %d %d",&t,&na,&nb);//reading input
		int l=0;
		REP(i,na){
			scanf("%d:%d %d:%d",&x.dt.F,&x.dt.S,&x.at.F,&x.at.S);
			x.dir=0;
			tpol[l++]=x;
		}
		REP(i,nb){
			scanf("%d:%d %d:%d",&x.dt.F,&x.dt.S,&x.at.F,&x.at.S);
			x.dir=1;
			tpol[l++]=x;
		}
		REP(j,2)
			rt[j].clear();
		sort(tpol,tpol+l,por);
		int res[2]={0,0};
		//simulation
		REP(i,l){
			x=tpol[i];
			if(rt[x.dir].empty() || ((*rt[x.dir].begin()) > x.dt) ){//not enough trains
				res[x.dir]++;
			}
			else{
				rt[x.dir].erase(rt[x.dir].begin());
			}
			para next = x.at;
			next.S+=t;
			popraw(next);
			rt[(x.dir+1)%2].insert(next);//new train
		}
		printf("Case #%d: %d %d\n",I+1,res[0],res[1]);
	}
	return 0;
}
