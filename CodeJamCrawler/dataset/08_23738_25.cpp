#include <iostream>

using namespace std;
long T;
long N, M, A;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%d", &T);
	for (long a = 0; a < T; a ++)
	{
		scanf("%d%d%d", &N, &M, &A);
		for (long x1 = 0; x1 <= N; x1 ++)
			for (long y1 = 0; y1 <= M; y1 ++)
				for (long x2 = 0; x2 <= N; x2 ++)
					for (long y2 = 0; y2 <= M; y2 ++)
						if (x1*y2-x2*y1==A || x1*y2-x2*y1==-A)
						{
							printf("Case #%d: 0 0 %d %d %d %d\n", a+1, x1, y1, x2, y2);
							goto ex;
						}
		printf("Case #%d: IMPOSSIBLE\n", a+1);
		ex:;
	}

	return 0;
}