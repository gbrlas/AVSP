#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstdlib>
using namespace std;

int main()
{
	ifstream fin("cand.in");
	ofstream fout("cand.out");
	int T, N;
	fin >> T;
	for (int casenum = 1; casenum <= T; casenum++)
	{
		long long sum = 0, mini = 10e7, tot = 0, curr, ans;
		fin >> N;
		for (int i = 0; i < N; i++)
		{
			fin >> curr;
			tot ^= curr;
			sum += curr;
			mini = min(mini, curr);
		}
		ans = sum - mini;
		fout << "Case #" << casenum << ": ";
		if (tot == 0)
			fout << ans << endl;
		else
			fout << "NO" << endl;
	}
}
