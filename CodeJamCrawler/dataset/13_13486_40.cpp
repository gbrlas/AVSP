#include "stdio.h"

#include <cmath>

inline bool is_palindrome(int n)
{
	int num = n, r = 0;
	while (num > 0) {
		r = (r * 10) + (num % 10);
		num /= 10;
	}
	return n == r;
}

int solve(int start, int end)
{
	int res = 0;
	for (int i = start; i <= end; ++i) {
		double sqrt_res = sqrt(i);
		double floor_sqrt_res = floor(sqrt_res);
		if (sqrt_res == floor_sqrt_res && is_palindrome((int)sqrt_res) && is_palindrome(i)) {
			res++;
		}
	}
	return res;
}

int main(int argc, char* argv[])
{
	if (argc < 3) {
		fprintf(stderr, "Program requires 2 arguments, expected: %s infile outfile\n", argv[0]);
		return 1;
	}

	FILE* infile = fopen(argv[1], "r");
	if (infile == NULL) {
		fprintf(stderr, "Could not read infile: %s\n", argv[1]);
		return 1;
	}

	FILE* outfile = fopen(argv[2], "w");
	if (outfile == NULL) {
		fprintf(stderr, "Could not read outfile: %s\n", argv[2]);
		return 1;
	}

	int T;
	fscanf(infile, "%d", &T);
	for (int i = 1; i <= T; ++i) {
		int A, B;
		fscanf(infile, "%d%d", &A, &B);
		fprintf(outfile, "Case #%d: %d\n", i, solve(A, B));
	}

	fclose(outfile);
	fclose(infile);
	return 0;
}
