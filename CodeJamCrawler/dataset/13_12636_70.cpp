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

set<int> Read(int board[100][100], int n, int m, int line, int dir)
{
	set<int> out;
	if(dir==1)	//1 horizontal 2 vertical
		for (int i = 0; i < m; ++i) out.insert(board[line][i]);
	else
		for (int i = 0; i < n; ++i) out.insert(board[i][line]);
	return out;
}

int MinBoard(int board[100][100], int n, int m)
{
	int out=1000;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(board[i][j]<out) out=board[i][j];
		}
	}
	return out;
}

bool AllSame(int board[100][100], int n, int m)
{
	int temp=board[0][0];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(board[i][j]!=temp) return false;
		}
	}
	return true;
}

int main()
{
	ifstream input;
	input.open("B-small-attempt0.in",ios::in);
	ofstream out;
	out.open("outputlawn.txt",ios::out);

	int count;
	input>>count;

	int board[100][100];

	for (int i = 1; i <= count; ++i)
	{
		int n,m;
		input>>n>>m;

		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < m; ++k)
			{
				input>>board[j][k];
				 // cout<<board[j][k];
			}
			 // cout<<endl;
		}	//board has been readed

		bool possible=false;
		bool quit=false;
		set<int> tempLine;
		while(!quit)
		{
			int line=1000;	//current line to be processed
			int dir;		//current direction to be processed
			int element=MinBoard(board,n,m);
			for (int j = 0; j < n; ++j)
			{
				tempLine.clear();
				tempLine=Read(board,n,m,j,1);
				if(tempLine.size()==1 &&
					*tempLine.upper_bound(0)==element)
				{
					line=j;
					dir=1;
				}
			}
			for (int j = 0; j < m; ++j)
			{
				tempLine.clear();
				tempLine=Read(board,n,m,j,2);
				if(tempLine.size()==1 &&
					*tempLine.upper_bound(0)==element)
				{
					line=j;
					dir=2;
				}
			}

			if(line==1000)
			{
				quit=true;
				possible=false;
			}
			else
			{
				if (dir==1)	//look for verticals
				{
					for (int j = 0; j < m; ++j)
					{
						tempLine.clear();
						tempLine=Read(board,n,m,j,2);
						if(tempLine.size()>1)
						{
							int elementToIncrease=*tempLine.upper_bound(*tempLine.upper_bound(0));
							board[line][j]=elementToIncrease;
						}
					}
				}
				else	//look for verticals
				{
					for (int j = 0; j < n; ++j)
					{
						tempLine.clear();
						tempLine=Read(board,n,m,j,1);
						if(tempLine.size()>1)
						{
							int elementToIncrease=*tempLine.upper_bound(*tempLine.upper_bound(0));
							board[j][line]=elementToIncrease;
						}
					}
				}
			}
			if(AllSame(board,n,m)==true)
			{
				 quit=true;
				 possible=true;	
			}
		}

		//printing the output
		out<<"Case #"<<i<<": ";
		if(possible==true) out<<"YES";
		else out<<"NO";
		if(i<count) out<<endl;
		
		// cout<<endl;
		// input>>temp;
		// cout<<total<<endl;
	}

	return 0;
}
