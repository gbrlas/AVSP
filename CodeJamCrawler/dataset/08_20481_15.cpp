#include <algorithm> 
#include <numeric>
#include <cmath> 

#include <string> 
#include <vector> 
#include <queue> 
#include <stack> 
#include <set> 
#include <map> 

#include <iostream> 
#include <sstream> 
#include <cstdio> 
#include <cstdlib> 
#include <cctype> 
#include <cassert> 

using namespace std;
#pragma comment(linker, "/STACK:20000000")

// useful defines
#define sz(x) (int)(x).size()
#define For(i,a,b) for( i=(int)(a);i<=(int)(b);++i)
#define Ford(i,a,b) for( i=(int)(a);i>=(int)(b);--i) 
#define Rep(i,n) for (i=0;i<(n);++i)
#define RepV(i,v) for (i=0;i<sz(v);++i)
#define Fill(a,b) memset(&a,b,sizeof(a)) 
#define All(c) (c).begin(),(c).end()
#define Min(a,b) (a)<(b)?(a):(b)
#define Max(a,b) (a)>(b)?(a):(b)
typedef pair <int,int> PI;
typedef pair <PI,int> PII;
typedef vector <int> VI;
typedef vector <string> VS;
typedef vector < PI > VP;

int n;
int i,j;
VI x,y;
int tt,t;
int a;



int main(){
	freopen("in.txt","rt",stdin);
	freopen("out.txt","wt",stdout);

	scanf("%d",&t);

	For(tt,1,t){
		scanf("%d",&n);
		
		x.clear();
		y.clear();

		For(i,1,n){
			scanf("%d",&a);
			x.push_back(a);
		}
		For(i,1,n){
			scanf("%d",&a);
			y.push_back(a);
		}

		sort(All(y));
		sort(All(x));
		
		__int64 q=0;

		if(tt==1001)
			q=0;

		For(i,0,n-1)
			q+=(__int64)x[i]*(__int64)y[n-1-i];

		printf("Case #%d: %I64d\n",tt,q);
			

	}




	
	return 0;
}