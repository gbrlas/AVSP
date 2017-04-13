#include <vector>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)

int getlen(int num)
{
	char str[11];
	return sprintf(str,"%d",num);
}

int tpow[10];

int main()
{
	int T;
	scanf("%d",&T);
	tpow[0]=1;
	REP(i,9)
		tpow[i+1]=tpow[i]*10;
	REP(test,T)
	{
		int A,B;
		scanf("%d%d",&A,&B);
		long long res=0;
		FOR(i,A,B+1)
		{
			int len=getlen(i);
			int c=i;
			REP(j,len-1)
			{
				c=c/tpow[len-1]+(c%tpow[len-1])*10;
//				if(A<=c&&c<=B&&getlen(c)!=len) printf("BAD");
				if(i<c&&A<=c&&c<=B) {res++;}
				if(c==i) break;
			}
		}
		printf("Case #%d: %lld\n",test+1,res);
	}
	return 0;
}
