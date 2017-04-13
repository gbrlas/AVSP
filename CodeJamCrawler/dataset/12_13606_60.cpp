#include <fstream>
#include <string>
#include <conio.h>
#include <iostream>

using namespace std;
void main()
{
	ifstream fin ("K:\\Root\\CodeJam\\Qualification Round 2012\\C\\C-small-attempt1.in");
	ofstream fout ("K:\\Root\\CodeJam\\Qualification Round 2012\\C\\C-small1.out");

	int T;
	fin >> T;
	int A, B, cnt, m, n, l;
	string sn;
	for (int t = 1; t <= T; t++)
	{
		fin >> A >> B;
		cnt = 0;
		for (m = A + 1; m <= B; m++)
		{
			for (n = A; n < m; n++)
			{
				sn = std::to_string((long long)n);
				for (l = 0; l < sn.length(); l++)
				{
					std::rotate(sn.begin(), sn.begin() + 1, sn.end());
					if (atoi(sn.c_str()) == m)
						cnt++;
				}
			}
		}
		fout << "Case #" << t << ": " << cnt << endl;
		cout  << "Case #" << t << ": " << cnt << endl;
	}
	fin.close();
	fout.close();
}