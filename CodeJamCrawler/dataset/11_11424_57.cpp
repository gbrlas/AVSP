// aa.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <vector>
#include <map>

using namespace std;

bool valid(vector<vector<char> >& b, int r, int c)
{
	return b[r][c] == '#' && b[r+1][c] == '#' && b[r][c+1] == '#' && b[r+1][c+1] == '#';
}

void place(vector<vector<char> >& b, int r, int c)
{
	b[r][c] = b[r+1][c+1] = '/';
	b[r][c+1] = b[r+1][c] = '\\';
}

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream in("test.txt");
	ofstream out("out.txt");

	int t;
	in >> t;
	for(int i=0; i<t; ++i)
	{
		int nr, nc;
		in >> nr >> nc;

		vector<vector<char> > b(nr, vector<char>(nc));
		for(int r=0; r<nr; ++r)
		{
			for(int c=0; c<nc; ++c)
			{
				in >> b[r][c];
			}
		}

		for(int r=0; r<nr-1; ++r)
		{
			for(int c=0; c<nc-1; ++c)
			{
				if(valid(b,r,c))
					place(b,r,c);
			}
		}

		bool possible = true;
		for(int r=0; r<nr; ++r)
		{
			for(int c=0; c<nc; ++c)
			{
				if(b[r][c] == '#')
				{
					possible = false;
					break;
				}
			}
		}

		out << "Case #" << (i+1) << ":" << endl;
		if(possible)
		{
			for(int r=0; r<nr; ++r)
			{
				for(int c=0; c<nc; ++c)
				{
					out << b[r][c];
				}
				out << endl;
			}
		}
		else
		{
			out << "Impossible" << endl;
		}
	}
	return 0;
}

