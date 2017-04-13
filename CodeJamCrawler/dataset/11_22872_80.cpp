#include <cstdio>
#include <algorithm>

using namespace std;

int T, N;
int arr[1000];

int main()
{
	freopen("C-large.in","r",stdin);
	freopen("C.out","w",stdout);
	scanf("%d",&T);
	int psum, sum;
	for (int i = 1; i <= T; i++)
	{
		scanf("%d",&N);
		psum = 0;
		sum = 0;
		for (int j = 0; j < N; j++)
		{
			scanf("%d",&arr[j]);
			psum ^= arr[j];
			sum += arr[j];
		}	

		if (psum)
			printf("Case #%d: NO\n", i);	
		else
		{
			sort(arr,arr+N);
			printf("Case #%d: %ld\n", i, sum - arr[0]);
		}
	}
	return 0;
}