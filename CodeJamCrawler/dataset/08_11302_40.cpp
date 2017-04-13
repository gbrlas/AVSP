#include <cstdio>
#include <algorithm>
using namespace std;

int list1[800], list2[800], N;

int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int t; scanf("%d", &t);
	for (int step=1; step<=t; step++)
	{
		scanf("%d", &N);
		for (int i=0; i<N; i++)
			scanf("%d", &list1[i]);
		for (int i=0; i<N; i++)
			scanf("%d", &list2[i]);
		sort(list1, list1+N);
		sort(list2, list2+N);
		int sum=0;
		for (int i=0; i<N; i++)
			sum+=list1[i]*list2[N-i-1];
		printf("Case #%d: %d\n", step, sum);
	}
	return 0;
}
