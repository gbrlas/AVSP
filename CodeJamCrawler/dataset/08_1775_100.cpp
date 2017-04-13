
// Headers {{{
#include<iostream>
#include<assert.h>
#include<cstdio>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<list>
#include<deque>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<utility>
#include<sstream>
#include<cstring>
#include<bitset>
#include<numeric>
using namespace std;


#define FOR(I,A,B) for(int I=(A);I<=(B);++I)
#define FORD(I,A,B) for(int I=(A);I>=(B);--I)
#define REP(I,N) for(int I=0;I<(N);++I)
#define VAR(V,init) __typeof(init) V=(init)
#define FORE(I,C) for(VAR(I,(C).begin());I!=(C).end();++I)
#define CLR(A,v) memset((A),v,sizeof((A)))

#define SIZE(x) ((int)((x).size()))
#define ALL(X) (X).begin(),(X).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second

typedef vector<int> VI;
typedef pair<int,int> PI;
typedef long long LL;
typedef vector<string> VS;
// }}}

const int nmx=1000100;
vector<LL> prim;
bool B[nmx];



void error(string s)
{
	fprintf(stderr,"%s\n",s.c_str());
	exit(1);
}

int P[nmx];

int parent(int x)
{
	if(P[x]==x) return x;
	return P[x]=parent(P[x]);
}

int main(int argc,char **args)
{
	FOR(i,2,nmx-1)
	{
		if (!B[i])
		{	
			prim.PB(i);
			for(int j=i+i;j<nmx;j+=i) B[j]=1;
		}
	}
	if (argc != 3) error("Bad arguments");
	FILE *in=fopen(args[1],"r");
	FILE *out=fopen(args[2],"w");
	int z; fscanf(in,"%d",&z);
	REP(zz,z)
	{
	   LL a,b,p;
		fscanf(in,"%lld%lld%lld",&a,&b,&p);
		LL n=(b-a)+1;
		REP(i,n) P[i]=i;
		LL pr;
		FORE(pri,prim)
		{
			pr=*pri;
			if (pr >= p && pr <= b)
			{
				LL x=(b/pr)*pr;
				LL last=x;
				while(x >= a)
				{
					P[parent(last-a)]=parent(x-a);
					x-=pr;
				}	
			}
		}
		int res=0;
		REP(i,n) if (P[i]==i) res++;
		fprintf(out,"Case #%d: %d\n",zz+1,res);
	}
	fclose(in); fclose(out);
	return 0;
}
