#include <iostream>
using namespace std;

int main ()
{
	freopen ("D:\\Users\\Lee\\Desktop\\A-large.in", "r", stdin);
	freopen ("D:\\Users\\Lee\\Desktop\\A-large.out", "w", stdout);
	int T, N, K;
	scanf("%d", &T);
	for (int k = 1; k <= T; k++)
	{
		printf("Case #%d: ", k);
		scanf("%d%d", &N, &K);
		if ((K + 1) % (1 << N) == 0)
			printf("ON\n");
		else
			printf("OFF\n");
	}
}