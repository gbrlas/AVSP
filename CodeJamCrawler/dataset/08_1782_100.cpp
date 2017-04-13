
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

const int nmx=1000021;
int k;
int T[nmx];
set<int> S;


int POW_TREE[nmx],max_pt;
//+ fun_pt {{{
inline int fun_pt(int x)
{
return (((x-1)^x)+1) >> 1;
}
//+ }}}
//+ update_pt {{{
void update_pt(int x,int vl)
{
	while (x <= max_pt) { POW_TREE[x]+=vl; x+=fun_pt(x);}	
}
//+ }}}
//+ pref_pt {{{
int pref_pt(int x)
{
	int res=0;
	while(x) {res+=POW_TREE[x]; x-=fun_pt(x); }
	return res;
}
//+ }}}



int main(int argc,char **args)
{
	if (argc != 3) error("Bad arguments");
	FILE *in=fopen(args[1],"r");
	FILE *out=fopen(args[2],"w");
	int z; fscanf(in,"%d",&z);
	REP(zz,z)
	{
		int n;
		int Q[100];
		CLR(T,-1);
		fscanf(in,"%d",&k);
		fscanf(in,"%d",&n);
		REP(i,n) fscanf(in,"%d",Q+i);
		int last=0;
		int jest=k;
		max_pt=k+2;
		REP(i,k) update_pt(i+1,1);
		REP(i,k) S.insert(i);
		FOR(i,0,k-1)
		{
			int j=0;
			int need=i%jest;
			int toend=pref_pt(k)-pref_pt(last);
			if (toend <= need)
			{
				need-=toend;
				last=0;
			}
			if (need == 0)
			{
				last=*(S.lower_bound(last));
			}
			else
			{
				FORD(s,23,0)
				{
					if (last + j + (1<<s) < k && pref_pt(last+j+(1<<s)+1) - pref_pt(last) <= need)
						j+=(1<<s);
				}
				j++;
				last+=j;
			}
			assert(T[last]==-1);
			T[last]=i;
			update_pt(last+1,-1);
			S.erase(last);
			jest--;
		}	
		
		fprintf(out,"Case #%d:",zz+1);
		REP(i,n)		fprintf(out," %d",T[Q[i]-1]+1);
		fprintf(out,"\n");
	}
	fclose(in); fclose(out);
	return 0;
}
