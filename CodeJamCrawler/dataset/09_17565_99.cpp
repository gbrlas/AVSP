//union-find: rank, path compression.

#include <iostream>
#include <vector>
using namespace std;

int T, H, W;
int alt[102][102];

pair <int, int> comp[102][102];
int rank[102][102];
int ans[102][102];

void initialize()
{
	int i, j;
	for(i = 0; i <= H+1; i++)
		for(j = 0; j <= W+1; j++)
		{
			comp[i][j] = make_pair(i, j);
			ans[i][j] = -1;
			rank[i][j] = 1;
		}
	for(i = 0; i <= H+1; i++)
	{
		alt[i][0] = 10000;
		alt[i][W+1] = 10000;
	}
	for(i = 0; i <= W+1; i++)
	{
		alt[0][i] = 10000;
		alt[H+1][i] = 10000;
	}
}

void input()
{
	scanf("%d%d", &H, &W);
	int i, j, x;
	for(i = 1; i <= H; i++)
		for(j = 1; j <= W; j++)
		{
			scanf("%d", &x);
			alt[i][j] = x;
		}
}

pair <int, int> findcomp(pair<int, int> x)
{
	if(comp[x.first][x.second] == x)
		return x;
	comp[x.first][x.second] = findcomp(comp[x.first][x.second]);
	return comp[x.first][x.second];
}

void merge(pair <int, int> x, pair <int, int> y)
{
	comp[x.first][x.second] = findcomp(y);
}

void components()
{
	int i, j;
	int mini, minj;
	
	for(i = 1; i <= H; i++)
	{
		for(j = 1; j <= W; j++)
		{
			mini = i;
			minj = j;
			if(alt[i-1][j] < alt[mini][minj])
			{
				mini = i-1;
				minj = j;
			}
			if(alt[i][j-1] < alt[mini][minj])
			{
				mini = i;
				minj = j-1;
			}
			if(alt[i][j+1] < alt[mini][minj])
			{
				mini = i;
				minj = j+1;
			}
			if(alt[i+1][j] < alt[mini][minj])
			{
				mini = i+1;
				minj = j;
			}
			merge(make_pair(i, j), make_pair(mini, minj));
			/*if(i == 3)
			{
				cout << "J = " << j << ":  mini = " << mini << "   minj = " << minj << endl;
				cout << "comp[i][j] = " << comp[i][j].first << ", " << comp[i][j].second << endl;
				cout << "comp[mini][minj] = " << comp[mini][minj].first << ", " << comp[mini][minj].second << endl;
			}*/
			
		}
	}
	
	int done = 0;
	pair <int, int> cmp;
	
	for(i = 1; i <= H; i++)
		for(j = 1; j <= W; j++)
		{
			cmp = findcomp(make_pair(i, j));
			//cout << "i = " << i << " j = " << j << " comp = " << cmp.first << ", " << cmp.second << endl;
			if(ans[cmp.first][cmp.second] == -1)
			{
				
				ans[cmp.first][cmp.second] = done;
				ans[i][j] = done;
				done++;
			}
			else
				ans[i][j] = ans[cmp.first][cmp.second];
		}
	/*for(i = 1; i <= H; i++)
	{
		for(j = 1; j <= W; j++)
			cout << ans[i][j] << " ";
		cout << endl;
	}*/
}

void output()
{
	for(int i = 1; i <= H; i++)
	{
		for(int j = 1; j<= W; j++)
		{
			cout << ((char)(97+ans[i][j])) << " ";
		}
		cout << endl;
	}
}

int main()
{
	cin >> T;
	int abc;
	for(abc = 1; abc <= T; abc++)
	{
	
		input();
		initialize();
		components();
		cout << "Case #" << abc << ": " << endl;
		output();
	}
}
