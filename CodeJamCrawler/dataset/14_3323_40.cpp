#include <cstdio>
#include <vector>
#include <algorithm>

int main()
{
	int T;
	scanf("%d", &T);
	for (int t=1; t<=T; t++)
	{
		int N, X;
		scanf("%d %d", &N, &X);
		std::vector<int> S(N);
		for (int i=0; i<N; i++)
			scanf("%d", &S[i]);
		sort(S.rbegin(), S.rend());
		int d = 0;
		int todo = N;
		while(todo > 0)
		{
			int cap = X;
			int o;
			for (o=0; o<N; o++)
				if (S[o] <= cap)
				{
					cap -= S[o];
					S[o] = 1000;
					d++;
					todo--;
					break;
				}
			if (todo == 0)
				break;
			int a;
			for (a=0; a<N; a++)
				if (S[a] <= cap)
				{
					S[a] = 1000;
					todo--;
					break;
				}
		}
		printf("Case #%d: %d\n", t, d);
	}
	return 0;
}
