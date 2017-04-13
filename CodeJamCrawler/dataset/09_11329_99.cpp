// GCJ09.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	int casecnt;
	fstream fp_in, fp_out;

	fp_in.open("D:\\Jam\\R1\\B-small.in",ios::in);
	fp_out.open("D:\\Jam\\R1\\B-small.out",ios::out);
	fp_in>>casecnt;
	for(int e=1; e<=casecnt; e++)
	{
		int h, w;
		fp_in>>h>>w;
		int a[100][100];
		char b[100][100];
		for(int i=0; i<h; i++)
		{
			for(int j=0; j<w; j++)
			{
				a[i][j]=-1;
				b[i][j]=0;
			}
		}

		for(int i=0; i<h; i++)
			for(int j=0; j<w; j++)
				fp_in>>a[i][j];

		char c='a';
		for(int i=0; i<h; i++)
		{
			for(int j=0; j<w; j++)
			{
				if(b[i][j] != 0)
					continue;
				
				int x=i, y=j;
				bool notdone = true;
				vector<int> p,q;
				p.push_back(x); q.push_back(y);
				while(notdone)
				{
					int min = a[x][y];
					int minX=-1, minY=-1;
					if((x-1)>=0 && a[x-1][y]<min)
					{
						minX = x-1; minY = y; min = a[x-1][y];
					}
					if((y-1)>=0 && a[x][y-1]<min)
					{
						minX = x; minY = y-1; min = a[x][y-1];
					}
					if((y+1)<w && a[x][y+1]<min)
					{
						minX = x; minY = y+1; min = a[x][y+1];
					}
					if((x+1)<h && a[x+1][y]<min)
					{
						minX = x+1; minY = y; min = a[x+1][y];
					}
					if(min == a[x][y] || b[x][y] != 0)
					{
						char d=b[x][y];
						if(b[x][y] == 0)
							d = c++;
						for(int k=0; k<p.size(); k++)
						{
							b[p[k]][q[k]] = d;
						}
						notdone = false;
					}
					else
					{
						x = minX; y = minY;
						p.push_back(x);
						q.push_back(y);
					}
				}
			}
		}
		fp_out<<"Case #"<<e<<": "<<endl;
		cout<<"Case #"<<e<<": "<<endl;
		for(int i=0; i<h; i++)
		{
			for(int j=0; j<w; j++)
			{
				fp_out<<b[i][j]<<" ";
				cout<<b[i][j]<<" ";
			}
			fp_out<<endl;
			cout<<endl;
		}
	}
	return 0;
}

