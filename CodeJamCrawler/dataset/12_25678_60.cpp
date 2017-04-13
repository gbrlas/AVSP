#include <stdio.h>

#define MAX 128

int v[MAX];

int main()
{
	int casos, cas;
	int n, s, p;
	int i, cnt;
	
	scanf("%d", &casos);
	
	for (cas=1; cas <= casos; cas++)
	{
		printf("Case #%d: ", cas);
		scanf("%d %d %d", &n, &s, &p);
		
		cnt = 0;
		for (i=0; i<n; i++)
		{
			scanf("%d", &v[i]);
			if (v[i] / 3 >= p || (v[i]%3 != 0 && (v[i] / 3)+1 >= p))
				cnt ++;
			else if (s)
			{
				if (p - (v[i]-p)/2 <= 2 && v[i]>=p)
				{
					s--;
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}
	
	return 0;
}
