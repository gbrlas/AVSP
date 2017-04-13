
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>

#include <iostream>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <list>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
using namespace std;

struct pos
{
	int altitude;
	int x;
	int y;
};

bool MyCmp(pos a,pos b)
{
	if(a.altitude<b.altitude)
		return true;
	else if(a.altitude==b.altitude)
	{
		if(a.x<b.x)
			return true;
		else if(a.x==b.x)
		{
			if(a.y<b.y)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

int N,H,W;
int input[100][100];
char result[100][100];
pos sorted[10000];
int num;

char findChar(int x,int y)
{
	int alti=input[x][y];
	char r='.';
	if(x-1>=0&&input[x-1][y]<alti)
	{
		alti=input[x-1][y];
		r=result[x-1][y];
	}
	if(y-1>=0&&input[x][y-1]<alti)
	{
		alti=input[x][y-1];
		r=result[x][y-1];
	}
	if(y+1<W&&input[x][y+1]<alti)
	{
		alti=input[x][y+1];
		r=result[x][y+1];
	}
	if(x+1<H&&input[x+1][y]<alti)
	{
		alti=input[x+1][y];
		r=result[x+1][y];
	}
	return r;
}

void solve()
{
	char c='a';
	for(int i=0;i<num;i++)
	{
		char r=findChar(sorted[i].x,sorted[i].y);
		if(r=='.')
		{
			result[sorted[i].x][sorted[i].y]=c;
			c++;
		}
		else
			result[sorted[i].x][sorted[i].y]=r;
	}
}

int main()
{
	ifstream infile("D:\\B-small-attempt0.in.txt",ios::in);
	ofstream outfile("D:\\result.out.txt",ios::out);
	//
	infile >> N;
	for(int i=0;i<N;i++)
	{
		infile >> H >> W;
		num=0;
		for(int m=0;m<H;m++)
			for(int n=0;n<W;n++)
			{
				result[m][n]='.';
				infile >> input[m][n];
				sorted[num].altitude=input[m][n];
				sorted[num].x=m;
				sorted[num].y=n;
				num++;
			}
		//
		sort(sorted,sorted+num,MyCmp);
		solve();
		//
		outfile << "Case #" << i+1 << ":\n";
		//
		map<char,char> CharMap;
		char cc='a';
		for(int m=0;m<H;m++)
		{
			for(int n=0;n<W;n++)
			{
				if(CharMap.count(result[m][n])==0)
				{
					CharMap[result[m][n]]=cc++;
				}
				outfile << CharMap[result[m][n]] << ' ';
			}
			outfile << endl;
		}
	}
	return 0;
}