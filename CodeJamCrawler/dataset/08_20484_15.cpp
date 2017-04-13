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

int n,m,nn;
int i,j;
int q;
int tt,t;
int x,y,k;
int fr[1010];
int pl;
int p,l,mn;




int main(){
	freopen("in.txt","rt",stdin);
	freopen("out.txt","wt",stdout);

	scanf("%d",&t);

	For(tt,1,t){
		scanf("%d%d%d",&p,&k,&l);

		For(i,1,l)
			scanf("%d",&fr[i]);

		sort(fr+1,fr+1+l);

		mn=0;
		q=1;
		i=l;
		pl=1;

		while(i>0){
			if(q>k){
				q=1;
				pl++;
			}
			mn+=fr[i]*pl;
			q++;
			i--;
		}



		printf("Case #%d: %d\n",tt,mn);


	}




	
	return 0;
}