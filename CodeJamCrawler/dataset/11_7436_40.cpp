#include <cstdio>
#include <vector>

using namespace std;

void solveCase()
{
	int L, H;
	int i,j, N;
	int freq[100];
	int valid;
	
	scanf("%d %d %d", &N, &L, &H);
	
	for (i=0; i<N; i++)
	{
		scanf("%d", &freq[i]);
	}
	
	for (i=L; i<=H; i++)
	{
		valid = 1;
		for (j=0; j<N && valid; j++)
		{
			if (freq[j] < i)
			{
				if (i % freq[j] != 0)
					valid = 0;
			}
			else
			{
				if (freq[j] % i != 0)
					valid = 0;
			}
		}
		if (valid)
		{
			printf("%d\n", i);
			return;
		}
	}
	printf("NO\n");
}

int main()
{
	int T, i;
	
	scanf("%d", &T);
	
	for (i=0; i<T; i++)
	{
		printf("Case #%d: ", i+1);
		solveCase();
	}
	
	return 0;
}
