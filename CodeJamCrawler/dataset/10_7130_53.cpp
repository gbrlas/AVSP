#include <stdio.h>

int main(int argc, char *argv[])
{
	unsigned long long R;
	unsigned long long k;
	int N;
	int nr_of_tc;
	int i;

	scanf("%d", &nr_of_tc);
	for (i = 0; i < nr_of_tc; i ++) {
		scanf("%llu %llu %d", &R, &k, &N);

		{ // Let's play
			unsigned long long Q[N];
			register int j;
			unsigned long long price;
			unsigned long long tmp;
			unsigned int idx;
			for (j = 0; j < N; j ++) {
				scanf("%llu", Q + j);
			}

			idx = 0;
			price = 0;
			while (R -- > 0) {
				tmp = 0;
				j = 0;
				while (tmp + Q[idx] <= k && j < N) {
					tmp += Q[idx];
					idx = (idx + 1) % N;
					j ++;
				}
				price += tmp;
			}

			printf("Case #%d: %llu\n", i + 1, price);
		}
	}

	return 0;
}


// End of a file
