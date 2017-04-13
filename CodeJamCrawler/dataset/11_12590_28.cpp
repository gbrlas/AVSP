#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include <functional>
#include<vector>
#include<string>
#include <iostream>
#include <sstream>
#include<set>
using namespace std;

#define fo(i,n) for(i=0;i<(n);++i)


typedef vector<int> vi ;
typedef vector<string> vs ;
typedef vector<double> vd ;

#define loop(i,n) for(i=0;i<n;i++)
#define sz(x) x.size();
#define INF (1<<30)

char grid[60][60];
int r,c;
int check2X2(int x,int y)
{
	int i,j;

	for(i=x;i<x+2;i++)
	{
		for(j=y;j<y+2;j++)
		{
			if(i>=0 && i<r && j>=0 && j<c)
			{
				if(grid[i][j] != '#')
					return 0;
			}
			else
				return 0;

		}
	}
	return 1;
}

void fillRed(int i, int j)
{
	grid[i][j] = '/';
	grid[i][j+1] = '\\';
	grid[i+1][j] = '\\';
	grid[i+1][j+1]= '/';
}
int main(void)
{
	FILE *in,*out;

	in = fopen("A-large.in","r");
	out = fopen("a.out","w");

	int t,T,i,j;
	char ch[60];
	int sol;


	fscanf(in,"%d",&T);
	for(t=0;t<T;t++)
	{
		fscanf(in,"%d %d", &r, &c);
		loop(i,r)
		{
			fscanf(in,"%s",ch);
			loop(j,c)
			{
				grid [i][j] = ch[j];
			}
		}

		loop(i,r)
		{
			loop(j,c)
			{
				if(grid[i][j] == '#')
				{
					if(check2X2(i,j))
					{
						fillRed(i,j);
					}
				}
			}
		}

		sol = 1;
		loop(i,r)
		{
			loop(j,c)
			{
				if(grid[i][j]== '#')
					sol = 0;
			}
		}

		fprintf(out,"Case #%d:\n", t+1);
		if(!sol)
			fprintf(out,"Impossible\n");
		else
		loop(i,r)
		{
			loop(j,c)
			{
				fprintf(out,"%c", grid[i][j]);
			}
			fprintf(out,"\n");
		}

	}

	return 0;
}
