#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

pair<pair<int,int>, int> D[1005];

int main()
{
	int T;
	scanf("%d", &T);
	int N;
	

	for(int t = 1; t <= T; t++)
	{
		scanf("%d", &N);
		for(int i = 0; i < N; i++)
		{
			D[i].second = i;
			scanf("%d", &D[i].first.second);
		}
		for(int i = 0; i < N; i++)
		{
			int x;
			scanf("%d", &x);
			D[i].first.first = 100-x;
			if(D[i].first.first == 100 || D[i].first.first == 0)
				D[i].first.second = 1;
		}
		sort(D, D+N);

		printf("Case #%d: ", t);
		for(int i = 0; i < N; i++)
			printf("%d ", D[i].second);
		printf("\n");
	}

	return 0;
}
