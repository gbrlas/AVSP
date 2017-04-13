#include <fstream>
#include <string>
#include <memory>
#include <cstdlib>

using namespace std;

const int maxh = 110;
const int maxw = 110;

int map[maxh][maxw];
int par[maxh][maxw];
char lab[maxh][maxw];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int t, h, w;
ifstream fin("b.in");
ofstream fout("b.out");

int main()
{
	fin >> t;
	int cases = 0;
	while (t--)
	{
		fin >> h >> w;
		for (int i=0; i<h; i++)
			for (int j=0; j<w; j++)
				fin >> map[i][j];
		for (int i=0; i<h; i++)
			for (int j=0; j<w; j++)
			{
				par[i][j] = -1;
				int now = map[i][j];
				for (int k=0; k<4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx >= 0 && ny >= 0 && nx < h && ny < w)
					{
						if (map[nx][ny] < now)
						{
							now = map[nx][ny];
							par[i][j] = k;
						}
					}
				}
			}
		memset(lab, 0, sizeof lab);
		char cc = 'a';
		for (int i=0; i<h; i++)
			for (int j=0; j<w; j++)
				if (lab[i][j] == 0)
				{
					int x = i;
					int y = j;
					while (lab[x][y] == 0 && par[x][y] != -1)
					{
						int t = par[x][y];
						x += dx[t]; y+= dy[t];
					}
					if (lab[x][y] == 0)
					{
						x = i; y = j;
						while (par[x][y] != -1)
						{
							lab[x][y] = cc;
							int t = par[x][y];
							x += dx[t]; y+= dy[t];
						}
						lab[x][y] = cc++;
					}
					else
					{
						char nc = lab[x][y];
						x = i; y = j;
						while (lab[x][y] == 0)
						{
							lab[x][y] = nc;
							int t = par[x][y];
							x += dx[t]; y+= dy[t];
						}
					}
				}
		fout << "Case #" << ++cases << ":\n";

		for (int i=0; i<h; i++)
		{
			for (int j=0; j<w-1; j++)
				fout << lab[i][j] << ' ';
			fout << lab[i][w-1];
			fout << "\n";
		}
	}
	return 0;
}