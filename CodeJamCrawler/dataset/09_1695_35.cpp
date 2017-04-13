#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>

using namespace std;

#define REP(i,n) for(int i=0,_n=(n);i<_n;i++)
#define FOR(i,a,b) for(int i=(a),_n=(b);i<=_n;i++)

typedef __int64 LL;

LL n;
int d[25];

int main(){
	freopen( "B-large.in", "r", stdin );
	freopen( "B-large.out", "w", stdout );
	int t;
	char x[25];
	scanf("%d",&t);
	REP(j,t){
		scanf("%s\n",x);
		
		int len=strlen(x);
		d[0]=0;
		REP(i,len){
			d[i+1]=x[i]-'0';
		}
			
		LL s=d[0];
		FOR(i,1,len){
			s*=10;
			s+=d[i];
		}
		
		next_permutation(d,d+len+1);
		
	//	LL res=d[0];
	//	FOR(i,1,len){
	//		res*=10;
	//		res+=d[i];
	//	}
		
	//	d[len++]=0;
	/*	
		while(res<=s){
			next_permutation(d,d+len);
		
			res=d[0];
			FOR(i,1,len-1){
				res*=10;
				res+=d[i];
			}
		}
		*/
		
		printf("Case #%d: ",j+1);
		REP(i,len+1){
			if(i==0 && d[i]==0){}
			else printf("%d",d[i]);
		}
		printf("\n");
	}

return 0;
}
