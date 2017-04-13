#include <stdio.h>
#include <stdlib.h>

void sort(int*, int);

int main(void)
{
	int T, n;
	int i, j;
	int *x, *y;
	int product;

	scanf("%d", &T);

	for (i = 0; i < T; ++i)
	{
		product = 0;

		scanf("%d", &n);
		x = malloc(n * sizeof(int));
		y = malloc(n * sizeof(int));
		for (j = 0; j < n; ++j)
		{
			scanf("%d", &x[j]);
		}
		for (j = 0; j < n; ++j)
		{
			scanf("%d", &y[j]);
		}

		sort(x, n);
		sort(y, n);

		for (j = 0; j < n; ++j)
		{
			product += x[j] * y[n-1-j];
		}

		printf("Case #%d: %d\n", i + 1, product);
	}


	return 0;
}

void sort(int* x, int n)
{
    int i, j;
    int temp;

    // bubble sort
    for (i = n - 1; i > 0; --i)
    {
        for (j = 0; j < i; ++j)
        {
            if (x[j] > x[j+1])
            {
                temp = x[j];
                x[j] = x[j+1];
                x[j+1] = temp;
            }
        }
    }

    return;
}