#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

const int Dx[4] = {-1, -1, 1, 1};
const int Dy[4] = {-1, 1, 1, -1};

const int maxr = 12 + 5;
const int maxn = 5 + 2;
const int maxt = 100000;

map< vector< pair<int, int> >, int > f;
vector< pair<int, int> > q[maxt];
char a[maxr][maxr];
int r, c, n;

bool check(vector< pair<int, int> > cur, char b[maxr][maxr])
{
	for (int i = 0; i < n; ++i)
	{
		bool edge = 0;
		for (int j = 0; j < 4; ++j)
		{
			int x = cur[i].first + dx[j], y = cur[i].second + dy[j];
			if (x >= 0 && x < r && y >= 0 && y < c && b[x][y] == 'o')
			{
				edge = 1;
				break;
			}
		}
		if (!edge) return 1;
	}
	return 0;
}

void BFS(vector< pair<int, int> > S, vector< pair<int, int> > T)
{
	f.clear();
	q[0] = S; f[S] = 0;
	for (int h = 0, t = 1; h < t; ++h)
	{
		vector< pair<int, int> > cur = q[h];
		int step = f[cur];
		if (cur == T)
		{
			printf("%d\n", step);
			return;
		}

//		for (int i = 0; i < n; ++i) printf("(%d,%d) ", cur[i].first, cur[i].second); printf("\n");
		char b[maxr][maxr];
		memcpy(b, a, sizeof(a));
		for (int i = 0; i < n; ++i) b[cur[i].first][cur[i].second] = 'o';

//		for (int i = 0; i < r; ++i) printf("%s\n", b[i]);

		bool danger = check(cur, b);

//		printf("%d\n", danger);

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < 4; ++j)
			{
				int x = cur[i].first + dx[j], y = cur[i].second + dy[j];
				if (x < 0 || x >= r || y < 0 || y >= c || b[x][y] != '.') continue;
				int ox = cur[i].first - dx[j], oy = cur[i].second - dy[j];
				if (ox < 0 || ox >= r || oy < 0 || oy >= c || b[ox][oy] != '.') continue;
//				printf("%d %d %d %d\n", cur[i].first, cur[i].second, ox, oy);
				swap(b[cur[i].first][cur[i].second], b[ox][oy]);
				bool flag = 1, state = 0;
				for (int k = 0; k < n; ++k)
				{
					bool edge = 0;
					for (int l = 0; l < 4; ++l)
					{
						int x = cur[k].first + dx[l], y = cur[k].second + dy[l];
						if (x >= 0 && x < r && y >= 0 && y < c && b[x][y] == 'o')
						{
							edge = 1;
							break;
						}
					}
					if (!edge)
					{
						for (int l = 0; l < 4; ++l)
						{
							int x = cur[k].first + Dx[l], y = cur[k].second + Dy[l];
							if (x >= 0 && x < r && y >= 0 && y < c && b[x][y] == 'o')
							{
								edge = 1;
								break;
							}
						}
						if (!edge)
						{
							flag = 0;
							break;
						}
						else state = 1;
					}
				}

				if (flag && (!danger && state || !state))
				{
					vector< pair<int, int> > tmp;
					tmp.clear();
					for (int k = 0; k < n; ++k)
						if (k != i) tmp.push_back( cur[k] );
						else tmp.push_back( make_pair(ox, oy) );

					sort(tmp.begin(), tmp.end());
					if (f.find(tmp) == f.end())
					{
						f[tmp] = step + 1;
						q[t++] = tmp;
					}
				}
				swap(b[cur[i].first][cur[i].second], b[ox][oy]);
			}
	}

	printf("-1\n");
}

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int tst = 1; tst <= T; ++tst)
	{
		vector< pair<int, int> > S, T;
		S.clear(); T.clear();

		scanf("%d%d", &r, &c);
		for (int i = 0; i < r; ++i)
		{
			scanf("%s", a[i]);
			for (int j = 0; j < c; ++j)
				if (a[i][j] == 'o') a[i][j] = '.', S.push_back( make_pair(i, j) );
				else
					if (a[i][j] == 'x') a[i][j] = '.', T.push_back( make_pair(i, j) );
					else
						if (a[i][j] == 'w') a[i][j] = '.', S.push_back( make_pair(i, j) ), T.push_back( make_pair(i, j) );
		}

		n = S.size();
		sort(S.begin(), S.end());
		sort(T.begin(), T.end());

		printf("Case #%d: ", tst);
		BFS(S, T);
	}

	return 0;
}
