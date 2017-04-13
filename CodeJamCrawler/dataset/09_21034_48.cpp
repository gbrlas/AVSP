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
char s[110];
int mp[300];

int getd( char c){
	if( isdigit(c) ) return int(c-'0');
	else return int(c-'a'+10);
}


int main() {
	freopen("in.in","rt",stdin);
	freopen("small.txt","wt",stdout);

	cin>>tt;

	For(t,1,tt){
		printf("Case #%d: ",t);
		scanf("%s",s);

		int ln=strlen(s);
		int q=1;
		bool f=0;

		Fill(mp,-1);

		mp[s[0]]=1;

		For(i,1,ln-1){
			if(mp[s[i]]==-1){
				if(!f){
					f=1;
					mp[s[i]]=0;
				}
				else{
					q++;
					mp[s[i]]=q;
				}
			}
		}
		//int mx=0;

		//Rep(i,ln) mx=max(mx,getd(s[i]));

		LL res=0;
		int b=q+1;
		Rep(i,ln) res=res*b+mp[s[i]];


		printf("%lld\n",res);

	}
	
	return 0;
}