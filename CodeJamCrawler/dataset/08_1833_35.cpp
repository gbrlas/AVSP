
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

const int mxk=1<<10;

int T[11][mxk];
int h,w;
char C[20][20];


int fun(int y,int mask)
{
	if (y==h) return 0;
	if (T[y][mask]!=-1) return T[y][mask];
	int bad=0;
	T[y][mask]=0;
	REP(x,w) if(C[y][x]=='x') bad|=(1<<x);
	REP(x,w)
	{
		if(mask&(1<<x))
		{
			if (x+1 <w) bad|=(1<<(x+1));
			if (x) bad|=(1<<(x-1));
		}	
	}
	REP(d,(1<<w))
	{
		bool ok=1;
		FOR(x,1,w-1)	if( (d&(1<<x)) && (d&(1<<(x-1)))) ok=0;
		if (!ok) continue;
		int cost=0;
		if ((bad & d)==0)
		{
			
			REP(x,w) if (d&(1<<x)) cost++;
			T[y][mask]=max(T[y][mask],cost+fun(y+1,d));
		}

	}
	return T[y][mask];
}





int main(int argc,char **args)
{
	if (argc != 3) error("Bad arguments");
	FILE *in=fopen(args[1],"r");
	FILE *out=fopen(args[2],"w");
	int z; fscanf(in,"%d",&z);
	REP(zz,z)
	{
		fprintf(stderr,"Working on %d / %d\n",zz+1,z);
		fscanf(in,"%d%d",&h,&w);
		CLR(T,-1);
		REP(y,h) fscanf(in,"%s",C[y]);

		fprintf(out,"Case #%d: %d\n",zz+1,fun(0,0));
	}
	fclose(in); fclose(out);
	return 0;
}
