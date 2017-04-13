#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct dc
{
	int i, j;
	int elev;
	struct dc * drainsTo;
	vector<struct dc *> drainsFrom;
	char basin;
};

void walkback(struct dc * asdf, char inBasin)
{
	queue<struct dc *> q;
	q.push(asdf);
	while(!q.empty())
	{
		struct dc * mp = q.front();
		q.pop();
		for(vector<struct dc *>::iterator it = mp->drainsFrom.begin(); it != mp->drainsFrom.end(); it++)
		{
			q.push(*it);
			(*it)->basin = inBasin;
		}
	}	
}
void procboard(int caseNum, int H, int W)
{
	struct dc bid[H * W];
	struct dc * brd[H][W];
	int piece = 0;
	for(int i = 0; i < H; i++) for(int j = 0; j < W; j++)
	{
		bid[piece].i = i;
		bid[piece].j = j;
		cin >> bid[piece].elev;
		bid[piece].drainsTo = NULL;
		bid[piece].basin = '\0';
		brd[i][j] = &bid[piece];
		piece++;
	}
	// determine drainage
	int directions[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
	for(int i = 0; i < H; i++) for(int j = 0; j < W; j++)
	{
		int mins = brd[i][j]->elev;
		for(int dir = 0; dir < 4; dir++)
		{
			int ii = i + directions[dir][0];
			int jj = j + directions[dir][1];
			if(ii < 0 || ii >= H || jj < 0 || jj >= W)
				continue;
			if(brd[ii][jj]->elev < mins)
			{
				brd[i][j]->drainsTo = brd[ii][jj];
				mins = brd[ii][jj]->elev;
			}
		}
		if(brd[i][j]->drainsTo != NULL)
		{
			brd[i][j]->drainsTo->drainsFrom.push_back(brd[i][j]);
		}
	}
	char inBasin = 'a';
	// assign basins
	cout << "Case #" << caseNum << ":" << endl;
	for(int i = 0; i < H; i++) for(int j = 0; j < W; j++)
	{
		if(j > 0) cout << " ";
		if(brd[i][j]->basin == '\0')
		{
			brd[i][j]->basin = inBasin;
			walkback(brd[i][j], inBasin);
			struct dc * blah = brd[i][j]->drainsTo;
			while(blah != NULL)
			{
				blah->basin = inBasin;
				walkback(blah, inBasin);
				blah = blah->drainsTo;
			}
			inBasin++;
		}
		cout << brd[i][j]->basin;
		if( j == (W - 1)) cout << endl;
	}
}

int main()
{
	int T;
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		int H, W;
		cin >> H >> W;
		//cerr << "H " << H << " W " << W << endl;
		procboard(i+1, H, W);
	}
}
