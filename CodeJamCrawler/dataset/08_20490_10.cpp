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

int n,m,nn,a;
int i,j,ii,jj,i2,j2;
int q;
int tt,t;
int x,y,k;


int main(){
	freopen("in.txt","rt",stdin);
	freopen("out.txt","wt",stdout);

	scanf("%d",&t);

	For(tt,1,t){

		scanf("%d%d%d",&n,&m,&a);

		if(tt==152)
			tt=152;

		bool ok=0;

		For(ii,0,n) {
			if(ok)break;
			For(jj,0,m){
				if(ok)break;
				For(i2,0,n){
					if(ok)break;
					For(j2,0,m){
						int s=abs((ii)*(j2)-(i2)*(jj));
						if(s==a&&(!ok)){
						printf("Case #%d: 0 0 %d %d %d %d\n",tt,ii,jj,i2,j2);
						ok=1;
						}
					}
				}
			}
		}
			

		if(!ok)
			printf("Case #%d: IMPOSSIBLE\n",tt);


	}




	
	return 0;
}