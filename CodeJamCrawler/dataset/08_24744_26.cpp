#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>

using namespace std;

ifstream fin("c-small-attempt2.in");
ofstream fout("c.out");

double probs[10000];
int pp;
double d[1000][4];
int Q, M;

void addprobs(int dep, double now)
{
	if (dep >= Q)
	{
		probs[pp++] = now;
		return;
	}

	for (int i=0; i<4; i++)
		addprobs(dep+1, now * d[dep][i]);
}

int main()
{
	int C;
	fin >> C;
	int cases = 0;
	while (C--)
	{
		fin >> M >> Q;
		for (int i=0; i<Q; i++)
		{
			for (int j=0; j<4; j++) fin >> d[i][j];
		}
		pp = 0;
		memset(probs, 0, sizeof probs);
		addprobs(0, 1);
		sort(probs, probs+pp, greater<double>());
		double ans = 0;
		for (int i=0; i<M; i++)
			ans += probs[i];
		fout << "Case #" << ++cases << ": " << ans << endl;
	}
	return 0;
}