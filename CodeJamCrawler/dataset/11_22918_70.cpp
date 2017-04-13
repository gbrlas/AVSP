#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int kases;
	scanf("%d", &kases);
	
	for (int i = 0; i < kases; ++i)
	{
		int n;
		scanf("%d", &n);
		
		int candies[1000];
		
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &candies[j]);
		}
		
		sort(candies, candies + n);
		
		int candyVal = 0;
		int gain = 0;
		for (int j = n - 1; j > 0; --j)
		{
			gain += candies[j];
			candyVal ^= candies[j];
		}
		
		printf("Case #%d: ", i + 1);
		
		if (candyVal != candies[0])
			printf("NO\n");
		else
			printf("%d\n", gain);
	}
	
	return 0;
}
