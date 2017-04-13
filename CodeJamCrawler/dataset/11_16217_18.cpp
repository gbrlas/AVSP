#include<iostream>
#include<fstream>
#include<sstream>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<cstdlib>
#include<iomanip>

using namespace std;

int main()
{
	ifstream fin("A.in");
	ofstream fout("A.out");
	
	int T, X, S, R, t, N;
	fin >> T;
	for (int cas = 1; cas <= T; cas++)
	{
		fin >> X >> S >> R >> t >> N;
		int B, E, nextw;
		vector< pair <int, int> > w;
		int left = X;
		int R2 = R-S;
		for (int i = 0; i < N; i++)
		{
			fin >> B >> E >> nextw;
			left -= E - B;
			w.push_back(make_pair(nextw + S, B - E));
		}
		double totaltime = 0.0, dt = (double) t;
		w.push_back(make_pair(S, -left));	
		sort (w.begin(), w.end());
		for (int i = 0; i < w.size(); i++)
		{
			int d = - w[i].second;
			int v = w[i].first;
			if (dt > 0)
			{
				double timerun = d/((double) (v + R2));
				if (dt > timerun)
				{
					totaltime += timerun;
					dt -= timerun;
				}
				else
				{
					totaltime += dt;
					double dleft = (double) d - dt*((double) (v + R2));
					totaltime += dleft/((double) v);
					dt = 0;
				}
			}
			else
				totaltime += d/((double) v);
		}
	    fout << fixed;		
		fout << setprecision(8) << "Case #" << cas << ": " << totaltime << endl;
	}
}
