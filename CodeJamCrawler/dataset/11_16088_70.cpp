#include <iostream>
#include <string>
using namespace std;

int n;
int value[1100];


int main()
{
	int i;
	int t, id = 0;
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w+", stdout);
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		int sum = 0;
		int xor = 0;
		int lmin = 10000000;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &value[i]);
			sum += value[i];
			xor ^= value[i];
			lmin = lmin < value[i] ? lmin : value[i];
		}
		printf("Case #%d: ", ++id);
		if (xor != 0)
		{
			printf("NO\n");
		}
		else
		{
			printf("%d\n", sum - lmin);
		}
	}
	return 0;
}
