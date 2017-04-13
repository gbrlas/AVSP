#include <iostream>
#include <algorithm>
#include <memory>

using namespace std;

bool v[3000];
bool g[3000][3000];
int t[3000];
int q[3000];
int deg[3000];
int op, cl;
int N, M;

int main()
{
	int C;
	cin >> C;
	int cases = 0;
	while (C--)
	{
		cin >> N >> M;
		memset(v, 0, sizeof v);
		memset(g, 0, sizeof g);
		memset(t, -1, sizeof t);
		memset(deg, 0, sizeof deg);
		op = cl = 0;
		for (int i=0; i<M; i++)
		{
			int T;
			cin >> T;
			for (int j=0; j<T; j++)
			{
				int a, b;
				cin >> a >> b;
				a--;
				if (b == 1) t[i] = a;
				else
				{
					deg[i]++;
					g[i][a] = true;
				}
			}
			if (deg[i] == 0)
			{
				q[op++] = i;
			}
		}
		bool possible = true;
		while (cl < op)
		{
			int k = q[cl++];
			if (t[k] < 0)
			{
				possible = false;
				break;
			}
			v[t[k]] = true;
			for (int i=0; i<M; i++)
				if (deg[i] > 0 && g[i][t[k]])
				{
					deg[i]--;
					g[i][t[k]] = false;
					if (deg[i] == 0)
					{
						q[op++] = i;
					}
				}
		}
		cout << "Case #" << ++ cases << ":";
		if (possible) 
		{
			for (int i=0; i<N; i++)
				if (v[i]) cout << " 1"; else cout << " 0";
			cout << endl;
		}
		else cout << " IMPOSSIBLE" << endl;
	}
	return 0;
}