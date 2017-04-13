#include <cstdio>
#include <algorithm>
using namespace std;
int dx[10005],
    dy[10005],
    trzymam[10005];
int main()
{
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		bool OK = false;
		int n, truelove;
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			trzymam[i] = 0;
		for(int i = 0; i < n; i++)
			scanf("%d %d", &dx[i], &dy[i]);
		scanf("%d", &truelove);

		trzymam[0] = min(dy[0], dx[0]);

		for(int i = 0; i < n; i++)
		{
			if(truelove-dx[i] <= trzymam[i])
			{
				OK = true;
				break;
			}
			for(int j = i+1; dx[j]-dx[i] <= trzymam[i] && j<n; j++)
			{
				int nt = min(dy[j], dx[j]-dx[i]);
				if(nt > trzymam[j])
					trzymam[j] = nt;
			}
				
		}

		printf("Case #%d: ", t);
		if(OK)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
