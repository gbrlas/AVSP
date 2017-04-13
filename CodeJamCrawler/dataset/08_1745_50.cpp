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

int readTime(string s)
{
	return 60*( (s[0]-'0')*10+s[1]-'0')+(s[3]-'0')*10+s[4]-'0';
}

multiset<int> AO,AI,BO,BI;

int main(int argc,char **args)
{
	if (argc != 3) error("Bad arguments");
	FILE *in=fopen(args[1],"r");
	FILE *out=fopen(args[2],"w");
	int z; fscanf(in,"%d",&z);
	REP(zz,z)
	{
		AO.clear(); AI.clear(); BO.clear(); BI.clear();
		int time,na,nb;
		fscanf(in,"%d",&time);
		fscanf(in,"%d%d",&na,&nb);
		char t1[10],t2[10];
		REP(i,na)
		{
			fscanf(in,"%s%s",t1,t2);
			AO.insert(readTime(t1));
			BI.insert(readTime(t2)+time);
		}
		REP(i,nb)
		{
			fscanf(in,"%s%s",t1,t2);
			BO.insert(readTime(t1));
			AI.insert(readTime(t2)+time);
		}
		int ra=0,rb=0;
		while (!AO.empty() || !BO.empty())
		{
			if (AO.empty() || (!BO.empty() && *AO.begin() > *BO.begin()))
			{
				int t=*BO.begin();
				BO.erase(BO.begin());
				if (BI.empty() || *BI.begin() > t)
					BI.insert(t),rb++;
				BI.erase(BI.begin());
			}
			else
			{
				int t=*AO.begin();
				AO.erase(AO.begin());
				if (AI.empty() || *AI.begin() > t)
					AI.insert(t),ra++;
				AI.erase(AI.begin());
			}
		}
		fprintf(out,"Case #%d: ",zz+1);
		fprintf(out,"%d %d\n",ra,rb);
	}
	fclose(in); fclose(out);
	return 0;
}
