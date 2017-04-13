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
	ifstream fin("A.in");
	ofstream fout("A.out");
	
	int T, N;
	fin >> T;
	for (int casenum = 1; casenum <= T; casenum++)
	{
		fin >> N;
		char tab[N][N];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				fin >> tab[i][j];
		int numgames[N], numwins[N];
		double wp[N], owp[N], oowp[N];
		for (int i = 0; i < N; i++)
		{
			numgames[i] = 0;
			numwins[i] = 0;
			for (int j = 0; j < N; j++)	
			{
				if (tab[i][j] != '.')
					numgames[i]++;
				if (tab[i][j] == '1')
					numwins[i]++;
			}
			wp[i] = numwins[i] /(1.0*numgames[i]);
		}	
		for (int i = 0; i < N; i++)
		{
			owp[i] = 0;
			for (int j = 0; j < N; j++)
			{
				if (tab[i][j] == '1')
				{
					owp[i] += numwins[j]/(1.0*(numgames[j]-1));
				}
				else if (tab[i][j] == '0')
				{
					owp[i] += (numwins[j]-1)/(1.0*(numgames[j]-1));
				}
			}
			owp[i] /= (1.0*numgames[i]);
		}	
		
		for (int i = 0; i < N; i++)
		{
			oowp[i] = 0;
			for (int j = 0; j < N; j++)
			{
				if (tab[i][j] != '.')
				{
					oowp[i] += owp[j];
				}
			}
			oowp[i] /= (1.0*numgames[i]);
		}
		fout << "Case #" << casenum << ": " << endl;
		for (int i = 0; i < N; i++)
			fout << setprecision(12) << (0.25 * wp[i] + 0.50 * owp[i] + 0.25 * oowp[i]) << endl;
	}
}
