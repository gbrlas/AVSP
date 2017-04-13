#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int H, W;
char letter[110][110];
int g[110][110];

bool Sink(int i , int j)
{
	return (!i || g[i-1][j] >= g[i][j]) &&(!j || g[i][j-1] >= g[i][j])
		&& (i == H-1 || g[i+1][j] >= g[i][j])&& (j == W-1 || g[i][j+1] >= g[i][j]);
}
//# Otherwise, water flows from the current cell to the neighbor with the lowest altitude.
//# In case of a tie, water will choose the first direction with the lowest altitude from this list: North, West, East, South.
char trace(int i, int j)
{
	if(letter[i][j] != -1)
		return letter[i][j];

	int nI, nJ, best = INT_MAX/2;
	//south
	if(i != H-1 && g[i+1][j] <= best) best = g[i+1][j], nI = i+1, nJ = j;
	//east
	if(j != W-1 && g[i][j+1] <= best) best = g[i][j+1], nI = i, nJ = j+1;
	//west
	if(j && g[i][j-1] <= best) best = g[i][j-1], nI = i, nJ = j-1;
	//north
	if(i && g[i-1][j] <= best) best = g[i-1][j], nI = i-1, nJ = j;

	return letter[i][j] = trace(nI, nJ);
}
int sinks[30];
int main()
{
	ifstream cin("Bs.in");
	ofstream cout("res.txt");
	int t;
	cin >> t;

	for(int x = 1; x <= t; x++)
	{
		memset(letter, -1 , sizeof(letter));
		memset(sinks, -1, sizeof(sinks));

		cin >> H >> W;

		for(int  i = 0; i < H; i++)
			for(int j = 0; j < W; j++)
				cin >> g[i][j];

		char let = 0;

		for(int  i = 0; i < H; i++)
			for(int j = 0; j < W; j++)
				if( Sink(i,j)) letter[i][j] = let++;

		for(int  i = 0; i < H; i++)
			for(int j = 0; j < W; j++)
				if(letter[i][j] == -1)letter[i][j] = trace(i,j);

		char newLet = 'a';

		cout << "Case #" <<x<< ":" << endl;
		for(int  i = 0; i < H; i++)
		{
			for(int j = 0; j < W; j++)
			{
				if(j) cout << " ";
				if(letter[i][j] < 30)
				{
					if(sinks[letter[i][j]] == -1) sinks[letter[i][j]] = newLet++;
					letter[i][j] = sinks[letter[i][j]];
				}
				cout << letter[i][j];
			}
			cout << endl;
		}

		

	}
	cout.close();
	return 0;
}