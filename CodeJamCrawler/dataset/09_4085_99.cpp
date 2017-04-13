#include <string>
#include <vector>
#include <map>
#include <fstream>

using namespace std;
#define rep(i,n) for(int i=0,_n=(n);i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)

const int infty = 1 << 29;
//North, West, East, South.
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void Fill(int i, int j, int r, const vector<vector<int> >& grid, vector<vector<int> >& v)
{
	const int n = grid.size();
	const int m = grid[0].size();
	v[i][j] = r;
	rep(d, 4)
	{
		int x = dx[d] + i;
		int y = dy[d] + j;
		if (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] > grid[i][j] && v[x][y] == 0)
		{
			int minS = grid[i][j] + 1, bestI = 0, bestJ = 0;
			rep(k, 4)
			{
				int xx = dx[k] + x;
				int yy = dy[k] + y;
				if (xx >= 0 && yy >= 0 && xx < n && yy < m && v[x][y] ==0 && grid[xx][yy] < minS)
				{
					minS = grid[xx][yy];
					bestI = xx;
					bestJ = yy;
				}
			}
			if (bestI == i && bestJ == j)
				Fill(x, y, r, grid, v);
		}
	}
}

int main()
{
	ifstream cin("B-small-attempt0.in");
	ofstream cout("B-small.out");

	int t, n, m;
	cin >> t;
	rep(ii, t)
	{
		cin >> n >> m;
		vector<vector<int> > grid(n, vector<int>(m, 0));
		vector<vector<int> > v(n, vector<int>(m, 0));
		rep(i, n) rep(j, m) cin >> grid[i][j];

		int region = 0;
		while (true)
		{
			++ region;
			int minVal = infty, minI = -1, minJ = -1;

			rep(i, n) rep(j, m)
				if (v[i][j] == 0 && grid[i][j] < minVal)
				{
					minVal = grid[i][j];
					minI = i;
					minJ = j;
				}
			if (minI == -1)
			{
				break;
			}

			Fill(minI, minJ, region, grid, v);
		}
		map<int, char> M;
		cout << "Case #" << (ii + 1) << ":\n";
		char curChar = 'a';
		rep(i, n)
		{
			rep(j, m)
			{
				char& ch = M[v[i][j]];
				if (ch == 0)
					ch = curChar ++;
				cout << ch <<' ';
			}
			cout << '\n';
		}
	}

	return 0;
}