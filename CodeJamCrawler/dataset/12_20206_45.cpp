#include <stdio.h>

#define FORN(i, t) for(i = 1; i<=t; ++i)
#define READFROMFILE 1
#define WRITEFILE 1

void solve(int casenum);

int main()
{
	int i, n;

#if READFROMFILE
	freopen("input.txt", "r", stdin);
#endif

#if WRITEFILE
	freopen("output.txt", "w", stdout);
#endif

	scanf("%d\n", &n);

	FORN(i, n)
	{
		solve(i);
	}

	return 0;
}


void solve(int casenum)
{
	int n, s, p;
	int count = 0, norm_min, sup_min;
	scanf("%d %d %d", &n, &s, &p);

	norm_min = p * 3 - 2;
	sup_min = p * 3 - 4;

	while(n > 0)
	{
		int num;
		scanf("%d", &num);

		if(num >= norm_min)
		{
			++count;
		}
		else if(num >= sup_min && num > 0 && s > 0)
		{
			--s;
			++count;
		}
		--n;
	}

	printf("Case #%d: %d\n", casenum, count);

}