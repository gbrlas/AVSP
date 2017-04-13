#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define VT vector
typedef VT<int> VI;
typedef VT<VI> VVI;
typedef VT<string> VS;
typedef VT<double> VD;
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define ALL(c) c.begin(),c.end()
#define PB push_back
#define MP make_pair
#define FS first
#define SC second
#define SZ size() 


using namespace std;

int d[][2] = {{-1,0}, {0,-1}, {0,1}, {1,0}};



int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int T,H,W;
	cin >>T;


	REP(t,T)
	{
		cin >>H>>W;

		VVI area(H, VI(W));
		VVI drains(H, VI(W));
		REP(h, H)
		{
			REP(w, W)
			{
				int a; cin >> a;
				area[h][w] = a;
			}
		}

		VI drainsx,drainsy;

		REP(h, H)
		{
			REP(w, W)
			{
				bool drain = true;
				REP(k, 4)
				{
					int y = h+d[k][0], x=w+d[k][1];
					if (x>=0&&x<W&&y>=0&&y<H&&area[y][x] < area[h][w])
						drain = false;
				}

				if (drain)
					drainsx.push_back(w), drainsy.push_back(h);
			}
		}

		REP(i, drainsx.size())
		{
			queue<pair<int,int> > q;
			q.push(MP(drainsy[i], drainsx[i]));

			while(!q.empty())
			{
				int w = q.front().second, h = q.front().first;
				q.pop();

				if (drains[h][w])
					continue;

				drains[h][w] = i+1;

				REP(k, 4)
				{
					int x = w+d[k][0],y=h+d[k][1];

					if (x>=0&&x<W&&y>=0&&y<H)
					{
						vector<pair<pair<int,int>,pair<int,int> > > dirs;

						REP(m, 4)
						{
							int xx = x+d[m][1], yy=y+d[m][0];

							if (xx>=0&&xx<W&&yy>=0&&yy<H && area[yy][xx] < area[y][x])
							{
								dirs.push_back(MP(MP(area[yy][xx],m),MP(yy,xx)));
							}
						}

						sort(ALL(dirs));

						if (dirs.size() && dirs[0].second.first==h &&dirs[0].second.second==w)
						{
							q.push(MP(y,x));
						}
					}
				}
			}
		}

		map<int, char> dmap;
		VVI result(H, VI(W));

		REP(h, H)
		{
			REP(w, W)
			{
				if (!result[h][w])
				{
					int d = drains[h][w];
					if (dmap.count(d) == 0)
					{
						dmap[d] = 'a'+dmap.size();
					}

					result[h][w] = dmap[d];
				}
			}
		}

		cout << "Case #" << (t+1) << ":\n";
		REP(h, H)
		{
			REP(w, W)
			{
				cout << char(result[h][w]) << " ";
			}
			cout << "\n";
		}

	}

}