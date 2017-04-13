
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

const int nmx=10000;
int n;
LL T[3][3];
LL res;

int B[3][3];
void fun(int z,int a,int b,LL was)
{
	if (z==3) 
	{
		if (a%3==0 && b%3==0)	res+=was;
		return;
	}
	REP(i,3)
		REP(j,3) if(B[i][j] < T[i][j])
		{
			B[i][j]++;
			fun(z+1,a+i,b+j,was*(T[i][j]-(LL)(B[i][j]-1)));
			B[i][j]--;
		}
}



int main(int argc,char **args)
{
	if (argc != 3) error("Bad arguments");
	FILE *in=fopen(args[1],"r");
	FILE *out=fopen(args[2],"w");
	int z; fscanf(in,"%d",&z);
	REP(zz,z)
	{
		LL a,b,c,d,x,y,m;
		CLR(T,0);
		fscanf(in,"%d%lld%lld%lld%lld%lld%lld%lld",&n,&a,&b,&c,&d,&x,&y,&m);
		REP(i,n)
		{
			T[x%3][y%3]++;
			x=(a*x+b)%m;
			y=(c*y+d)%m;
		}
		res=0;
		CLR(B,0);
		fun(0,0,0,1);
		fprintf(out,"Case #%d: %lld\n",zz+1,res/6LL);
	}
	fclose(in); fclose(out);
	return 0;
}
