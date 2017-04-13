#include <fstream>
#include <queue>
using namespace std;

ifstream fin ("basin.in");
ofstream fout ("basin.out");
int test,length,width;
int board[102][102];
char answer[102][102];
char temp;
char a;
int direction(int pos, int north, int west, int east, int south); //return 0-sink,1-N,2-W,3-E,4-S
void recurse(int i, int j);
int main()
{
	fin >> test;
	for(int i=0;i<test;i++)
	{
		a='a';
		fin >> length >> width;
		for(int j=0;j<=length+1;j++)
		{
			board[j][0]=-1;
			board[j][width+1]=-1;
		}
		for(int j=0;j<=width+1;j++)
		{
			board[0][j]=-1;
			board[length+1][j]=-1;
		}
		for(int j=1;j<length+1;j++)
		{
			for(int k=1;k<width+1;k++)
			{
				fin >> board[j][k];
			}
		}
		for(int j=1;j<length+1;j++)
		{
			for(int k=1;k<width+1;k++)
			{
				temp=a;
				if(answer[j][k]==0)
				{
					recurse(j,k);
					a++;
				}
			}
		}
		fout<<"Case #"<<i+1<<":\n";
		for(int j=1;j<=length;j++)
		{
			for(int z=1;z<=width;z++)
			{
				fout<<answer[j][z]<<" ";
			}
			fout<<"\n";
		}
		for(int j=0;j<102;j++)
		{
			for(int k=0;k<102;k++)
			{
				answer[j][k]=0;
			}
		}
	}
	return (0);
}

int xcoord[5] = {0,-1,0,0,1};
int ycoord[5] = {0,0,-1,1,0};

void recurse(int i, int j)
{
	int dir = direction(board[i][j],board[i-1][j],board[i][j-1],board[i][j+1],board[i+1][j]);
	if(dir==0)
	{
		answer[i][j]=temp;
	}
	else if(answer[i+xcoord[dir]][j+ycoord[dir]]==0)
	{
		recurse(i+xcoord[dir],j+ycoord[dir]);
		answer[i][j]=temp;
	}
	else //(answer[i+xcoord[dir],j+ycoord[dir]]==isChar())
	{
		a--;
		temp=answer[i+xcoord[dir]][j+ycoord[dir]];
		answer[i][j]=temp;
	}
}
int direction(int pos, int north, int west, int east, int south) //return 0-sink,1-N,2-W,3-E,4-S
{
	int min=1000000;
	if(min>north && north!=-1)
	{
		min=north;
	}
	if(min>east && east!=-1)
	{
		min=east;
	}
	if(min>south && south!=-1)
	{
		min=south;
	}
	if(min>west && west!=-1)
	{
		min=west;
	}
	if(min>=pos)
	{
		return 0;
	}
	if(min==north && north!=-1)
	{
		return 1;
	}
	if(min==west && west!=-1)
	{
		return 2;
	}
	if(min==east && east!=-1)
	{
		return 3;
	}
	if(min==south && south!=-1)
	{
		return 4;
	}
	return 0;
}
