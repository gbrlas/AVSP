#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

#define REP(i,n) for(int i=0,_n=(n);i<_n;i++)
#define FOR(i,a,b) for(int i=(a),_n=(b);i<=_n;i++)

char data[5250][20];

int main(){
	int l,d,n;
	scanf("%d %d %d",&l,&d,&n);
	REP(i,d){
		scanf("%s",&data[i]);
	}
	char ss[300];
	REP(i,n){
		scanf("%s",&ss);
		int res=0;
		REP(j,d){
			int lo=0,len=strlen(ss),val=0;
			REP(k,l){
				val=0;
				if( ss[lo]=='(' ){
					lo++;
					while(ss[lo]!=')'){
						if(data[j][k]==ss[lo])val=1;
						lo++;
					}
					lo++;
				}
				else if(ss[lo++]==data[j][k])val=1;
				if(val==0)break;
			}
			if(val==1)res++;
		//	printf(" %s %d\n",data[j],res);
		}
		
		printf("Case #%d: %d\n",i+1,res);
	}

return 0;
}
