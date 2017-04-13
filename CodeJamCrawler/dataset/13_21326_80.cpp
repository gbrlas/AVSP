#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>

using namespace std;

char buffer[1024];

bool check(char _car, vector<string>& _b)
{
	
	for(int i = 0; i < 4; ++i)
	{
		bool winLine = true;
		for(int j = 0; j < 4; ++j)
		{
			if(_b[i][j] != _car && _b[i][j] != 'T')
			{
				winLine = false;
				break;
			}
		}
		if(winLine)
			return true;
	}

	bool win = true;
	for(int i = 0; i < 4; ++i)
	{
		if(_b[i][i] != _car && _b[i][i] != 'T')
		{
			win = false;
			break;
		}
	}

	if(win)
		return true;

	win = true;
	for(int i = 0; i < 4; ++i)
	{
		if(_b[i][3-i] != _car && _b[i][3-i] != 'T')
		{
			win = false;
			break;
		}
	}

	if(win)
		return true;

	for(int j = 0; j < 4; ++j)
	{
		bool winColumn = true;
		for(int i = 0; i < 4; ++i)
		{
			if(_b[i][j] != _car && _b[i][j] != 'T')
			{
				winColumn = false;
				break;
			}
		}
		if(winColumn)
			return true;
	}

	return false;
}

int main(int argc, char* argv[])
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w+", stdout);

	memset(buffer, 0, sizeof(buffer));

	int N;
	fgets(buffer, sizeof(buffer), stdin);
	N = atoi(buffer);

	for(int T = 0; T < N; ++T)
	{
		if(T >= 1 )
			fgets(buffer, sizeof(buffer), stdin);

		vector<string> b;
		for(int i = 0; i < 4; ++i)
		{
			fgets(buffer, sizeof(buffer), stdin);
			b.push_back(buffer);
		}

		if(check('X', b))
		{
			cout << "Case #" << (T+1) << ": " << "X won" << endl;
			continue;
		}

		if(check('O', b))
		{
			cout << "Case #" << (T+1) << ": " << "O won" << endl;
			continue;
		}


		//DRaw?
		bool isDraw = true;
		for(int i = 0; i < 4; ++i)
		{
			for(int j = 0; j < 4; ++j)
			{
				if(b[i][j] == '.')
				{
					isDraw = false;
					break;
				}
			}
			if(!isDraw)
				break;
		}

		if(isDraw)
		{
			cout << "Case #" << (T+1) << ": " << "Draw" << endl;
		}
		else
		{
			cout << "Case #" << (T+1) << ": " << "Game has not completed" << endl;
		}

	}

	return 0;
}