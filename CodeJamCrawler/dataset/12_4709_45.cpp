#include<stdio.h>
int main()
{
	int T = 0;
	int t = 0;
	scanf("%d", &T);
	while(t++ < T)
	{
		int n = 0;
		int s = 0;
		int p = 0;
		int score = 0;
		int num = 0;
		int best = 0;
		int surp = 0;
		scanf("%d%d%d", &n, &s, &p);

		if(p == 0) best = 0;
		else best = 3*p-2;

		if(p <= 2) surp = p;
		else surp = 3*p-4;

		for(int i = 0; i < n; i++)
		{
			scanf("%d", &score);
			if(score >= best)
				num++;
			else if(s && score >= surp)
			{
				num++;
				s--;
			}
		}
		printf("Case #%d: %d\n", t, num);
	}
	return 0;
}