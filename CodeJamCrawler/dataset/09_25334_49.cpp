#include <fstream>
#include <algorithm>
#include <string>
#include <memory>

using namespace std;

int price[200][100];
bool g[200][200];
int px[200], py[200];
bool visited[200];
int n, k;
int T;

ifstream fin("r2c.in");
ofstream fout("r2c.out");

bool findpath(int x)
{
	if (visited[x]) return false;
	visited[x] = true;
	for (int i=0; i<n; i++)
		if (g[x][i])
		{
			if (py[i] < 0)
			{
				py[i] = x;
				px[x] = i;
				return true;
			}
			else
			{
				if (!visited[py[i]])
				{
					if (findpath(py[i]))
					{
						py[i] = x;
						px[x] = i;
						return true;
					}
				}
			}
		}
	return false;
}

int main()
{
	fin >> T;
	int cases = 0;
	while (T--)
	{
		fin >> n >> k;
		for (int i=0; i<n; i++)
			for (int j=0; j<k; j++)
				fin >> price[i][j];
		memset(g, 0, sizeof g);
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
			{
				bool larger = true;
				for (int t=0; t<k; t++)
					if (price[i][t] <= price[j][t])
					{
						larger = false;
						break;
					}
				if (larger) g[i][j] = true;
			}

		memset(px, -1, sizeof px);
		memset(py, -1, sizeof py);
		int ans = 0;
		for (int i=0; i<n; i++)
		{
			memset(visited, 0, sizeof visited);
			if (findpath(i)) ans++;
		}
		ans = n - ans;
		fout << "Case #" << ++cases << ": " << ans << endl;
	}
	return 0;
}