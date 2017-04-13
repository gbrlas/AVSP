#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 10000

long long T, A, B;
long long start_in[MAX], end_in[MAX];
long long data[MAX];
long long n_data;

void strrev(char *p)
{
  char *q = p;
  while(q && *q) ++q;
  for(--q; p < q; ++p, --q)
    *p = *p ^ *q,
    *q = *p ^ *q,
    *p = *p ^ *q;
}

int isPalindrome(long long x)
{
	char a[10000], b[10000];	
	sprintf(a,"%lld",x);
	strcpy(b, a);
	strrev(a);
	if (strcmp(a, b) == 0)
		return 1;
	else
		return 0;	
}

int main()
{
	freopen("C-large-1.in", "rt", stdin);
	freopen("C-large-1.out", "wt", stdout);
	
	long long count = 0;
	start_in[0] = 0;
	end_in[0] = 0;
	for (long long i = 1; i <= floor(sqrt(100000000000000)); i++)
	{
		if (isPalindrome(i))
		{
			long long sq = i*i;
			if (isPalindrome(sq))
			{
				++n_data;
				data[n_data] = data[n_data-1] + 1;
				end_in[n_data-1] = sq-1;
				start_in[n_data] = sq;
				end_in[n_data] = sq;
			}
		}
		end_in[n_data] = i*i;
	}
//	printf ("%lld\n\n", n_data);
//	for (int i = 0; i <= n_data; i++)
//		printf ("%lld-%lld :%lld\n", start_in[i], end_in[i], data[i]);
	scanf ("%lld", &T);
	for (long long t = 0; t < T; t++)
	{
		scanf ("%lld %lld", &A, &B);
		//printf ("%lld\n\n", B);
		
		long long out_a = -1, out_b = -1;
		for (int i = 0; i <= n_data; i++)
		{
			if (out_a == -1 && start_in[i] < A && A <= end_in[i]+1)
				out_a = data[i];
			if (out_b == -1 && start_in[i] <= B && B <= end_in[i])
			{
				out_b = data[i];	
				break;
			}
		}
		
		printf ("Case #%lld: %lld\n", t+1, out_b - out_a);
	}
	
	return 0;
}