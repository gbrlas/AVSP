#include <cstdio>
#include <algorithm>
#include <map>
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <fstream>
#include <cmath>
#include <math.h>

using namespace std;

int main()
{
	int T;
	ifstream fin("A.in.txt");
	fin >> T;
	ofstream fout("A.out");
	for(int i = 1; i <= T; i++)
	{
		int N;
		fin >> N;
		int p1=1, p2 = 1;
		int res = 0;
		int temp1 = 0, temp2 = 0;
		for(int j = 0; j < N; j++)
		{
			char c;
			fin >> c;
			int s;
			fin >> s;
			
			if(c == 'O')
			{
				if(temp1 > abs(s-p1))
				{
					res += 1;
					temp2 += 1;
				}
				else
				{
					res += abs(s-p1) - temp1 + 1;
					temp2 += abs(s-p1) - temp1 + 1;
				}
				p1 = s;
				temp1 = 0;
			}
			else if(c== 'B')
			{
				if(temp2 > abs(s-p2))
				{
					res += 1;
					temp1 += 1;
				}
				else
				{
					res += abs(s-p2) - temp2 + 1;
					temp1 += abs(s-p2) - temp2 + 1;
				}
				p2 = s;
				temp2 = 0;
			}
		}
		fout <<"Case #"<<i<<": "<<res<<'\n';
	}
	return 0;
}