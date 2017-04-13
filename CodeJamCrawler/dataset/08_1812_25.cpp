
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

char S[50010];
int n;



int ocen(string S)
{
	int r=0;
	int last=0;
	REP(i,n)
	{
		if (S[i] != last)
		{
			r++;
			last=S[i];
		}
	}
	return r;
}

string Per(VI p,int k)
{
	string r="";
	REP(j,n/k)
	{
		REP(i,k) r+=S[j*k+p[i]];
	}
	return r;
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
		int k;
		fscanf(in,"%d%s",&k,S);
		n=strlen(S);
		int res=n;
		VI p;
		REP(i,k) p.PB(i);
		do
		{
			res=min(res,ocen(Per(p,k)));
		} while (next_permutation(ALL(p)));
		fprintf(out,"Case #%d: %d\n",zz+1,res);
	}
	fclose(in); fclose(out);
	return 0;
}
