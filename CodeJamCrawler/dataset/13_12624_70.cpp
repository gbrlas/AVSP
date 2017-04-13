#include <string>
#include <map>
#include <math.h>
#include <sstream>
#include <time.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

#define fx first
#define sx second

typedef pair<int,int> ii;
typedef vector<int> vec;
typedef vector<ii> vecp;
typedef long long int lli;
typedef unsigned long long int ulli;

int main()
{
	ifstream read;
	read.open("A-small-attempt2.in",ios::in);
	ofstream out;
	out.open("output.txt",ios::out);

	int count;
	read>>count;

	char board[4][4];
	string temp;
	

	for (int i = 1; i <= count; ++i)
	{
		bool xWin=false;
		bool oWin=false;
		for (int j = 0; j < 4; ++j)
		{
			read>>temp;
			for (int k = 0; k < 4; ++k)
			{
				board[j][k]=temp[k];
				// cout<<board[j][k];
			}
			// cout<<endl;
		}
		//board has been readed

		int total=0;
		for (int j = 0; j < 4; ++j)		//horizontal and vertical cases
		{
			int xCounth=0;
			int xCountv=0;
			int oCounth=0;
			int oCountv=0;

			for (int k = 0; k < 4; ++k)
			{
				if(board[j][k]=='T')
				{
					++xCounth;
					++oCounth;
					++total;
				}
				if (board[j][k]=='X')
				{
					++xCounth;
					++total;
				}
				if (board[j][k]=='O')
				{
					++oCounth;
					++total;
				}

				if(board[k][j]=='T')
				{
					++xCountv;
					++oCountv;
				}
				if (board[k][j]=='X')
				{
					++xCountv;
				}
				if (board[k][j]=='O')
				{
					++oCountv;
				}
			}

			// cout<<xCounth<<" "<<xCountv<<" "<<oCounth<<" "<<oCountv<<endl;
			if(xCounth==4 || xCountv==4)
			{
				 xWin=true;
				 // break;	
			}
			else if (oCounth==4 || oCountv==4)
			{
				 oWin=true;
				 // break;
			}
		}

		int xCount=0;
		int oCount=0;
		for (int j = 0; j < 4; ++j) //first diagonal
		{
			if(board[j][j]=='X' || board[j][j]=='T') ++xCount;
			if(board[j][j]=='O' || board[j][j]=='T') ++oCount;
		}

		if (xCount==4) xWin=true;
		if (oCount==4) oWin=true;


		xCount=0;
		oCount=0;
		for (int j = 0; j < 4; ++j) //second diagonal
		{
			if(board[j][3-j]=='X' || board[j][3-j]=='T') ++xCount;
			if(board[j][3-j]=='O' || board[j][3-j]=='T') ++oCount;
		}

		if (xCount==4) xWin=true;
		if (oCount==4) oWin=true;

		//printing the output
		out<<"Case #"<<i<<": ";
		if(xWin==true) out<<"X won";
		else if(oWin==true) out<<"O won";
		else
		{
			if(total==16) out<<"Draw";
			else out<<"Game has not completed";
		}

		// cout<<endl;
		if(i<count) out<<endl;
		// read>>temp;
		// cout<<total<<endl;
	}

	return 0;
}
