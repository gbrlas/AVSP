// Tic-Tac-Toe-Tomek.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	freopen("C:/Users/wangxun/Desktop/google code jam/A-small-attempt2.in", "r", stdin);
    freopen("C:/Users/wangxun/Desktop/google code jam/A-small-attempt2.out", "w", stdout);
	char board[4][4];
	int caseNo;
	int flag=1,spe=0;
	string s1 = "X won";
	string s2 = "O won";
	string s3 = "Draw";
	string s4 = "Game has not completed";
	//输入测试数据个数
	cin>>caseNo;
	for(int cno = 0;cno < caseNo;cno++)
	{
		for(int ii = 0;ii < 4;ii++)
			for(int jj = 0;jj < 4;jj++)
				cin>>board[ii][jj];
		//对每个测试数据进行判断并输出结果
		for(int i = 0; i < 4; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				if(board[i][j] == '.')
					flag = 1;
				//else flag = 0;
				spe = 0;
				if((board[i][j] =='X'&& board[i][(j+1)%4] =='X'&& board[i][(j+2)%4] =='X'&&board[i][(j+3)%4] =='X')
					||(board[i][j] =='X'&& board[(i+1)%4][j] =='X'&& board[(i+2)%4][j] =='X'&&board[(i+3)%4][j] =='X')
					||(board[0][0] =='X'&& board[1][1] =='X'&& board[2][2] =='X'&&board[3][3] =='X')
					||(board[0][3] =='X'&& board[1][2] =='X'&& board[2][1] =='X'&&board[3][0] =='X'))
					{
						cout<<"Case #"<<cno+1<<": "<<s1<<endl;
						flag = 0;
						spe = 1;
						break;
				 }
				else if((board[i][j] =='O'&& board[i][(j+1)%4] =='O'&& board[i][(j+2)%4] =='O'&&board[i][(j+3)%4] =='O')
					||(board[i][j] =='O'&& board[(i+1)%4][j] =='O'&& board[(i+2)%4][j] =='O'&&board[(i+3)%4][j] =='O')
					||(board[0][0] =='O'&& board[1][1] =='O'&& board[2][2] =='O'&&board[3][3] =='O')
					||(board[0][3] =='O'&& board[1][2] =='O'&& board[2][1] =='O'&&board[3][0] =='O'))
					{
						cout<<"Case #"<<cno+1<<": "<<s2<<endl;
						flag = 0;
						spe = 1;
						break;	
					 }
				if(board[i][j] == 'T')
					{
						if(i == j)
						{
							if(board[(i+1)%4][(j+1)%4] =='O'&& board[(i+2)%4][(j+2)%4] =='O'&& board[(i+3)%4][(j+3)%4] =='O')
								{
									cout<<"Case #"<<cno+1<<": "<<s2<<endl;
									flag = 0;
									spe = 1;
									break;	
								 }
							if(board[(i+1)%4][(j+1)%4] =='X'&& board[(i+2)%4][(j+2)%4] =='X'&& board[(i+3)%4][(j+3)%4] =='X')
								{
									cout<<"Case #"<<cno+1<<": "<<s1<<endl;
									flag = 0;
									spe = 1;
									break;	
								 }
						}
						if(i+j == 3)
						{
							if(board[(i+3)%4][(j+1)%4] =='O'&& board[(i+2)%4][(j+2)%4] =='O'&& board[(i+1)%4][(j+3)%4] =='O')
								{
									cout<<"Case #"<<cno+1<<": "<<s2<<endl;
									flag = 0;
									spe = 1;
									break;	
								 }
							if(board[(i+3)%4][(j+1)%4] =='X'&& board[(i+2)%4][(j+2)%4] =='X'&& board[(i+1)%4][(j+3)%4] =='X')
								{
									cout<<"Case #"<<cno+1<<": "<<s1<<endl;
									flag = 0;
									spe = 1;
									break;	
								 }
						}
						if((board[i][(j+1)%4] == 'X' && board[i][(j+2)%4] == 'X' && board[i][(j+3)%4] == 'X')
							||(board[(i+1)%4][j] == 'X' && board[(i+2)%4][j] == 'X' && board[(i+3)%4][j] == 'X'))
						{
							cout<<"Case #"<<cno+1<<": "<<s1<<endl;
							flag = 0;
							spe = 1;
							break;
						}
						else if((board[i][(j+1)%4] == 'O' && board[i][(j+2)%4] == 'O' && board[i][(j+3)%4] == 'O')
							||(board[(i+1)%4][j] == 'O' && board[(i+2)%4][j] == 'O' && board[(i+3)%4][j] == 'O'))
						{
							cout<<"Case #"<<cno+1<<": "<<s2<<endl;
							flag = 0;//游戏结束
							spe = 1;//游戏非正常结束
							break;
						}
						
				    }
			}
			if(spe == 1)
				break;
		}
		if(flag == 1 )
			cout<<"Case #"<<cno+1<<": "<<s4<<endl;
	    if(flag == 0 && spe == 0)
			cout<<"Case #"<<cno+1<<": "<<s3<<endl;

	}
	return 0;
}

