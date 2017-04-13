// GCJ - Saving The Universe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

struct node
{
	string eng;
	int c;

}lol[110];

string q[10008];

bool operator <(node a, node b)
{
	return(a.c > b.c);
}
ifstream in;
ofstream out;

int main()
{
	string name = "file.txt", temp;
	in.open(name.c_str());
	name = "out.txt";

	out.open(name.c_str());

	int cases, numS, numQ, casenum = 1, itemp, count, index;
	in >> cases;
	for(int x = 0; x < cases; x++)
	{
		count = 0;
		in >> numS;

		getline(in, temp);
		for(int y = 0; y < numS; y++)
		{
			getline(in, lol[y].eng);
			lol[y].c = 0;
		}

		in >> numQ;
		getline(in, temp);

		for(int z = 0; z < numQ; z++)
		{
			getline(in, temp);

			q[z] = temp;

		}

		for(int g = 0 ; g < numQ ;g++ )
		{
			if(g == 0)
			{
				for(int d = 0; d < numS; d++)
				{
					lol[d].c = 0;
					for(int e = 0; e < numQ; e++ )
					{
						if(lol[d].eng != q[e] )
							lol[d].c++;
						else
							break;
					}
				}
				sort(lol, lol + numS);

			}
			else
				if(lol[0].eng == q[g])
				{
					count++;

					for(int d = 0; d < numS; d++)
					{
						lol[d].c = 0;

						for(int e = g; e < numQ; e++ )
						{
							if(lol[d].eng != q[e] )
								lol[d].c++;
							else
								break;
						}
					}

					sort(lol, lol + numS);
				}
		}

		out << "Case #" << casenum << ": " << count << endl;
		casenum++;

	}

	in.close();
	out.close();

	return 0;
}

