#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <map>

using namespace std;

#define LMAX 20
#define DMAX 5005

int L, D, N, res;
char w[DMAX][LMAX];
bool p[LMAX][500];
char tmp[500];

int main() {
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
	scanf("%d%d%d", &L, &D, &N);
	for (int i=0; i<D; i++) scanf("%s", w[i]);
	for (int i=0; i<N; i++) {
		scanf("%s", tmp);
		int tmp_length = strlen(tmp);
		memset(p, 0, sizeof(p));
		res = 0;
		for (int j=0, k=0, open=false; j<tmp_length; j++) {
			if (tmp[j]=='(') open = true;
			if (tmp[j]==')') open = false;
			p[k][tmp[j]] = true;
			if (!open) k++;
		}
		// Solving this task.
		for (int j=0; j<D; j++) {
			bool correct = true;
			for (int k=0; k<L && correct; k++) {
				if (p[k][w[j][k]]==false) correct = false;
			}
			if (correct) res++;
		}
		printf("Case #%d: %d\n", i+1, res);
	}
	return 0;
}
