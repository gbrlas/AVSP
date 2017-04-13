#include <iostream>
#include <fstream>
#include <cstdlib>

enum
{
	SQUARE_BOARD_SIZE=4
};

using namespace std;

char* outputOneOfTheStatuses(char board[][SQUARE_BOARD_SIZE]);
int checkRowCol(char board[][SQUARE_BOARD_SIZE], int i, int j);
void main()
{
	ifstream inStream;
	ofstream outFile("output.txt");
	int numTestCases;							

	inStream.open("A-large.in");
	if(inStream.fail())
	{
		cerr<<"Input file opening failed. \n";
		exit(1);
	}
	inStream>>numTestCases;						//number of test cases
	for(int t=1;t<=numTestCases;t++)
	{
		char squareBoard[SQUARE_BOARD_SIZE][SQUARE_BOARD_SIZE];	//declaration of 4 x 4 squareboard array
		for(int i=0;i<SQUARE_BOARD_SIZE;i++)					
		{
			for(int j=0;j<SQUARE_BOARD_SIZE;j++)
			{
				inStream>>squareBoard[i][j];					//feed data into a squareboard array
			}
		}
		outFile<<"Case #"<<t<<": "<<outputOneOfTheStatuses(squareBoard)<<endl;
																//output
	}
	outFile.close();
	inStream.close();
}

char* outputOneOfTheStatuses(char board[][SQUARE_BOARD_SIZE])
{
	bool existEmpty=false;								//this variable check '.' character on a 4 x 4 square board
	for(int i=0;i<SQUARE_BOARD_SIZE;i++)
	{
		for(int j=0;j<SQUARE_BOARD_SIZE;j++)
		{
			if(board[i][j]=='.')					
				existEmpty=true;
			else										//one of the fields is filled
			{
				if(checkRowCol(board, i, j)!=0)			//check winnig condition on row and col
				{
					if(checkRowCol(board, i, j)==1)
						return "X won";
					else
						return "O won";
				}
				int dXCount=0,dOCount=0;
				if(i==j)								//check winnig condition on diagonal
				{
					for(int k=0;k<SQUARE_BOARD_SIZE;k++)
					{
						switch(board[k][k])
						{
						case 'X':
							dXCount++;
							break;
						case 'O':
							dOCount++;
							break;
						case 'T':
							dXCount++;
							dOCount++;
							break;
						}
					}
				}
				else if((i+j)==(SQUARE_BOARD_SIZE-1))	//check winnig condition on diagonal of inverse
				{
					for(int k=0;k<SQUARE_BOARD_SIZE;k++)
					{
						switch(board[k][SQUARE_BOARD_SIZE-1-k])
						{
						case 'X':
							dXCount++;
							break;
						case 'O':
							dOCount++;
							break;
						case 'T':
							dXCount++;
							dOCount++;
							break;
						}
					}
				}
				if(dXCount==4)							
						return "X won";
				else if(dOCount==4)
						return "O won";
			}
		}
	}
	if(existEmpty)
		return "Game has not completed";
	else
		return "Draw";
}
int checkRowCol(char board[][SQUARE_BOARD_SIZE], int i, int j)
{
	int rXCount=0,rOCount=0,cXCount=0,cOCount=0;
	for(int k=0;k<SQUARE_BOARD_SIZE;k++)
	{
		switch(board[i][k])
		{
		case 'X':
			rXCount++;
			break;
		case 'O':
			rOCount++;
			break;
		case 'T':
			rXCount++;
			rOCount++;
			break;
		}
		switch(board[k][j])
		{
		case 'X':
			cXCount++;
			break;
		case 'O':
			cOCount++;
			break;
		case 'T':
			cXCount++;
			cOCount++;
			break;
		}
		if((rXCount==4)||(cXCount==4))
			return 1;
		else if((rOCount==4)||(cOCount==4))
			return 2;
	}
	return 0;
}