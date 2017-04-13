
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



int main(int argc,char **args)
{
	if (argc != 3) error("Bad arguments");
	FILE *in=fopen(args[1],"r");
	FILE *out=fopen(args[2],"w");
	int z; fscanf(in,"%d",&z);
	REP(zz,z)
	{
		fprintf(stderr,"Working on %d / %d\n",zz+1,z);
		int a,n,m;
		fscanf(in,"%d%d%d",&n,&m,&a);
		bool ok=0;
		FOR(x1,0,n)
			FOR(x2,0,n)
				FOR(y1,0,m)
				{
					if (ok) break;
					FOR(y2,0,m) 
					if(!ok && x1*y2-x2*y1 == a)
					{
							fprintf(out,"Case #%d: 0 0 %d %d %d %d\n",zz+1,x1,y1,x2,y2);
						ok=1;	
					}
				}

		if (!ok)
		fprintf(out,"Case #%d: IMPOSSIBLE\n",zz+1);
	}
	fclose(in); fclose(out);
	return 0;
}
