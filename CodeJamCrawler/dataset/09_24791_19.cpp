#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
#define EPS 1e-6
#define LIM 1000
#define MAX 2000

using namespace std;

set <int> s;
int C, N;
double pu;
double memo[MAX][LIM];

void montar (int se, int es, int p) {
	if (p == C && es < N)
		return;
	if (p == C) {
		s.insert (se);
		return;
	}
	if (es < N)
		montar (se | (1<<p), es + 1, p+1);
	montar (se, es, p+1);
}

double prob (int se, int q) {
	//printf ("%d %d\n", se, q);
	if (q >= LIM)
		return LIM;
	if (se + 1 == (1<<C))
		return q;
	if (memo[se][q] != -1)
		return memo[se][q];
	double resp = 0.0;
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
		resp += pu * (prob (se | (*it), q + 1));
	memo[se][q] = resp;
	//printf ("%d %d %lf\n", se, q, resp);
	return resp;
}

int main () {
	int T;
	scanf ("%d", &T);
	for (int test = 1; test <= T; test++) {
		s.clear();
		scanf ("%d%d", &C, &N);
		montar (0, 0, 0);
		for (int i = 0; i < (int) (1<<C); i++)
			for (int j = 0; j < LIM; j++)
				memo[i][j] = -1;
		pu = 1.0 / (double)s.size();
		printf ("Case #%d: %lf\n", test, prob (0, 0));
	}
	return 0;
}
