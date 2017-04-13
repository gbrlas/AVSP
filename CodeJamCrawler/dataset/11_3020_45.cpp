#include <stdio.h>

#include <algorithm>
using std :: sort;

const int MAX_SIZE = 1010;

void print_ans (int size, int candy[], int n)
{
	int balance = candy[0];
	for (int i = 1; i < size; ++i)
		balance ^= candy[i];

	if (balance != 0)
	{
		printf ("Case #%d: NO\n", n);
	}
	else
	{
		for (int i = 1; i < size; ++i)
			balance ^= candy[i];
		int balance_l = candy[0];
		int i = 1;
		while (balance != balance_l)
		{
			balance ^= candy[i];
			balance_l ^= candy[i];
			++i;
		}
		int sum = 0;
		for (int j = i; j < size; ++j)
			sum += candy[j]; 

		printf ("Case #%d: %d\n", n, sum);
	}
}


int main ()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	int all = 0;
	scanf ("%d", &all);
	
	for (int i = 0; i < all; ++i)
	{
		int size = 0;
		scanf ("%d", &size);
		int candy[MAX_SIZE] = {};
		for (int i = 0; i < size; ++i)
			scanf ("%d", &candy[i]);
		
		sort (candy, candy + size);

		print_ans (size, candy, i + 1);
	}

	getchar ();
	getchar ();

	return 0;
}