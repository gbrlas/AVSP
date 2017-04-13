#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <time.h>
#include <math.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for (int i=0; i<n; i++)
#define FOR(i,x,y) for (int i=x; i<=y; i++)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
const double pi=acos(-1.0);

int main()
{
	freopen("A-small-attempt0.in","rt",stdin);
	freopen("output.txt","wt",stdout);
	int t;
	cin>>t;
	FOR(tests,1,t)
	{
		printf("Case #%d:\n",tests);
		vector<string> data;
		string tmp;
		int R,C;
		cin>>R>>C;
		FOR(i,1,R)
		{
			cin>>tmp;
			data.push_back(tmp);
		}
		FOR(i,0,R-2)
			FOR(j,0,C-2)
		{
			if (data[i][j]=='#')
			{
				if (data[i+1][j+1]=='#' && data[i+1][j]=='#' && data[i][j+1]=='#')
				{
					data[i][j]='/';
					data[i+1][j+1]='/';
					data[i+1][j]='\\';
					data[i][j+1]='\\';
				}
				else
				{
					cout<<"Impossible"<<endl;
					goto a1;
				}
			}
		}
		FOR(i,0,R-1)
			FOR(j,0,C-1)
				if (data[i][j]=='#')
				{
					cout<<"Impossible"<<endl;
					goto a1;
				}
		FOR(i,0,R-1)
			cout<<data[i]<<endl;
a1:
		int a;

	}
}
