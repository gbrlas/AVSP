#include <stdio.h>
#include <string.h>

#define SZ 1005

typedef struct {
	__int64 res, endind;
}info;

__int64 que[SZ], visited[SZ];
info arr[SZ];
__int64 r, k, n;

void ReturnRes(__int64 startind)
{
	__int64 j, m, res = 0;
	for(j = startind, m = 0; m < n; j = (j + 1) % n, m++)
	{
		if((res + que[j]) <= k)
			res += que[j];
		else	break;
	}
	arr[startind].res = res;
	arr[startind].endind = j;
}

int main()
{
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);

	__int64 i, j, startind, sum = 0, res, tcase, t, cyclelength, cyclestartind, cycleres, mod;

	scanf("%I64d",&t);

	for(tcase = 1; tcase <= t; tcase++)
	{
		scanf("%I64d %I64d %I64d",&r, &k, &n);
		for(i = 0; i < n; i++)
		{
			scanf(" %I64d",&que[i]);
			arr[i].res = -1;
			arr[i].endind = -1;
		}

		startind = 0;
		res = 0;
		memset(visited, -1, sizeof(visited));

		for(i = 0; i < n; i++)
			ReturnRes(i);

		for(i = 0; i < r; i++)
		{
			if(visited[startind] >= 0)
			{
				cyclelength = i+1 - visited[startind];
				cyclestartind = startind;
				break;
			}
			visited[startind] = i+1;
			res += arr[startind].res;
			startind = arr[startind].endind;
		}

		cycleres = 0;
		startind = cyclestartind;
		for(j = 0; j < cyclelength; j++)
		{
			cycleres += arr[startind].res;
			startind = arr[startind].endind;
		}

		res = res + ((r - i) / cyclelength * cycleres);
		mod = (r - i) % cyclelength;

		startind = cyclestartind;
		for(j = 0; j < mod; j++)
		{
			res += arr[startind].res;
			startind = arr[startind].endind;
		}
		
		printf("Case #%I64d: %I64d\n",tcase, res);

	}

	return 0;
}