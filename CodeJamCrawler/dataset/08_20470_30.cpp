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
#define RepV(i,v) for (int i=0;i<sz(v);++i)
#define Fill(a,b) memset(&a,b,sizeof(a)) 
#define All(c) (c).begin(),(c).end()
#define Min(a,b) (a)<(b)?(a):(b)
#define Max(a,b) (a)>(b)?(a):(b)
typedef pair <int,int> PI;
typedef pair <PI,int> PII;
typedef vector <int> VI;
typedef vector <string> VS;
typedef vector <PI> VP;

int n;
int s,q;
int tt,i,j,k;
int res;
string ss;
string qq[1010];
string sm[1010];
int dp[1010][1010];

/*map<string,int> mp;
map<string,int>::iterator it;*/


int main(){
	freopen("in.txt","rt",stdin);
	freopen("out.txt","wt",stdout);

	cin>>n;

	For(tt,1,n){

		cin>>s;
		getline(cin,ss);

		For(i,1,s)
			getline(cin,sm[i]);
		
	
		cin>>q;
		res=q;
		getline(cin,ss);

		For(i,1,q)
			getline(cin,qq[i]);

		Fill(dp,127);

		For(i,1,s)
			if(qq[1]!=sm[i])
				dp[1][i]=0;
			else dp[1][i]=1;
		
		For(i,2,q)
			For(j,1,s)
				For(k,1,s)
					if(sm[j]!=qq[i]){
						dp[i][j]=Min(dp[i][j],dp[i-1][k]+(k!=j));
					}
		res=1<<30;

		if(q==0)res=0;

		For(i,1,s)
			res=Min(res,dp[q][i]);


		cout<<"Case #"<<tt<<": "<<res<<endl;
		
	}

	
	return 0;
}