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

int m,d,n;
char w[5005][25];
char s[10005];
bool x[10005][30];
node v[1000005];
int nn,ln;

void add(int i, int j, int k){
	if(j==m) return;
	if(v[k].q[w[i][j]-'a']!=-1) add(i,j+1,v[k].q[w[i][j]-'a']);
	else{
		nn++;
		v[k].q[w[i][j]-'a']=nn;
		add(i,j+1,nn);
	}
}

int go(int j,char z, int k){
	if(k==-1) return 0;
	if(j==ln) return 1;
	if(j==m) return 0;
	int res=0;
	For(c,'a'-'a','z'-'a') 
		if(x[j][c]) res+=go(j+1,c+'a',v[k].q[c]);
	return res;
}



int main(){
	freopen("in.in","rt",stdin);
	freopen("large.txt","wt",stdout);

	scanf("%d",&m);
	scanf("%d",&d);
	scanf("%d\n",&n);


	Rep(i,d){
		gets(w[i]);
		add(i,0,0);
	}

	For(t,1,n){
		gets(s);
		Fill(x,0);
		ln=strlen(s);
		int p=0;
		int l=0;
		bool op=0;
		while(p<ln){
			if(s[p]=='('){
				op=1;
				p++;
				continue;
			}
			if(s[p]==')'){
				op=0;
				l++;
				p++;
				continue;
			}
			x[l][s[p]-'a']=1;
			if(!op) l++;
			p++;
		}
		ln=l;
		printf("Case #%d: %d\n",t,go(0,'*',0));
	}




	return 0;
}
