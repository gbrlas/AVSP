#include <cstdio>
#include <cstring>

#define MAX 1<<20

int primes[MAX];
int used[MAX];
int numprimes;

void sieve() {
	for (int i=2; i<MAX; i++)
		if (!used[i]) {
			primes[numprimes++] = i;
			for (int j=i+i; j<MAX; j+=i)
				used[j]=1;
		}
}

int root[MAX];

int findroot(int a) {
	int curr=a;
	while (curr != root[curr])
		curr = root[curr];
	int tmp=a;
	while (tmp != curr) {
		int tt = root[tmp];
		root[tmp] = curr;
		tmp = tt;
	}
	return curr;
}

long long left[MAX];

long long a, b, p;

void doit(long long curr) {
	long long start = (a / curr) * curr;
	int prevr = -1;

	for (; start<=b; start+=curr)
		if (start >= a) {
			while (left[start-a] % curr == 0) left[start-a] /= curr;
			if (curr >= p) {
				int r = findroot(int(start-a));
				if (prevr != -1)
					root[r] = prevr;
				else
					prevr = r;
			}
		}
}

int main() {
	FILE *fin = fopen("in.txt", "r");
	FILE *fout = fopen("out.txt", "w");

	int tests;

	sieve();

	fscanf(fin, "%d", &tests);
	for (int test=0; test<tests; test++) {
		fscanf(fin, "%lld%lld%lld", &a, &b, &p);

		for (long long j=a; j<=b; j++) {
			root[j-a]=int(j-a);
			left[j-a]=j;
		}

		for (int j=0; j<numprimes; j++)
			doit(primes[j]);

		for (long long j=a; j<=b; j++)
			if (left[j-a] > 1) {
				doit(left[j-a]);
			}

		int result=0;
		for (long long j=a; j<=b; j++)
			if (root[j-a] == j-a)
				result++;

		fprintf(fout, "Case #%d: %ld\n", test+1, result);
	}

	return 0;
}
