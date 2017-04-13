#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstdlib>
using namespace std;

int main()
{
	ifstream fin("bot.in");
	ofstream fout("bot.out");
	int T, N;
	fin >> T;
	for (int casenum = 1; casenum <= T; casenum++)
	{
		fin >> N;
		int ans = 0, p;
		char r;
		int curr[2];
		int maxm[2];
		curr[0] = 1; curr[1] = 1;
		maxm[0] = 0; maxm[1] = 0;
		vector< queue<int> > next;
		queue<int> o, b;
		next.push_back(o);
		next.push_back(b);
		vector<int> order;
		for (int i = 0; i < N; i++)
		{
			fin >> r >> p;
			if (r == 'O')
			{
				order.push_back(0);
				next[0].push(p);
			}
			else
			{
				order.push_back(1);
				next[1].push(p);
			}
		}
		for (int i = 0; i < N; i++)
		{
			int x = order[i];
			int y = (x+1)%2;
			int steps = max(0, abs(next[x].front() - curr[x]) - maxm[x]) + 1;
			//cout << steps << ' ' << x << ' ' << curr[x] << ' ' << maxm[x] << endl;
			ans += steps;
			maxm[y] += steps;
			curr[x] = next[x].front();
			next[x].pop();
			maxm[x] = 0;
		}
		//cout << endl;
		fout << "Case #" << casenum << ": " << ans << endl;
	}
}
