#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <cstdlib>
#include <cmath>
#include <list>

using namespace std;

#define FOR(i,a,b) for(int i=(a),_b(b);i<_b;++i)
#define FORD(i,a,b) for(int i=(a),_b(b);i>=_b;--i)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) (a).begin(),a.end()
#define SORT(a) sort(ALL(a))
#define UNIQUE(a) SORT(a),(a).resize(unique(ALL(a))-a.begin())
#define SZ(a) ((int) a.size())
#define pb push_back

#define VAR(a,b) __typeof(b) a=(b)
#define FORE(it,a) for(VAR(it,(a).begin());it!=(a).end();it++)
#define X first
#define Y second

typedef pair<int,int> PII;
typedef vector<PII> VPII;

#define INF 1000000000


int main(void)
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	int dx[]={-1,0,0,1};
	int dy[]={0,-1,1,0};

	int tt;
	cin >> tt;
	
	REP(t,tt)
	{
		int n,m;
		cin >> n >> m;

		cout << "Case #" << t+1 << ":" << endl;
		vector<vector<int>> ma(n);

		REP(i,n)
		{
			REP(j,m)
			{
				int tmp;
				cin >> tmp;
				ma[i].pb(tmp);
			}		
		}

		vector<vector<int>> ans;
		REP(i,n)
			ans.pb(vector<int>(m));

		int C=1;

		
		REP(i,n)
			REP(j,m)
			{
				if(!ans[i][j])
				{
					int x=i,y=j;
					vector<PII> path;					
					while(1)
					{
						path.pb(make_pair(x,y));
						if(ans[x][y])
							break;
						int minx=x, miny=y, min=ma[minx][miny];
						REP(kk,4)
						{
						if(  ((x+dx[kk])>=0) && ((x+dx[kk])<n) && ((y+dy[kk])<m) && ((y+dy[kk])>=0)  )
							if(min>ma[x+dx[kk]][y+dy[kk]])
							{
								minx=x+dx[kk];
								miny=y+dy[kk];
								min=ma[minx][miny];
							}
						}						
						if((minx==x)&&(miny==y))
							break;
						x=minx;
						y=miny;
					}			
					int c;
					if(ans[x][y])
						c=ans[x][y];
					else
					{
						c=C;
						C++;
					}

					REP(p,path.size())
						ans[path[p].first][path[p].second] = c;
				}					
			}

		REP(i,n)
		{
			REP(j,m-1)
				cout << (char)('a'+ans[i][j]-1)<<" ";
			cout << (char)('a'+ans[i][m-1]-1) << endl;
		}
	}
	return 0;
}