#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[])
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w+", stdout);

	int T;
	cin >> T;
	for(int t=0; t < T; ++t)
	{
		int R, C;
		cin >> R;
		cin >> C;

		char grid[60][60];
	
		int nwhite = 0;
		int nblue = 0;
		for(int i=0; i < R; ++i)
		{
			for(int j=0; j < C; ++j)
			{
				cin >> grid[i][j];
				if( grid[i][j] == '.' )
					++nwhite;
				else
					++nblue;
			}
		}

		if( nblue == 0 )
		{
			cout << "Case #" << (t+1) << ":"<< endl;
			for(int i=0; i < R; ++i)
			{
				for(int j=0; j < C; ++j)
				{
					cout << grid[i][j];
				}
				if( i < R-1 )
					cout << endl;
			}
			cout << endl;
			continue;
		}

		if( nblue < 4 || (nblue % 4 != 0 ) )
		{
			cout << "Case #" <<  (t+1) << ":" << endl << "Impossible" << endl;
			continue;
		}

		bool f = false;
		for(int i=0; i < R; ++i)
		{
			for(int j=0; j < C; ++j)
			{
				if( grid[i][j] =='#' )
				{
					grid[i][j] = '/';
					if( grid[i][j+1] == '#' )
						grid[i][j+1] = '\\';
					else
					{
						f = true;
						break;
					}

					if( grid[i+1][j] == '#')
						grid[i+1][j] = '\\';
					else
					{
						f = true;
						break;
					}
					if(grid[i+1][j+1] == '#' )
					grid[i+1][j+1] = '/';
					else
					{
						f = true;
						break;
					}

				}
			}
			if( f )
				break;
		}
		if( f )
		{
			cout << "Case #" <<  (t+1) << ":" << endl << "Impossible" << endl;
			continue;
		}


		cout << "Case #" <<  (t+1) << ":" << endl;
		for(int i=0; i < R;++i)
		{
			for(int j=0; j < C; ++j)
			{
				cout << grid[i][j];
			}

			cout << endl;
		}

	}
	return 0;
}