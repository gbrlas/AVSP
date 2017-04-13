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
#include <ctime> 

using namespace std;
#pragma comment(linker, "/STACK:20000000")

// useful defines
#define sz(x) (int)(x).size()
#define For(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define Ford(i,a,b) for(int i=(int)(a);i>=(int)(b);--i) 
#define Rep(i,n) for (int i=0;i<(n);++i)
#define RepV(i,v) for (int i=0;i<sz(v);++i)
#define Fill(a,b) memset(&a,b,sizeof(a)) 
#define All(c) (c).begin(),(c).end()
#define Min(a,b) (a)<(b)?(a):(b)
#define Max(a,b) (a)>(b)?(a):(b)
typedef pair <int,int> PI;
typedef pair <PI,int> PII;
typedef vector <int> VI;
typedef vector <string> VS;
typedef vector < PI > VP;

struct node{
	int q[30];
	node(){
		Fill(q,-1);
	}
};

int n;
int ln1, ln2;
char s[5005];
char q[]="welcome to code jam";
int dp[5005][55];

int go(int p1, int p2){
	if(p1==ln1) return 1;
	if(p2==ln2) return 0;
	if(dp[p1][p2]!=-1) return dp[p1][p2];

	int res=0;
	if(s[p2]==q[p1]) res=(res+go(p1+1,p2+1))%10000;
	res=(res+go(p1,p2+1))%10000;
	return dp[p1][p2]=res;
}




int main(){
	freopen("in.in","rt",stdin);
	freopen("small.txt","wt",stdout);


	ln1=strlen(q);

	scanf("%d\n",&n);

	For(t,1,n){
		gets(s);
		ln2=strlen(s);
		Fill(dp,-1);
		printf("Case #%d: %.4d\n",t,go(0,0));		
	}




	return 0;
}
