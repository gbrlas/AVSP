#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

const int size = 4;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int cases;
	char board[size][size];
	bool Xwon, Owon;

	cin >> cases;

	for (int t = 1; t <= cases; t++)
	{
		getchar();
		Xwon = false; Owon = false;
		int spaces = 0;

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				board[i][j] = getchar();
			}

			getchar();
		}

		for (int i = 0; i < size; i++)
		{	
			int x_num = 0, o_num = 0;

			for (int j = 0; j < size; j++)
			{
				switch (board[i][j])
				{
				case 'X':
					x_num++;
					break;
				case 'O':
					o_num++;
					break;
				case 'T':
					x_num++;
					o_num++;
					break;
				case '.':
					spaces++;
					break;
				}
			}

			if (x_num == 4)
			{
				Xwon = true;
				break;
			}
			else if (o_num == 4)
			{
				Owon = true;
				break;
			}
		}
		if (!Xwon && !Owon)
		{
			for (int i = 0; i < size; i++)
			{
				int x_num = 0, o_num = 0;

				for (int j = 0; j < size; j++)
				{
					switch (board[j][i])
					{
					case 'X':
						x_num++;
						break;
					case 'O':
						o_num++;
						break;
					case 'T':
						x_num++;
						o_num++;
						break;
					}
				}

				if (x_num == 4)
				{
					Xwon = true;
					break;
				}
				else if (o_num == 4)
				{
					Owon = true;
					break;
				}
			}
		}

		if (!Xwon && !Owon)
		{
			int x_num = 0, o_num = 0;

			for (int i = 0; i < size; i++)
			{
				switch (board[i][i])
				{
				case 'X':
					x_num++;
					break;
				case 'O':
					o_num++;
					break;
				case 'T':
					x_num++;
					o_num++;
					break;
				}
			}

			if (x_num == 4)
			{
				Xwon = true;
			}
			else if (o_num == 4)
			{
				Owon = true;
			}
		}

		if (!Xwon && !Owon)
		{
			int x_num = 0, o_num = 0;
			int j = 3;

			for (int i = 0; i < size; i++)
			{
				switch (board[i][j--])
				{
				case 'X':
					x_num++;
					break;
				case 'O':
					o_num++;
					break;
				case 'T':
					x_num++;
					o_num++;
					break;
				}
			}

			if (x_num == 4)
			{
				Xwon = true;
			}
			else if (o_num == 4)
			{
				Owon = true;
			}
		}

		cout << "Case #" << t << ": ";

		if (Xwon)
			cout << "X won" << endl;
		else if (Owon)
			cout << "O won" << endl;
		else if (spaces > 0)
			cout << "Game has not completed" << endl;
		else
			cout << "Draw" << endl;
	}
}