#include <cstdio>
#include <cstring>
char inp[105][105];
double WP[105], OWP[105], OWPP[105], RPI[105];
inline void solve(const int &tc) {
	memset(RPI, 0, sizeof RPI);
	memset(WP, 0, sizeof WP);
	memset(OWP, 0, sizeof OWP);
	memset(OWPP, 0, sizeof OWPP);
	int N, i, j, k;
	scanf("%d%*c", &N);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%c", &inp[i][j]);
		}
		scanf("%*c");
	}
	//puts("zz");
	for (i = 0; i < N; i++) {
		int jwin, tot;
		jwin = tot = 0;
		for (j = 0; j < N; j++) {
			if (inp[i][j] == '1')
				jwin++,tot++;
			else if (inp[i][j] == '0')
				tot++;
		}
		WP[i] = (double)jwin / (double)tot;
		//printf("WP[i] = %.6lf\n", WP[i]);
	}
	for (i = 0; i < N; i++) {
		double tott = 0;
		double jtim = 0;
		for (j = 0; j < N; j++) {
			if (inp[i][j] == '.')
				continue;
			jtim++;
			int jwin, tot;
			jwin = tot = 0;
			for (k = 0; k < N; k++) {
				if (k == i)
					continue;
				if (inp[j][k] == '1')
					jwin++, tot++;
				else if (inp[j][k] == '0')
					tot++;
			}
			tott += (double)jwin / (double)tot;
		}
		OWP[i] = tott / jtim;
		//printf("OWP[i] = %.6lf\n", OWP[i]);
	}
	for (i = 0; i < N; i++) {
		OWPP[i] = 0;
		int tot = 0;
		for (j = 0; j < N; j++) {
			if (inp[i][j] != '.') {
				OWPP[i] += OWP[j];
				tot++;
			}
		}
		OWPP[i] /= (double)tot;
		//printf("OWPP[i] = %.6lf\n", OWPP[i]);
	}
	printf("Case #%d:\n", tc+1);
	for (i = 0; i < N; i++) {
		RPI[i] = 0.25 * WP[i] + 0.50 * OWP[i] + 0.25 * OWPP[i];
		printf("%.12lf\n", RPI[i]);
	}
}
int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
		solve(i);
	return 0;
}
