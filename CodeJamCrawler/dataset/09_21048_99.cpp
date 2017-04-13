#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;

int r, c;

int d[200][200];
int label[200][200];
char cols[200][200];

int di[4] = {-1, 0, 0, 1};
int dj[4] = {0, -1, 1, 0};

bool next(int i, int j, int& I, int &J)
{
	int md = d[i][j];
	for (int k = 0; k < 4; k++)
	{
		int ii = i + di[k];
		int jj = j + dj[k];
		if (ii >= 0 && ii < r && jj >= 0 && jj < c)
		{
			if (d[ii][jj] < md)
			{
				I = ii;
				J = jj;
				md = d[I][J];
			}
		}
	}
	return (md != d[i][j]);

}

void run_label()
{
	memset(label, 0, sizeof(label));
	int cl = 1;
	for (int i0 = 0; i0 < r; i0++)
		for (int j0 = 0; j0 < c; j0++)
		{
			int i = i0;
			int j = j0;
			if (label[i][j] == 0)
			{
				label[i][j] = cl;
				int I, J;
				while (next(i, j, I, J))
				{
					if (label[I][J] == 0)
					{
						label[I][J] = cl;
					}
					else if (label[I][J] != cl)
					{
						int old_label = label[I][J];
						queue<pair<int, int> > rq;
						rq.push(make_pair(I, J));
						label[I][J] = cl;
						while (!rq.empty())
						{
							pair<int, int> t = rq.front();
							rq.pop();
							for (int k = 0; k < 4; k++)
							{
								int ii = t.first + di[k];
								int jj = t.second + dj[k];
								if (ii >= 0 && ii < r && jj >= 0 && jj < c)
								{
									if (label[ii][jj] == old_label)
									{
										label[ii][jj] = cl;
										rq.push(make_pair(ii, jj));
									}
								}
							}
						}
					}
					i = I;
					j = J;
				}
				cl++;
			}
		}
}

void run_colors()
{
	char colour = 'a';
	map<int, char> m;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
		{
			if (m.find(label[i][j]) == m.end())
			{
				m[label[i][j]] = colour++;
			}
			cols[i][j] = m[label[i][j]];
		}
}

int main()
{
	int tc, t = 0;
	for (cin >> tc; t < tc; t++)
	{
		cin >> r >> c;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				cin >> d[i][j];
		run_label();
		run_colors();
		cout << "Case #" << t + 1 << ":" << endl;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (j) cout << " ";
				cout << cols[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}