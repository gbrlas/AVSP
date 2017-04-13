#include <cstdio>
#include <cstring>

int T,N;
int arr[1001];
bool visited[1001];
int main()
{
	freopen("D-small-attempt2.in","r",stdin);
	freopen("D.out","w",stdout);
	int i, j, k;
	scanf("%d",&T);
	for (i = 1; i <= T; i++)
	{
		scanf("%d",&N);
		for (j = 1; j <= N; j++)
			scanf("%d",&arr[j]);
		memset(visited, false, sizeof(visited));
		int ans = 0;
		for (j = 1; j <= N; j++)
		{
			if (visited[j] || arr[j] == j)
				continue;
			else
			{
				int len = 1;
				k = arr[j];
				while (arr[k]!=arr[j])
				{
					visited[k] = true;
					k = arr[k];
					len+=1;
				}	
				ans += len;
			}
		}
		printf("Case #%d: %lf\n",i ,double(ans));
	}
}