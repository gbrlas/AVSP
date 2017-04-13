#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

#define FILL(a,val) memset((a),(int)val,sizeof(a));
#define CLEAR(a) FILL(a,0)
#define REP(i,n) for (int i=0, _n=(n); i<_n; ++i)
#define FOR(i,a,b) for (int i=(a), _n=(b); i<_n; ++i)
#define REPD(i,n) for (int _n=(n), i=_n; i>=0; --i)
#define FORD(i,b,a) for (int _n=(b), _a=(a), i=_n; i>=_a; --i)
#define PB push_back
#define VI vector<int>
#define VVI vector< VI >
#define MII map<int,int>
#define SZ(x) (x.size())

template <class T> inline void checkmin(T& a, const T& b){if (b<a) a=b;}
template <class T> inline void checkmax(T& a, const T& b){if (b>a) a=b;}
template <class T> inline T sqr(const T&a){return a*a;}
//bool myfunc(int i,int j){return i<j;}
//////////////////////////////////////////
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
//////////////////////////////////////////

//double round(double d){
//	return d>=0? floor(d+0.5): -floor(-d+0.5);
//}

int main(){
	int T;
	scanf("%d",&T);
	REP(t,T){
		int n;
		scanf("%d",&n);
		string s;
		int num;
		vector<PII> V;
		REP(i,n){	
			cin>>s>>num;			
			V.PB(PII(s[0]=='B'?1:0,num)); //0=O,1=B
		}

		//solve
		int total_count=0;
		int M=SZ(V);
		int p[2]={1,1};				
		int acc[2]={0,0};
		REP(step,M){
			int who=V[step].first;
			int pos_dif=abs(p[who]-V[step].second);
			int steps_done=max(0,pos_dif-acc[who])+1;
			total_count+=steps_done;
			p[who]=V[step].second;
			acc[who]=0;
			acc[1-who]+=steps_done;
		}

		//output	
		printf("Case #%d: %d\n",t+1,total_count);
	}
	return 0;
}

