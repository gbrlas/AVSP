#include <iostream>
#include <vector>
using namespace std;

bool ok(vector<string>& view, int x, int y)
{
	int dx[] = {0, 1, 1, 0}, dy[] = {0, 0, 1, 1};
	for(int i = 0; i < 4; i++)
	{
		int X = x + dx[i], Y = y + dy[i];
		if(X >= view.size() || Y >= view[X].size())
			return false;
		if(view[X][Y] != '#')
			return false;
		view[X][Y] = i%2 ? '\\' : '/';
	}
	return true;
}

int main()
{
	int T; cin >> T;
	for(int No = 1; No <= T; No++)
	{
		int R, C; cin >> R >> C;
		vector<string> view(R);
		for(int i = 0; i < R; i++)
			cin >> view[i];
		
		bool ans = true;
		for(int i = 0; i < R; i++)
			for(int j = 0; j < C; j++)
				if(view[i][j] == '#' && !ok(view, i, j))
						ans = false;
		
		cout << "Case #" << No << ":" << endl;
		if(ans)
		{
			for(int i = 0; i < R; i++)
				cout << view[i] << endl;
		}
		else
		{
			cout << "Impossible" << endl;
		}
	}
	return 0;
}
