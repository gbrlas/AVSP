#include <iostream>
#include <sstream>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

typedef pair<int, int> T;
int h, w, n;
int g[128][128];
int a[128][128];
char c[128][128];
queue<T> q;

int main()
{
#ifndef DEBUG
	freopen("B-large.in", "rt", stdin);
	freopen("B-large.out", "wt", stdout);
#endif
	cin >> n;
	for(int t = 1; t <= n; t++)
	{
		cin >> h >> w;
		for(int i = 0; i < h; i++)
			for(int j = 0; j < w; j++)
			{
				cin >> a[i][j];
				g[i][j] = 0;
				c[i][j] = 0;
			}
		for(int i = 0; i < h; i++)
			for(int j = 0; j < w; j++)
			{
				int d = a[i][j];
				if(i > 0 && a[i - 1][j] < a[i][j] && a[i - 1][j] < d)
				{
					g[i][j] = 1;
					d = a[i - 1][j];
				}
				if(j > 0 && a[i][j - 1] < a[i][j] && a[i][j - 1] < d)
				{
					g[i][j] = 2;
					d = a[i][j - 1];
				}
				if(j < w - 1 && a[i][j + 1] < a[i][j] && a[i][j + 1] < d)
				{
					g[i][j] = 3;
					d = a[i][j + 1];
				}
				if(i < h - 1 && a[i + 1][j] < a[i][j] && a[i + 1][j] < d)
				{
					g[i][j] = 4;
					d = a[i + 1][j];
				}
			}
		char tc = 'a';
		for(int i = 0; i < h; i++)
			for(int j = 0; j < w; j++)
				if(c[i][j] == 0)
				{
					q.push(T(i, j));
					c[i][j] = tc;
					while(!q.empty())
					{
						T p = q.front();
						q.pop();
						switch(g[p.first][p.second])
						{
						case 1:
							if(c[p.first - 1][p.second] == 0)
							{
								q.push(T(p.first - 1, p.second));
								c[p.first - 1][p.second] = tc;
							}
							break;
						case 2:
							if(c[p.first][p.second - 1] == 0)
							{
								q.push(T(p.first, p.second - 1));
								c[p.first][p.second - 1] = tc;
							}
							break;
						case 3:
							if(c[p.first][p.second + 1] == 0)
							{
								q.push(T(p.first, p.second + 1));
								c[p.first][p.second + 1] = tc;
							}
							break;
						case 4:
							if(c[p.first + 1][p.second] == 0)
							{
								q.push(T(p.first + 1, p.second));
								c[p.first + 1][p.second] = tc;
							}
							break;
						}
						if(p.first > 0 && c[p.first - 1][p.second] == 0 && g[p.first - 1][p.second] == 4)
						{
							q.push(T(p.first - 1, p.second));
							c[p.first - 1][p.second] = tc;
						}
						if(p.first < h - 1 && c[p.first + 1][p.second] == 0 && g[p.first + 1][p.second] == 1)
						{
							q.push(T(p.first + 1, p.second));
							c[p.first + 1][p.second] = tc;
						}
						if(p.second > 0 && c[p.first][p.second - 1] == 0 && g[p.first][p.second - 1] == 3)
						{
							q.push(T(p.first, p.second - 1));
							c[p.first][p.second - 1] = tc;
						}
						if(p.second < w - 1 && c[p.first][p.second + 1] == 0 && g[p.first][p.second + 1] == 2)
						{
							q.push(T(p.first, p.second + 1));
							c[p.first][p.second + 1] = tc;
						}
					}
					tc++;
				}
		cout << "Case #" << t << ":" << endl;
		for(int i = 0; i < h; i++)
		{
			for(int j = 0; j < w; j++)
			{
				if(j > 0)
					cout << ' ';
				cout << c[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}