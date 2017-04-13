#include <stdio.h>

int main(int argc, char *argv[])
{
	unsigned long long k;
	unsigned long long t;
	int n;
	int nr_of_tc;
	register int i;
	int state;
	long long u;

	fscanf(stdin, "%d\n", &nr_of_tc);

	for (i = 0; i < nr_of_tc; i ++) {
		fscanf(stdin, "%d %llu\n", &n, &k);

		state = 0;

		t = (0x01 << n);
		state = ((k+1) % t) == 0;

		printf("Case #%d: %s\n", i + 1, state ? "ON" : "OFF");
	}

	return 0;
}
