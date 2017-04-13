#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstdlib>
#include<iomanip>
#include<string>
using namespace std;

int dist[1000001];

int main()
{
	ifstream fin("B.in");
	ofstream fout("B.out");
	
	long long T, L, t, N, C, b, sumb;
	fin >> T;
	for (int casenum = 1; casenum <= T; casenum++)
	{
		fin >> L >> t >> N >> C;
		int a;
		int sumd = 0;
		vector<int> save;
		bool past = false;
		for (int i = 0; i < C; i++)
		{
			fin >> a;
			for (int k = 0; k*C+i < N; k++)
				dist[k*C+i] = a;
		}
		for (int j = 0; j < N; j++)
		{
			sumd += dist[j];
			if (past)
				save.push_back(-dist[j]);
			
			if ((sumd > t/2)&& (past == false))
			{
				past = true;
				save.push_back(-(sumd - t/2));
			}
		}

		sort(save.begin(), save.end());
		long long total = sumd*2;
		/*for (int i = 0; i < N; i++)
			cout << dist[i] << ' ';
		cout << endl;
		cout << total << endl;
		for (int i = 0; i < save.size(); i++)
			cout << save[i] << endl;*/
		for (int i = 0; ((i < save.size()) && (i < L)); i++)
			total += save[i];
		fout << "Case #" << casenum << ": " << total << endl;
	}
}
