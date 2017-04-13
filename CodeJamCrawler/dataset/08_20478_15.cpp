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
int q;
VI x,y;
int tt,t;



int main(){
	freopen("in.txt","rt",stdin);
	freopen("out.txt","wt",stdout);

	scanf("%d",&t);

	For(tt,1,t){
		scanf("%d",&n);
		
		x.clear();
		y.clear();

		For(i,1,n){
			scanf("%d",&q);
			x.push_back(q);
		}
		For(i,1,n){
			scanf("%d",&q);
			y.push_back(q);
		}

		int mn=1000000000;

		sort(All(y));

		do{
			int qq=0;
			For(i,0,n-1)
				qq+=x[i]*y[i];
			if(qq<mn)mn=qq;
		}while(next_permutation(All(y)));

		printf("Case #%d: %d\n",tt,mn);

	}




	
	return 0;
}