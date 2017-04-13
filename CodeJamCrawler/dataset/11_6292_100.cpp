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

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)
#define FORIT(a,aa) for(a=aa.begin();a!=aa.end();++a)
#define split(str) {vs.clear();istringstream sss(str);while(sss>>(str))vs.push_back(str);}

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long ll;
typedef pair<int,int> PII;

typedef pair<char,char> PCC;


double x[1002],y[1002];
int main()
{
  	freopen("A.in","r",stdin);
  	freopen("D.out","w",stdout);
	int T,i,j,l,n,k,p,q;
	x[1]=0;
	x[2]=2;
	y[1]=1;
	FOR(i,2,1001) y[i]=y[i-1]/i;
	FOR(i,2,1001)
	{
		x[i]=i+x[i-1];
		REP(k,i-2) x[i]+=x[k+1]*y[i-k-1]+x[i-k-1]-1;
		x[i]/=i-1;
	}
//	REP(i,5)cout<<x[i]<<endl;
	cin>>T; 
	for (l=1;l<=T;l++)
	{
		cin>>n;
		vector<int> v;
		float ans=0;
		double res=0;
		bool flag[1002];
		memset(flag,0,sizeof(flag));
		REP(i,n) { cin>>p;v.push_back(p-1);}

		REP(i,n) 
		{
			if (!flag[i])
			{
				flag[i]=true;
				j=i;
				q=1;
				while (v[j]!=i)
				{
					q++;
					flag[v[j]]=true;
					j=v[j];
				}
				res+=x[q];
			}
		}	
		ans=res;
		printf("Case #%d: %.6f\n",l,ans);
		
	}
	return 0;
}


