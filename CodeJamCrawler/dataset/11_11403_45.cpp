// test1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <fstream>
#include <vector>

struct mv
{
	char r;
	int p;
};

int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;
	int t = -1;
	fstream in("test.txt");
	ofstream out("out.txt");
	in >> t;
	for(int i=0; i<t; ++i)
	{
		
		int n = -1;
		in >> n;

		vector<mv> m(n);
		for(int k=0; k<n; ++k)
		{
			in >> m[k].r >> m[k].p;
		}

		vector<mv>::const_iterator bm=m.begin(), om=m.begin(), gm=m.begin();
		while(bm != m.end() && bm->r != 'B')
			++bm;
		while(om != m.end() && om->r != 'O')
			++om;

		int time = 0;
		int op = 1, bp = 1;
		while(gm != m.end())
		{
			bool moved = false;
			time++;
			if(om == m.end())
			{
			}
			else if(om->p-op > 0)
			{
				++op;
			}
			else if(om->p-op < 0)
			{
				--op;
			}
			else if(gm != om)
			{
			}
			else
			{
				moved = true;
				++om;
				while(om != m.end() && om->r != 'O')
					++om;
			}
				
			if(bm == m.end())
			{
			}
			else if(bm->p-bp > 0)
			{
				++bp;
			}
			else if(bm->p-bp < 0)
			{
				--bp;
			}
			else if(gm != bm)
			{
			}
			else
			{
				moved = true;
				++bm;
				while(bm != m.end() && bm->r != 'B')
					++bm;
			}

			if(moved)
				++gm;
		}
		out << "Case #" << i+1 << ": " << time << endl;
	}
	return 0;
}

