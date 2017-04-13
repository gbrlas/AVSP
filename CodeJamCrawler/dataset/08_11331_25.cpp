#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN=100000001;

int list[MaxN][2], N, M, A;
bool used[MaxN];

int main()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int t; scanf("%d", &t);
	for (int step=1; step<=t; step++)
	{
		scanf("%d%d%d", &N, &M, &A);
		printf("Case #%d:", step);
		bool t=false;
		for (int i=0; !t && i<=N; i++)
			for (int j=0; !t && j<=M; j++)
				for (int k=0; !t && k<=N; k++)
					for (int l=0; !t && l<=M; l++)
						if (k*l-i*j==A)
						{
							printf(" %d %d %d %d %d %d\n", 0, 0, i, l, k, j);
							t=true;
						}
		if (!t) printf(" IMPOSSIBLE\n");
	}
	return 0;
}
