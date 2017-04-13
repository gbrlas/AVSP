#include<iostream>

using namespace std;

int main()
{
	char matrix[4][4];

	int N;

	cin >> N;
	for(int test = 1; test <= N; test++)
	{

		for(int i = 0;i < 4;i++)
			for(int j = 0; j < 4;j++)
				cin >> matrix[i][j];

		int horXwinCount = 0, verXwinCount = 0, LdiagXwinCount = 0, RdiagXwinCount = 0,
			horOwinCount = 0, verOwinCount = 0, LdiagOwinCount = 0, RdiagOwinCount = 0;

		bool incomplete = false, XWins = false, OWins = false;


		cout << "Case #" << test << ": ";

		for(int i = 0; i < 4; i++)
		{

			horXwinCount = verXwinCount = horOwinCount = verOwinCount = 0;
			
			for(int j = 0; j < 4; j++)
			{
				if( matrix[i][j] == 'X' || matrix[i][j] == 'T' ) horXwinCount++;
				if( matrix[j][i] == 'X' || matrix[j][i] == 'T' ) verXwinCount++;

				if( matrix[i][j] == 'O' || matrix[i][j] == 'T' ) horOwinCount++;
				if( matrix[j][i] == 'O' || matrix[j][i] == 'T' ) verOwinCount++;

				if( i == j && ( matrix[i][j] == 'X' || matrix[i][j] == 'T' )) LdiagXwinCount++;
				if( i == j && ( matrix[i][j] == 'O' || matrix[i][j] == 'T' )) LdiagOwinCount++;


				if( (i+j) == 3 && ( matrix[i][j] == 'X' || matrix[i][j] == 'T' )) RdiagXwinCount++;
				if( (i+j) == 3 && ( matrix[i][j] == 'O' || matrix[i][j] == 'T' )) RdiagOwinCount++;

				if(matrix[i][j] == '.')incomplete = true;
			}

			if(horXwinCount == 4 || verXwinCount == 4 || LdiagXwinCount == 4 || RdiagXwinCount == 4) 
			{ XWins = true;  break; }
			else if(horOwinCount == 4 || verOwinCount == 4 || LdiagOwinCount == 4 || RdiagOwinCount == 4) 
			{ OWins = true; break; }
			
		}

		
			if(XWins) cout << "X won" << "\n";
			else if(OWins) cout << "O won" << "\n";
			else if(incomplete) cout << "Game has not completed" << "\n";
			else  cout << "Draw" << "\n";


	}

return 0;

}