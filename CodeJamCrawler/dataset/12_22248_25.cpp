#include <algorithm> 
#include <numeric>
#include <cmath> 

#include <string> 
#include <string.h>
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

int n;
char dict[] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
char s[105],q[105];

int main() {
	freopen("in.txt","rt",stdin);
	freopen("out.txt","wt",stdout);

	scanf("%d\n",&n);

	Rep(tt,n){
		gets(s);
		

		int ln = strlen(s);

		Rep(i,ln)if(isalpha(s[i])) s[i] = dict[s[i]-'a'];

		printf("Case #%d: %s\n",tt+1,s);
		//puts(s);
	}


	return 0;
}