#include <iostream>
#include <fstream>

using namespace std;

int map[10002][102];
char charMap[10002][102];
bool visited[10002][102];

char visit(int& i, int r, int c)
{
	if (visited[r][c])
		return charMap[r][c];
	visited[r][c] = true;
	int sinkR, sinkC;
	int curr = map[r][c];
	if(map[r-1][c] < curr && map[r-1][c] != -1)
	{
		sinkR = r-1; sinkC = c;
		curr = map[r-1][c];
	}
	if(map[r][c-1] < curr && map[r][c-1] != -1)
	{
		sinkR = r; sinkC = c-1;
		curr = map[r][c-1];
	}
	if(map[r][c+1] < curr && map[r][c+1] != -1)
	{
		sinkR = r; sinkC = c+1;
		curr = map[r][c+1];
	}
	if(map[r+1][c] < curr && map[r+1][c] != -1)
	{
		sinkR = r+1; sinkC = c;
		curr = map[r+1][c];
	}

	if(curr == map[r][c])
	{
		if (charMap[r][c] == 0)
			charMap[r][c] = char(i++);
	}
	else
		charMap[r][c] = visit(i, sinkR, sinkC);

	return charMap[r][c];
}
void solve(int H, int W)
{
	int i = 'a';
	for (int r = 1; r <= H; r++)
		for (int c = 1; c <= W; c++)
			if(!visited[r][c])
				visit(i, r, c);
}
int main()
{
	ifstream cin("B-large.in");
	ofstream cout("3.txt");
	int T, H, W;
	cin >> T;

	for (int i = 1; i <= T; i++)
	{
		cin >> H >> W;
		memset(map, -1, sizeof(map));
		for (int r = 1; r <= H; r++)
			for (int c = 1; c <= W; c++)
				cin >> map[r][c];
		memset(charMap, 0, sizeof(charMap));
		memset(visited, 0, sizeof(visited));
		solve(H, W);
		cout << "Case #" << i << ":" << endl;
		for (int r = 1; r <= H; r++)
		{
			for (int c = 1; c <= W; c++)
				cout << charMap[r][c] << ' ';
			cout << endl;
		}
	}
	return 0;
}