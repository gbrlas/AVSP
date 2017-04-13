#include<algorithm>
using namespace std;

#include<cstdio>
#include<cstdlib>
#include<cstring>

#define REP(i,n) for(int (i)=0,_n=(n);(i)<_n;(i)++)

#define FOR(i,a,b) for(int (i)=a,_b=(b);(i)<_b;(i)++)

char eng[105][105],quer[105];
int flag[105];
int main(){
	int n,s,q,change,qq=1;
	scanf("%d",&n);
	while(n--){
		scanf("%d\n",&s);
		REP(i,s)gets(eng[i]);
		scanf("%d\n",&q);
		memset(flag,0,sizeof(flag));
		change=0;
		REP(i,q){
			gets(quer);
			REP(j,s)if(strcmp(quer,eng[j])==0)flag[j]++;
			int v=1;
			REP(j,s){
				if(flag[j]==0){v=0;break;}
			}
			if(v==1){change++;memset(flag,0,sizeof(flag));}
			REP(j,s)if(strcmp(quer,eng[j])==0)flag[j]++;
		}
		printf("Case #%d: %d\n",qq++,change);
	}

return 0;
}
