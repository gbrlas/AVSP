#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 50000 + 100;

int n, val, limit;
int t[MAX_N], f[MAX_N][2];
#define AND 2
#define OR 4

void update(int & trgt, int left, int right)
{
	int sum = (left == -1 || right == -1) ? -1 : left + right;
	if (trgt == -1 || sum != -1 && sum < trgt)
		trgt = sum;
}

int solve(int x, int val)
{
	if (f[x][val] != -2)
		return f[x][val];

	// orig:
	f[x][val] = -1;	
	if (t[x] & AND)
	{
		if (val == 1)
			update(f[x][val], solve(x * 2 + 1, 1), solve(x * 2, 1));
		else
		{
			update(f[x][val], solve(x * 2 + 1, 0), solve(x * 2, 1));
			update(f[x][val], solve(x * 2 + 1, 0), solve(x * 2, 0));
			update(f[x][val], solve(x * 2 + 1, 1), solve(x * 2, 0));
		}
	}
	else
	{
		if (val == 1)
		{
			update(f[x][val], solve(x * 2 + 1, 0), solve(x * 2, 1));
			update(f[x][val], solve(x * 2 + 1, 1), solve(x * 2, 1));
			update(f[x][val], solve(x * 2 + 1, 1), solve(x * 2, 0));
		}
		else
			update(f[x][val], solve(x * 2 + 1, 0), solve(x * 2, 0));
	}
	if (t[x] & 1)
	{
		int result = -1;
		if (t[x] & OR)
		{
			if (val == 1)
				update(result, solve(x * 2 + 1, 1), solve(x * 2, 1));
			else
			{
				update(result, solve(x * 2 + 1, 0), solve(x * 2, 1));
				update(result, solve(x * 2 + 1, 0), solve(x * 2, 0));
				update(result, solve(x * 2 + 1, 1), solve(x * 2, 0));
			}
		}
		else
		{
			if (val == 1)
			{
				update(result, solve(x * 2 + 1, 0), solve(x * 2, 1));
				update(result, solve(x * 2 + 1, 1), solve(x * 2, 1));
				update(result, solve(x * 2 + 1, 1), solve(x * 2, 0));
			}
			else
				update(result, solve(x * 2 + 1, 0), solve(x * 2, 0));
		}
		update(f[x][val], result, 1);
	}
	return f[x][val];
}

int main()
{
	int cases;
	scanf("%d", &cases);
	for (int caseNo = 0; caseNo < cases; ++caseNo)
	{
		scanf("%d %d", &n, &val);
		limit = (n - 1) / 2; // 1..limit, limit + 1..n
		for (int i = 1, g, c; i <= limit; ++i)
		{
			scanf("%d %d", &g, &c);
			if (g == 1)
				t[i] = AND | c;
			else
				t[i] = OR | c;
		//	printf("t[%d] = %d\n", i, t[i]);
			f[i][0] = f[i][1] = -2;
		}
		for (int i = limit + 1, t0; i <= n; ++i)
		{
			scanf("%d", &t0);
			f[i][t0] = 0; f[i][1 - t0] = -1;
		//	printf("%d -> %d\n", i, t0);
		}
		int ans = solve(1, val);
		printf("Case #%d: ", caseNo + 1);
		if (ans == -1)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}

