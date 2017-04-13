#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int tc;
	scanf("%d", &tc);
	for (int cur = 1; cur <= tc; cur++)
	{
		int n;
		int s;
		int p;
		scanf("%d %d %d", &n, &s, &p);
		vector<int> scores(n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &scores[i]);
		}
		sort(scores.rbegin(), scores.rend());
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			int left = scores[i] - p;
			if (left < 0)
			{
				break;
			}
			int lower = left/2;
			int upper = left-lower;

			if (lower < p-2 || upper < p-2)
			{
				break;
			}

			if (lower == p-2 || upper == p-2)
			{
				if (s > 0)
				{
					s--;
				}
				else
				{
					break;
				}
			}

			res++;	
		}

		printf("Case #%d: %d\n", cur, res);
	}
	return 0;
}