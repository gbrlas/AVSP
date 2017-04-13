
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

ifstream in;
ofstream out;

int mob [1005][1005];

int freq[1005];

bool cmp (int a, int b)
{
	return(a > b);
}


int main()
{
	string name = "file.txt";
	in.open(name.c_str());
	name = "out.txt";

	out.open(name.c_str());

	int numtest, P, K, L, temp, pos, casenum = 1;

	in >> numtest;

	for(int q = 0; q < numtest; q++)
	{
		memset(mob, 0, sizeof(mob));

		in >> P >> K >> L;

		for(int y = 0; y < L; y++)
		{
			in >> freq[y];
		}

		sort(freq, freq + L, cmp);

		pos = 0;

		temp = 0;

		for(int x = 0; x < L ; x++)
		{
			temp = P + 1;
			
			for(int g = 0; g < K; g++)
			{
				if(mob[g][0] < temp && !mob[g][P])
				{
					temp = mob[g][0];
					pos = g;
				}

			}

			mob[pos][0]++;

			temp = 1;
			while(mob[pos][temp] != 0)
				temp++;

			mob[pos][temp] = freq[x];
			
		}

		temp = 0;

		for(int f = 0; f < K; f++)
		{
			for(int u = 1; u <= mob[f][0] ; u++)
			{
				temp += mob[f][u] * u;
			}
		}

		out << "Case #" << casenum << ": " << temp << endl;
		casenum++;

	}


	in.close();
	out.close();

	return 0;
}


