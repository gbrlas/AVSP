#include <cstdio>
#include <cstring>

long long result;
long long num[3][3];
long long used[3][3];

void recurse(int curr, int left) {
	if (left < 0) return;
	if (curr == 9) {
		if (left > 0) return;

		long long sumx=0, sumy=0;
		for (int i=0; i<9; i++) {
			sumx += used[i/3][i%3] * (i/3);
			sumy += used[i/3][i%3] * (i%3);
		}
		sumx %= 3;
		sumy %= 3;

		if (sumx == 0 && sumy == 0) {
			long long add = 1;
			for (int i=0; i<9; i++)
				if (used[i/3][i%3]==1)
					add *= num[i/3][i%3];
				else
					if (used[i/3][i%3]==2)
						add *= num[i/3][i%3] * (num[i/3][i%3]-1) / 2;
					else
						if (used[i/3][i%3]==3)
							add *= num[i/3][i%3] * (num[i/3][i%3]-1) * (num[i/3][i%3]-2) / 6;
			if (add > 0)
				result += add;
		}

		return;
	}
	used[curr/3][curr%3]=0;
	recurse(curr+1, left);

	used[curr/3][curr%3]=1;
	recurse(curr+1, left-1);

	used[curr/3][curr%3]=2;
	recurse(curr+1, left-2);

	used[curr/3][curr%3]=3;
	recurse(curr+1, left-3);
}

int main() {
	FILE *fin = fopen("in.txt", "r");
	FILE *fout = fopen("out.txt", "w");

	int tests;

	fscanf(fin, "%d", &tests);
	for (int test=0; test<tests; test++) {
		memset(num, 0, sizeof(num));
		memset(used, 0, sizeof(used));
		long long n, a, b, c, d, x0, y0, m;
		fscanf(fin, "%lld%lld%lld%lld%lld%lld%lld%lld", &n, &a, &b, &c, &d, &x0, &y0, &m);
		long long x=x0;
		long long y=y0;
		for (int j=0; j<n; j++) {
			num[x%3][y%3]++;

			x = (a*x + b) % m;
			y = (c*y + d) % m;
		}

		result=0;
		recurse(0, 3);

		fprintf(fout, "Case #%d: %lld\n", test+1, result);
	}

	return 0;
}
