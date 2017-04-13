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

//#define maxn 5005
//#define maxm 1000000
//#define MAXP 12

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;
 


int main()
{
	freopen("B-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	//ios_base::sync_with_stdio(false);
	
	int T;
	scanf("%d",&T);
	FOR(TT,1,T)
	{
		printf("Case #%d: ",TT);
		double c,f,x;
		scanf("%lf%lf%lf",&c,&f,&x);
		if (c>x)
		{
			printf("%.7lf\n",x/2);
			continue;
		}
		double ans=0;
		double v=2;
		while (true)
		{
			if (x/(f+v)<(x-c)/v)
			{
				ans+=c/v;
				v+=f;
			}
			else break;
		}
		ans+=x/v;
		printf("%.7lf\n",ans);
	}

	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
