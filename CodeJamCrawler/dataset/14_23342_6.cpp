#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
	int t,T;
	cin >> T;
	int board[4][4];
	set<int> s;
	int i,j;

	for( t = 0; t < T; t++)
	{
		int row;
		cin >> row;
		for( i = 0; i < 4; i++ )
		{
			for( j = 0; j < 4; j++ )
			{
				cin >> board[i][j];
			}
		}
		s.clear();
		for( i = 0; i < 4; i++ )
		{
			s.insert(board[row-1][i]);
		}

		cin >> row;

		for( i = 0; i < 4; i++)
		{
			for( j = 0; j < 4; j++ )
			{
				cin >> board[i][j];
			}
		}

		vector<int> result;
		result.clear();
		for( i = 0; i < 4; i++ )
		{
			if( s.find(board[row-1][i]) != s.end() )
			{
				result.push_back(board[row-1][i]);
			}
		}
		cout << "Case #" << (t+1) << ": ";
		if( result.size() == 1 )
			cout << result[0];
		else if( result.size() > 1 )
			cout << "Bad magician!";
		else
			cout << "Volunteer cheated!";
		cout << endl;
	}

	return 0;
}