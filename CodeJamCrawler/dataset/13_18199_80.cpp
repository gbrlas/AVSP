#include "stdio.h"

#define N	10
#define M	10

int nTests,n,m;
int arr[N][M], arr2[N][M];
int an[N], am[M];

const char *const res [] = {"YES", "NO"};

int solve(void)
{
	int i,j;

	// Get Max M Values
	for(j=0 ; j<m ; ++j)
	{
		int l=0;
		for(i=0 ; i<n ; ++i)
		{
			if(l<arr[i][j])	l=arr[i][j];
		}
		am[j] = l;
	}

	// Fill with init values
	for(i=0 ; i<n ; ++i)
	{
		for(j=0 ; j<m ; ++j)
			arr2[i][j] = an[i];
	}

	for(j=0 ; j<m ; ++j)
	{
		for(i=0 ; i<n ; ++i)
		{
			if(arr2[i][j] > am[j])
				arr2[i][j] = am[j];
		}
	}
	
	for(i=0 ; i<n ; ++i)
	{
		for(j=0 ; j<m ; ++j)
			if(arr[i][j] != arr2[i][j])
				return 1;
	}
	
	
	return 0;
}

int main(void)
{
	int cTest,i,j;

	scanf("%d\n", &nTests);

	for(cTest=1 ; cTest<=nTests ; ++cTest)
	{
		scanf("%d %d\n", &n, &m);
		for(i=0 ; i<n ; ++i)
		{
			// Calculate Max N here itself
			int l=0;
			int * ptr = arr[i];

			for(j=0 ; j<m ; ++j)
			{
				int val;
				scanf("%d", &val);
				ptr[j] = val;
				if(l<val)	l=val;
			}
			
			an[i] = l;
		}

		i=solve();
		
		printf("Case #%d: %s\n", cTest, res[i]);
	}
	
	return 0;
}
