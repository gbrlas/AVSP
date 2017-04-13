#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstdlib>
#include<iomanip>
using namespace std;

double Ep[1001];
double sumEp;

int main()
{
	ifstream fin("goro.in");
	ofstream fout("goro.out");
	Ep[2] = 1;
	sumEp = 1;
	for (int i = 3; i <= 1000; i++)
	{
		Ep[i] = 2*sumEp/((double) i-1) + 1;
		sumEp += Ep[i];
	}
	
	int T, N, cyclen;
	fin >> T;
	for (int casenum = 1; casenum <= T; casenum++)
	{
		fin >> N;
		int arr[N];
		bool used[N];
		double ans = 0;
		for (int i = 0; i < N; i++)
		{
			fin >> arr[i];
			arr[i]--;
			used[i] = false;
		}
		for (int i = 0; i < N; i++)
		{
			cyclen = 0;
			int j = i;
			while (!used[j])
			{
				used[j] = true;
				cyclen++;
				j = arr[j];
			}
			if (cyclen > 1)
				ans += 1 + Ep[cyclen];
		}
		fout << fixed << setprecision(6) << "Case #" << casenum << ": " << ans << endl;
	}
}
