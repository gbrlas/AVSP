	#include <iostream>
	#include <string>
	using namespace std;

	int main()
	{
		int cases, emptyFlag;
		string a, row, col;
		string b = "";
		string list[10];
		char arr[4][4];
		string winO[] = {"OOOO","OOOT", "OOTO", "OTOO", "TOOO"};
		string winX[] = {"XXXX","XXXT", "XXTX", "XTXX", "TXXX"};
		cin >> cases;
		getline(cin,a); //for extra space
		for(int i =1; i <= cases; i++)
		{
			b = "";
			emptyFlag = 0;
			for(int r=0;r<=3;r++)
			{
				row = "";
				getline(cin,a);
				for(int c=0;c<=3; c++)
				{
					arr[r][c] = a[c];
					if(a[c] == '.')
					emptyFlag = 1;
					
					row = row + a[c];
				}
				list[r] = row; // adding row to list
			} 
			
			for(int c=0; c<=3; c++)
			{
				col = "";
				for(int r=0;r<=3; r++)
				{
					col = col + arr[r][c];
				}
				list[4+c] = col; //addding col to list
			}
			list[8] = "";
			list[9] = "";
			for(int d=0; d<=3; d++)
			{
				list[8] = list[8] + arr[d][d]; //adding diagonal 1 to list
				list[9] = list[9] + arr[d][3-d];//adding diagonal 2 to list
			}
			
			for(int l = 0; l < 10; l++)
			{
				for(int count = 0; count <=4; count++)
				{
					if(list[l].compare(winO[count]) == 0)
					{
						b = "O won";
						break;			
					}
					if(list[l].compare(winX[count]) == 0)
					{
						b = "X won";
						break;
					}
				}
				if(b.empty() == 0)
				break;
			}

			if(b.empty() == 1)
			{	
				if(emptyFlag == 1)
				b = "Game has not completed";
				else
				b = "Draw";
			}
			cout << "Case #" << (i) << ": " << b <<"\n";	
			getline(cin,a); //for extra space
		}
		return 0;
	}