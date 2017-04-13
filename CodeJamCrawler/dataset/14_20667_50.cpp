#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define FORD(i,h,l) for(int i=(h);i>=(l);--i)

//#define coutpoint5 setiosflags(ios::fixed)<<setprecision(5)

#define maxn 10
#define maxm 10
//#define MM 1000000007

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

string s[maxm];

int m,n;
int ans,anscount;

int p[maxn][maxm];

void cal()
{
	int sum=0;
	FOR(i,1,n)
	{
		if (p[i][0]==0) return;
		FOR(j,1,p[i][0])
		{
			int len=0;
			FOR(k,1,j-1)
			{
				int minlen=min(s[p[i][j]].size(),s[p[i][k]].size());
				int t;
				for(t=0;t<minlen && s[p[i][j]][t]==s[p[i][k]][t];t++);
				len=max(len,t);
			}
			sum+=s[p[i][j]].size()-len;
		}
	}
	if (sum==ans)
		anscount++;
	else if (sum>ans)
	{
		ans=sum;
		anscount=1;
	}
	return;
}			

void dfs(int step)
{
	if (step==m+1)
	{
		cal();
		return;
	}
	FOR(i,1,n)
	{
		p[i][0]++;
		p[i][p[i][0]]=step;
		dfs(step+1);
		p[i][0]--;
	}
}

int main()
{
	freopen("D-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	//ios_base::sync_with_stdio(false);
	
	int T;
	scanf("%d",&T);
	FOR(TT,1,T)
	{
		printf("Case #%d: ",TT);
		scanf("%d%d",&m,&n);
		FOR(i,1,m)
			cin>>s[i];
		//FOR(i,1,m)
		//	cout<<s[i]<<endl;
		ans=0,anscount=0;
		memset(p,0,sizeof(p));
		dfs(1);
		/*p[1][0]=p[2][0]=2;
		p[1][1]=1; p[1][2]=4;
		p[2][1]=2; p[2][2]=3;
		cal();*/
		printf("%d %d\n",ans+n,anscount);
	}

	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
