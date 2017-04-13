#include <stdio.h>
#include <map.h>

using namespace std;

map<long int, long int> m;
map<long int, long int> it;

int ndigits(long int n)
{
	long int tens = 10;
	int digs = 1;
	while (tens <= n)
	{
		tens *= 10;
		digs++;
	}
	return digs;
}

long int good_pairs(long int n, long int B)
{
	long int gp = 0;
	int i;
	int d = ndigits(n);
	long int tens = 1;
	for (i = 1; i < d; i++)
		tens *= 10;
	
	long int k = n;	
	for (i = 1; i <= d; i++)
	{
		k = (k % 10) * tens + (k / 10);
		if (k > n && B >= k && m.find(k) == m.end())
		{
			m[k] = 1;
			gp += 1;
		}
	}
	
	return gp;
}


int main()
{
	//printf("%d %d %d %d\n", ndigits(100), ndigits(2000000), ndigits(144), ndigits(100));
	int A, B, T;
	int i;
	long int n;
	
	scanf("%d", &T);
	
	for (i = 0; i < T; i++)
	{
		scanf("%d %d", &A, &B);
		
		long int ans = 0;
		for (n = A; n <= B; n++)
		{
			m.clear();
			ans += good_pairs(n, B);
		}

		printf("Case #%d: %ld\n", i+1, ans);
	}
	
	return 0;
}