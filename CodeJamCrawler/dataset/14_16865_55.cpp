#include<stdio.h>
#include<algorithm>
using namespace std;

double a[1100], b[1100];

void del(int idx, int n)
{
	int i;
	for(i = idx ; i < n-1 ; i++)
	{
		b[i] = b[i+1];
	}
}

int war(int n)
{
	int cnt = 0;
	int i, j;

	for(i = n-1 ; i >= 0 ; i--)
	{
		if(a[i] > b[i])
		{
			cnt++;
			del(0, n-(n-1-i));
		}
		else
		{
			for(j = 0 ; j <= i ; j++)
			{
				if(a[i] < b[j])
				{
					del(j, n-(n-1-i));
					break;
				}
			}
		}
	}

	return cnt;
}

int dewar(int n)
{
	int i;
	int cnt = 0;
	int idx = 0;
	for(i = 0 ; i < n ; i++)
	{
		if(a[i] > b[idx])
		{
			cnt++;
			idx++;
		}
	}
	return cnt;
}

int main(void)
{
	int t, n;
	int i, j;
	int cnt;
	int warRes, warRes2;

	scanf("%d", &t);

	for(i = 0 ; i < t ; i++)
	{
		cnt = 0;
		scanf("%d", &n);
		for(j = 0 ; j < n ; j++)
		{
			scanf("%lf", &a[j]);
		}
		sort(a, a+n);

		for(j = 0 ; j < n ; j++)
		{
			scanf("%lf", &b[j]);
		}
		sort(b, b+n);

		printf("Case #%d: %d ", i+1, dewar(n));
		printf("%d\n", war(n));
	}

	return 0;
}