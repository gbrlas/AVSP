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


const int lentmp=105;
void error(string s)
{
	fprintf(stderr,"%s\n",s.c_str());
	exit(1);
}
map<string,int> M;
int n,q;
int Q[1001];
int R[101];

int main(int argc,char **args)
{
	if (argc != 3) error("Bad arguments");
	FILE *in=fopen(args[1],"r");
	FILE *out=fopen(args[2],"w");
	int z; fscanf(in,"%d",&z);
	int mx=0;
	REP(zz,z)
	{
		M.clear();
		fscanf(in,"%d\n",&n);
		char tmp[lentmp];
		REP(i,n) 
		{
			fgets(tmp,104,in);
			int l=strlen(tmp);
			mx=max(mx,l);
			tmp[l-1]=0;
			M[tmp]=i;
		}
		fscanf(in,"%d\n",&q);
		REP(i,q)
		{
			fgets(tmp,104,in);
			int l=strlen(tmp);
			mx=max(mx,l);
			tmp[l-1]=0;
			Q[i]=M[tmp];
		}
		CLR(R,0);
		FORD(i,q-1,0)
		{
			int mn[2];
			mn[0]=mn[1]=10000;
			REP(j,n) 
			if (R[j] <= mn[0])
			{
				mn[1]=mn[0];
				mn[0]=R[j];
			}
			else
			mn[1]=min(mn[1],R[j]);
			REP(j,n)
			{
				int res=R[j];
				if (Q[i]==j) res=10000;
				else
				{
					if (R[j] != mn[0])
						res=min(res,mn[0]+1);
					else 
						res=min(res,mn[1]+1);
				}
				R[j]=res;
			}
		}
		fprintf(out,"Case #%d: ",zz+1);
		int res=R[0]; REP(i,n) res=min(res,R[i]);
		fprintf(out,"%d\n",res);
	}
	fprintf(stderr,"Max:%d\n",mx);
	fclose(in); fclose(out);
	return 0;
}
