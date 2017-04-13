#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

bool checkDir(int a, int b, int dira, int dirb, char grid[][5])
{
	char c1=grid[a][b],c2=grid[a+dira][b+dirb],c3=grid[a+2*dira][b+2*dirb],c4=grid[a+3*dira][b+3*dirb];
	if (c1==c2 && c2==c3 && c3==c4)
		return true;
	else
		return false;
}

int main()
{
	ofstream cout ("ASmall.out");
	ifstream cin ("ASmall.in");

	int t;
	cin>>t;

	for (int i=1; i<=t; i++)
	{
		bool isEmpty=false;

		cout<<"Case #"<<i<<": ";
		char result='D';	//D->Draw
		
		int Tposa=9, Tposb=9;
		char grid[5][5];
		char player;

		for (int a=1;a<=4;a++)
		{
			for (int b=1;b<=4;b++)
			{
				cin>>grid[a][b];
				if (grid[a][b]=='T')
				{
					Tposa=a;
					Tposb=b;
				}
				if (grid[a][b]=='.')
					isEmpty=true;
			}
		}

		//T=X, Check for player X win
		if (Tposa!=9 && Tposb!=9)
			grid[Tposa][Tposb]='X';

		//check vertical
		for (int b=1;b<=4;b++)
		{
			player = grid[1][b];
			if (checkDir(1,b,1,0,grid) && player!='.')
				result=player;
		}

		//check horizontal
		for (int a=1;a<=4;a++)
		{
			player = grid[a][1];
			if (checkDir(a,1,0,1,grid) && player!='.')
				result=player;
		}

		//check first diagonal
		player = grid[1][1];
		if (checkDir(1,1,1,1,grid) && player!='.')
			result=player;

		//check second diagonal
		player = grid[1][4];
		if (checkDir(1,4,1,-1,grid) && player!='.')
			result=player;

		if (result=='X')
		{
			cout<<"X won"<<endl;
			continue;
		}

		//T=O
		if (Tposa!=9 && Tposb!=9)
			grid[Tposa][Tposb]='O';

		//check vertical
		for (int b=1;b<=4;b++)
		{
			player = grid[1][b];
			if (checkDir(1,b,1,0,grid) && player!='.')
				result=player;
		}

		//check horizontal
		for (int a=1;a<=4;a++)
		{
			player = grid[a][1];
			if (checkDir(a,1,0,1,grid) && player!='.')
				result=player;
		}

		//check first diagonal
		player = grid[1][1];
		if (checkDir(1,1,1,1,grid) && player!='.')
			result=player;

		//check second diagonal
		player = grid[1][4];
		if (checkDir(1,4,1,-1,grid) && player!='.')
			result=player;

		if (result=='O')
		{
			cout<<"O won"<<endl;
			continue;
		}

		if (result!='X' && result!='O' && isEmpty)
			cout<<"Game has not completed"<<endl;
		else
			cout<<"Draw"<<endl;
	}
	return 0;
}
		//for (int a=1;a<=1;a++)
		//{
		//	for (int b=1; b<=4; b++)
		//	{
		//		char player=grid[a][b];
		//		if (checkDir(a,b,1,1,grid) || checkDir(a,b,1,0,grid) || checkDir(a,b,0,1,grid))
		//		{
		//			result=player;
		//			continue;
		//		}
		//	}
		//}