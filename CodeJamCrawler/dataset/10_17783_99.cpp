#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, k;

int main()
{
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int nCase = 1; nCase <= T; ++nCase)
	{
		scanf("%d%d", &n, &k);

		printf("Case #%d: ", nCase);
		if (k % (1 << n) == ((1 << n) - 1) && k != 0) printf("ON\n");
		else printf("OFF\n");
	}

	return 0;
}
