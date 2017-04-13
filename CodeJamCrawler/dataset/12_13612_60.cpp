#include <fstream>
#include <string>
#include <array>
#include <conio.h>
#include <iostream>
#include <list>

using namespace std;
void main()
{
	ifstream fin ("K:\\Root\\CodeJam\\Qualification Round 2012\\C\\C-large.in");
	ofstream fout ("K:\\Root\\CodeJam\\Qualification Round 2012\\C\\C-large.out");

	int T;
	fin >> T;
	int A, B, cnt, m, n, l, nosi = 0, i;
	string sn;
	list<int> nos;
	for (int t = 1; t <= T; t++)
	{
		fin >> A >> B;
		cnt = 0;
		for (m = A; m <= B; m++)
		{
			nos.clear();
			sn = std::to_string((long long)m);
			for (l = 1; l < sn.length(); l++)
			{
				std::rotate(sn.begin(), sn.begin() + 1, sn.end());
				if (sn.c_str()[0] == '0') continue;
				n = atoi(sn.c_str());
				if (n >= A && n <= B && n < m)
				{
					if (find(nos.begin(), nos.end(), n) == nos.end())
					{
						cnt++;
						nos.push_back(n);
					}
				}
			}
		}
		fout << "Case #" << t << ": " << cnt << endl;
		cout  << "Case #" << t << ": " << cnt << endl;
	}
	fin.close();
	fout.close();
}