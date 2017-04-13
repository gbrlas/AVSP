#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TPoint {
	int i;
	int j;
};

const TPoint dir[4] = {{-1,0},{0,-1},{0,1},{1,0}};

bool inside (int i, int j, int h, int w)
{
	if ((i>=0)&&(i<h)&&(j>=0)&&(j<w))
		return true;
	else
		return false;
}

int main()
{
	int k;
	cin >> k;
	for (int t = 0; t<k; ++t)
	{
		int map[110][110];
		vector<TPoint> route[110][100];
		int ans[110][110];
		bool is_basin[110][110], checked[110][110];
		int h,w;
		
		cin >> h >> w;
		for (int i = 0; i<h; ++i)
			for (int j = 0; j<w; ++j)
				cin >> map[i][j];
				
		for (int i = 0; i<h; ++i)
			for (int j = 0; j<w; ++j)
			{
				TPoint f = {i,j};
				
				for (int p = 0; p<4; ++p)
				{
					if ( inside(i+dir[p].i, j+dir[p].j, h, w) )
						if (map[i+dir[p].i][j+dir[p].j] < map[f.i][f.j])
						{
							f.i = i+dir[p].i;
							f.j = j+dir[p].j;
						}
				}
				TPoint c = {i,j};
				if ((f.i == c.i)&&(f.j == c.j))
					is_basin[i][j] = true;
				else
					is_basin[i][j] = false;
				route[f.i][f.j].push_back(c);
			}
// 		for  (int i = 0; i<h; ++i)
// 			for (int j = 0; j<w; ++j)
// 			{
// 				cout << "(" << i << ", " << j << "): ";
// 
// 				for (int p = 0; p<route[i][j].size(); ++p)
// 					cout << "(" << route[i][j][p].i << ", " << route[i][j][p].j << ") ";
// 				cout << endl;
// 			}
		for  (int i = 0; i<h; ++i)
			for (int j = 0; j<w; ++j)
				checked[i][j] = false;
		int d = 0;
		for  (int i = 0; i<h; ++i)
			for (int j = 0; j<w; ++j)
				if (is_basin[i][j])
				{
					++d;
					queue<TPoint> Q;
					TPoint c = {i,j};
					Q.push(c);
					while (!Q.empty())
					{
						TPoint c = Q.front();
						Q.pop();
						
						checked[c.i][c.j] = true;
						ans[c.i][c.j] = d;
						for (int p = 0; p<route[c.i][c.j].size(); ++p)
						{
							if (!checked[route[c.i][c.j][p].i][route[c.i][c.j][p].j])
							{
								TPoint g = {route[c.i][c.j][p].i,route[c.i][c.j][p].j};
								Q.push(g);
							}
						}
					}
				}

		char symbolic[27];
		for (int c = 1; c<=27; ++c)
			symbolic[c] = '*';
		char last = 'a';
		
		cout << "Case #" << t+1 << ":" << endl;
		for (int i = 0; i<h; ++i)
		{
			for (int j = 0; j<w; ++j)
			{
				if (symbolic[ans[i][j]] == '*')
				{
					symbolic[ans[i][j]] = last;
					++last;
				}
				cout << symbolic[ans[i][j]] << " ";
				
			}
			cout << endl;
		}
	}
}
