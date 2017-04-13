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
#define For(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define Ford(i,a,b) for(int i=(int)(a);i>=(int)(b);--i) 
#define Rep(i,n) for (int i=0;i<(n);++i)
#define RepV(i,v) for (int i=0;i<sz(v);++i)
#define Fill(a,b) memset(&a,b,sizeof(a))   
#define All(a) (a).begin(),(a).end()   
typedef long long LL;
typedef pair <int,int> PI;
typedef pair <double,double> PD;
typedef vector <int> VI;
typedef vector <string> VS;
typedef vector <PI> VP;

int tt;
int n;
int m;
int x;
VI q;
bool v[110];

int main() {
	freopen("in.in","rt",stdin);
	freopen("Csmall.txt","wt",stdout);

	cin>>tt;

	For(t,1,tt){
		printf("Case #%d: ",t);

		scanf("%d",&n);
		scanf("%d",&m);

		q.clear();

		Rep(i,m){
			scanf("%d",&x);
			q.push_back(x);
		}

		sort(All(q));

		int res=1000000000;

		do{
			Fill(v,0);
			v[0]=v[n+1]=1;

			int w=0;

			RepV(i,q){
				v[q[i]]=1;

				int k=q[i]-1;

				while(1){
					if(k==0) break;
					if(v[k]) break;
					w++;
					k--;
				}
				k=q[i]+1;
				while(1){
					if(k==n+1) break;
					if(v[k]) break;
					w++;
					k++;
				}
			}

			res=min(res,w);


		}while(next_permutation(All(q)));

		printf("%d\n",res);



	}
	
	return 0;
}