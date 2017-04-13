
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


void error(string s)
{
	fprintf(stderr,"%s\n",s.c_str());
	exit(1);
}

const int inf=1000000;
const int nmx=10010;
int T[2][nmx];
int C[nmx];
int G[nmx];
int V[nmx];
int n;



int fun(int x,int v)
{
	if (T[v][x]!=-1) return T[v][x];
	T[v][x]=inf;
	if( x*2 > n)
	{ //lisc
		if (V[x]==v) T[v][x]=0;
	}
	else
	{
		if (v)
		{
			int o=G[x];
			if (C[x] || !o)
			{
				T[v][x]=min(T[v][x],fun(x*2,0)+fun(x*2+1,1)+o);
				T[v][x]=min(T[v][x],fun(x*2,1)+fun(x*2+1,0)+o);
				T[v][x]=min(T[v][x],fun(x*2,1)+fun(x*2+1,1)+o);
			}
			o=abs(G[x]-1);
			if (C[x] || !o)
				T[v][x]=min(T[v][x],fun(x*2,1)+fun(x*2+1,1)+o);
		}
		else
		{
			int o=G[x];
			if (C[x] || !o)		T[v][x]=min(T[v][x],fun(x*2,0)+fun(x*2+1,0)+o);
			o=abs(G[x]-1);
			if (C[x] || !o)
				T[v][x]=min(T[v][x],fun(x*2,1)+fun(x*2+1,0)+o);
			if (C[x] || !o)
				T[v][x]=min(T[v][x],fun(x*2,0)+fun(x*2+1,1)+o);
			if (C[x] || !o)
				T[v][x]=min(T[v][x],fun(x*2,0)+fun(x*2+1,0)+o);
		}
	}
	if (T[v][x] >= inf) T[v][x]=inf;
	return T[v][x];
}



int main(int argc,char **args)
{
	if (argc != 3) error("Bad arguments");
	FILE *in=fopen(args[1],"r");
	FILE *out=fopen(args[2],"w");
	int z; fscanf(in,"%d",&z);
	REP(zz,z)
	{		
		CLR(T,-1);
		fprintf(stderr,"Working on %d / %d\n",zz+1,z);
		int v;
		fscanf(in,"%d%d",&n,&v);
		int d=1;
		REP(i,(n-1)/2)
		{
			fscanf(in,"%d%d",G+d,C+d);
			d++;
		}
		REP(i,(n+1)/2)
		{
			fscanf(in,"%d",V+d);
			d++;
		}
		int r=fun(1,v);
		if (r >= inf)
			fprintf(out,"Case #%d: IMPOSSIBLE\n",zz+1);
		else
			fprintf(out,"Case #%d: %d\n",zz+1,r);
	}
	fclose(in); fclose(out);
	return 0;
}
