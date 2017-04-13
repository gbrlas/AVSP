#include <iostream>
#include <algorithm>
#include <memory>
#include <limits>

using namespace std;

int g[20000], c[20000], v[20000];
int d[20000][2];

int main()
{
	int N;
	cin >> N;
	int cases =  0;
	while (N--)
	{
		int M;
		cin >> M;
		int V;
		cin >> V;
		for (int i=0; i<(M-1)/2; i++)
			cin >> g[i] >> c[i];
		for (int i=(M-1)/2; i<M; i++)
			cin >> v[i];
		for (int i=0; i<M; i++)
			d[i][0]=d[i][1] = 100000000;
		for (int i=(M-1)/2; i<M; i++)
		{
			d[i][v[i]] = 0;
		}

		for (int i=(M-1)/2-1; i>=0; i--)
		{
			if (g[i] == 0) // or
			{
				d[i][0] = min(d[i*2+1][0] + d[i*2+2][0], 100000000);
				d[i][1] = min(100000000,min(d[i*2+1][1] + d[i*2+2][0], min(d[i*2+1][0]+d[i*2+2][1], d[i*2+1][1]+d[i*2+2][1])));
			}
			else // and
			{
				d[i][0] = min(100000000,min(d[i*2+1][1] + d[i*2+2][0], min(d[i*2+1][0]+d[i*2+2][1], d[i*2+1][0]+d[i*2+2][0])));
				d[i][1] = min(d[i*2+1][1] + d[i*2+2][1], 100000000);
			}

			if (c[i])
			{
				if (g[i] == 1) // or
				{
					d[i][0] = min(d[i][0], min(d[i*2+1][0] + d[i*2+2][0] + 1, 100000000));
					d[i][1] = min(d[i][1], min(100000000,min(d[i*2+1][1] + d[i*2+2][0]+1, min(d[i*2+1][0]+d[i*2+2][1]+1, d[i*2+1][1]+d[i*2+2][1]+1))));
				}
				else // and
				{
					d[i][0] = min(d[i][0], min(100000000,min(d[i*2+1][1] + d[i*2+2][0]+1, min(d[i*2+1][0]+d[i*2+2][1]+1, d[i*2+1][0]+d[i*2+2][0]+1))));
					d[i][1] = min(d[i][1], min(d[i*2+1][1] + d[i*2+2][1]+1, 100000000));
				}			
			}
		}
		
		cout << "Case #" << ++cases << ": ";
		if (d[0][V] < 100000000) cout << d[0][V]; else cout << "IMPOSSIBLE";
		cout << endl;
	}
	return 0;
}