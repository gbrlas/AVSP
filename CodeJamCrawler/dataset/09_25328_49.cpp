#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <algorithm>

using namespace std;

int N;
ifstream fin("r2a.in");
ofstream fout("r2a.out");
string s[100];
int l[100];
int r[100];

int main()
{
	int T;
	int cases = 0;
	fin >> T;
	while (T--)
	{
		fin >> N;
		for (int i=0; i<N; i++) fin >> s[i];
		for (int i=0; i<N; i++)
		{
			l[i] = -1;
			for (int j=0; j<N; j++) if (s[i][j] == '1') l[i] = j;
		}
		memcpy(r, l, sizeof l);
		//sort(r, r+N);
		int ans = 0;
		for (int i=0; i<N; i++)
		{
			if (l[i] > i)
			{
				for (int j=i+1; j<N; j++)
					if (l[j] <= i)
					{
						int t = l[j];
						for (int k=j; k>i; k--)
						{
							l[k] = l[k-1];
							ans++;
						}
						l[i] = t;
						//ans++;
						break;
					}
			}
		}

		fout << "Case #" << ++cases << ": " << ans << endl;
	}
	return 0;
}