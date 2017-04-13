#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstdlib>
#include<iomanip>
#include<string>
using namespace std;

int main()
{
	ifstream fin("C.in");
	ofstream fout("C.out");
	
	int T, N, L, H;
	fin >> T;
	for (int casenum = 1; casenum <= T; casenum++)
	{
		fin >> N >> L >> H;
		fout << "Case #" << casenum << ": ";
		int notes[N];
		bool poss;
		for (int i = 0; i < N; i++)
			fin >> notes[i];
		for (int j = L; j <= H; j++)
		{
			poss = true;
			for (int i = 0; i < N; i++)
			{
				if ((j % notes[i] != 0) && (notes[i] % j != 0))
				{
					poss = false;
					break;
				}
			}
			if (poss)
			{
				fout << j << endl;
				break;
			}
		}
		if (!poss)
		{
			fout << "NO" << endl;
		}
	}
}
