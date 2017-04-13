
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

LL mod=10007;
LL T[500][500];
bool B[500][500];
int tx,ty;
LL fun(int y,int x)
{
	if (tx==x && ty==y) return 1;
	if (y>ty || x>tx) return 0;
	if (B[y][x]) return 0;
	if (T[y][x]!=-1) return T[y][x];
	T[y][x]=(fun(y+2,x+1)+fun(y+1,x+2))%mod;
	return T[y][x];
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
		CLR(B,0);
		CLR(T,-1);
		int w,h,r;
		fscanf(in,"%d%d%d",&tx,&ty,&r);
		while(r--)
		{
			fscanf(in,"%d%d",&w,&h);
			B[h][w]=1;
		}


		fprintf(out,"Case #%d: %lld\n",zz+1,fun(1,1));
	}
	fclose(in); fclose(out);
	return 0;
}
