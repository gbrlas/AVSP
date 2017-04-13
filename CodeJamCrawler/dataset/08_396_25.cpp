#include <cstdio>
#include <cstring>

int a, n, m;

int abs(int a) {
	if (a < 0) return -a;
	return a;
}

int min(int a, int b, int c) {
	if (a <= b && a <= c) return a;
	if (b <= a && b <= c) return b;
	return c;
}

bool check(int x1, int y1, int x2, int y2, int x3, int y3) {
	if (abs(x1-x2)>n) return false;
	if (abs(x1-x3)>n) return false;
	if (abs(x2-x3)>n) return false;
	if (abs(y1-y2)>m) return false;
	if (abs(y1-y3)>m) return false;
	if (abs(y2-y3)>m) return false;
	return true;
}

int main() {
	FILE *fin = fopen("in.txt", "r");
	FILE *fout = fopen("out.txt", "w");

	int tests;

	fscanf(fin, "%d", &tests);
	for (int test=0; test<tests; test++) {
		fscanf(fin, "%d%d%d", &n, &m, &a);

		int x1, x2, x3=0;
		int y1, y2, y3=0;
		bool found=false;

		for (x1=-n; x1<=n; x1++)
			for (y1=-m; y1<=m; y1++)
				for (x2=-n; x2<=n; x2++) {
					y2 = a + x2*y1;
					if (x1==0 || y2 % x1 == 0) {
						if (x1 != 0)	y2 /= x1;
						else {
							y2 = 0;
							if (-y1*x2!=a) continue;
						}
						if (check(x1, y1, x2, y2, x3, y3)) {
							found=true;

							int t = min(x1, x2, x3);
							if (t < 0) { x1-=t; x2-=t; x3-=t; }

							t=min(y1, y2, y3);
							if (t < 0) { y1-=t; y2-=t; y3-=t; }

							goto END;
						}
					}
				}
END:
		if (!found)
			fprintf(fout, "Case #%d: IMPOSSIBLE\n", test+1);
		else
			fprintf(fout, "Case #%d: %d %d %d %d %d %d\n", test+1, x1, y1, x2, y2, x3, y3);

	}

	return 0;
}
