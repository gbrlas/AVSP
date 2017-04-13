#include <cstdio>
#include <cstring>

#define MAX 10000000

int v, m;
int val[10100];
int can[10100];
int result[10100][2];

int solve(int node, int tar) {
	if (result[node][tar])
		return result[node][tar]-1;

	if (node > (m-1)/2) {
		if (tar != val[node])
			return MAX;
		return 0;
	}

	int l[2], r[2];
	l[0] = solve(node*2, 0);
	l[1] = solve(node*2, 1);
	r[0] = solve(node*2+1, 0);
	r[1] = solve(node*2+1, 1);

	int best=MAX;

	// and
	if (val[node] == 1 || can[node]) {
		for (int i=0; i<2; i++)
			for (int j=0; j<2; j++)
				if ((i & j) == tar && l[i] < MAX && r[j] < MAX) {
					int cur = l[i] + r[j] + ((val[node]==1)?0:1);
					if (cur < best) best = cur;
				}
	}

	// or
	if (val[node] == 0 || can[node]) {
		for (int i=0; i<2; i++)
			for (int j=0; j<2; j++)
				if ((i | j) == tar && l[i] < MAX && r[j] < MAX) {
					int cur = l[i] + r[j] + ((val[node]==0)?0:1);
					if (cur < best) best = cur;
				}
	}

	result[node][tar]=best+1;
	return best;
}

int main() {
	FILE *fin = fopen("in.txt", "r");
	FILE *fout = fopen("out.txt", "w");

	int tests;

	fscanf(fin, "%d", &tests);
	for (int test=0; test<tests; test++) {
		fscanf(fin, "%d%d", &m, &v);

		for (int i=0; i<(m-1)/2; i++)
			fscanf(fin, "%d%d", val+i+1, can+i+1);
		for (int i=0; i<(m+1)/2; i++)
			fscanf(fin, "%d", val+i+(m-1)/2+1);

		memset(result, 0, sizeof(result));

		int sol = solve(1, v);
		if (sol >= MAX)
			fprintf(fout, "Case #%d: IMPOSSIBLE\n", test+1);
		else
			fprintf(fout, "Case #%d: %d\n", test+1, sol);

	}

	return 0;
}
