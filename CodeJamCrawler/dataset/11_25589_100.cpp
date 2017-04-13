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

const int MAX = 1000+1;
const double EPS = 1e-9;
int A[MAX];
long double AVG[MAX];
int used[MAX];

long double avg(int n){	
	if (AVG[n]<0.0){
		if (n==1 || n==0){
			AVG[n] = n;		
		}else{			
			double a1 = 0, a2=0;			
			int step=1;
			double prob=1.0;
			
			for(;;){				
				FOR(i,1,n){
					a2 += step * prob * 1.0/n * avg(n-1);
				}
				prob *= 1.0/n;
				double diff = abs(a1-a2);
				if (diff<EPS){
					break;
				}
				a1=a2;
				step++;
			}
			AVG[n] = a2;
		}
	}
	return AVG[n];
}

int main(){
	freopen("D-large.in", "rt", stdin);
    freopen("D-large.out", "wt", stdout);
	
	//REP(i,MAX) AVG[i]=-1.0;
	/*FOR(i,1,MAX) {
		printf("%d = %.6f\n",i,avg(i)); // AVG[i] = i !!!
	}*/

	int T;
	scanf("%d",&T);
	REP(t,T){
		double answer = 0.0;
		int N;
		scanf("%d", &N);
		REP(i,N) scanf("%d",&A[i]), used[i]=0;

		//solve
		REP(i,N) if (used[i]==0){
			int j=i, count=0;						
			while ((used[j])==0){
				used[j]=1;
				int next = A[j]-1;
				count++;
				j=next;
			}
			answer += count>1 ? count : 0; //should be function!
		}

		//output	
		printf("Case #%d: %.6f\n",t+1,answer);
	}
	return 0;
}