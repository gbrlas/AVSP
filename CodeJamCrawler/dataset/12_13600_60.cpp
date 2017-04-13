#include <iostream>
#include <fstream>

using namespace std;
void main()
{
	ifstream fin ("K:\\Root\\CodeJam\\Qualification Round 2012\\B\\B-large.in");
	ofstream fout ("K:\\Root\\CodeJam\\Qualification Round 2012\\B\\B-large.out");

	int T, N, S, p, cnt, k1, k2, k3, k4;
	int *t;
	fin >> T;
	for (int TI = 1; TI <= T; TI++)
	{
		cnt = 0;
		fin >> N >> S >> p;
		t = new int[N];
		for (int i=0;i<N;i++)
		{
			fin >> t[i];

			if (t[i] % 3 == 0)
			{
				if(t[i] / 3 >= p)
				{
					cnt++;
					continue;
				}				
			}

			if (t[i] - 1 < 0) continue;
			if ((t[i] - 1) % 3 == 0)
			{
				if((t[i] - 1) / 3 + 1 >= p)
				{
					cnt++;
					continue;
				}
			}

			if (t[i] - 2 < 0) continue;
			if ((t[i] - 2) % 3 == 0)
			{
				if((t[i] - 2) / 3 + 1 >= p)
				{
					cnt++;
					continue;
				}
			}

			if (S == 0) continue;
			if ((t[i] - 2) % 3 == 0)
			{
				if((t[i] - 2) / 3 + 2 >= p)
				{
					cnt++;
					S--;
					continue;
				}
			}

			if (t[i] - 3 < 0) continue;
			if ((t[i] - 3) % 3 == 0)
			{
				if((t[i] - 3) / 3 + 2 >= p)
				{
					cnt++;
					S--;
					continue;
				}
			}

			if (t[i] - 4 < 0) continue;
			if ((t[i] - 4) % 3 == 0)
			{
				if((t[i] - 4) / 3 + 2 >= p)
				{
					cnt++;
					S--;
					continue;
				}
			}
		}

		cout << "Case #" << TI << ": " << cnt << endl;
		fout << "Case #" << TI << ": " << cnt << endl;
	}

	fin.close();
	fout.close();
}