#include <stdio.h>
#include <stdlib.h>

int lawn[100][100];
int valid[100][100];

int main () {
	int T, flag;
	int M, N;
	int max;

	FILE *ifp, *ofp;
	ifp = fopen("B-small-attempt0.in", "r");
	ofp = fopen("output.txt", "w");

	//scanf("%d", &T);
	fscanf(ifp, "%d", &T);

	for (int caseNum = 1; caseNum <= T; caseNum++) {
		flag = 1;

		//scanf("%d %d", &M, &N);
		fscanf(ifp, "%d %d", &M, &N);

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				//scanf("%d", &lawn[i][j]);
				fscanf(ifp, "%d", &lawn[i][j]);

				valid[i][j] = 0;
			}
		}

		/*******/
		for (int i = 0; i < M; i++) {
			max = lawn[i][0];
			for (int j = 1; j < N; j++) {
				max = lawn[i][j] > max ? lawn[i][j]:max;
			}

			for (int j = 0; j < N; j++) {
				if (lawn[i][j] == max) valid[i][j] = 1;
			}
		}

		for (int j = 0; j < N; j++) {
			max = lawn[0][j];
			for (int i = 1; i < M; i++) {
				max = lawn[i][j] > max ? lawn[i][j]:max;
			}

			for (int i = 0; i < M; i++) {
				if (lawn[i][j] == max) valid[i][j] = 1;
			}
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				flag = flag && valid[i][j];
			}
		}
		/*******/

		//printf("Case #%d: ", caseNum);
		//if (flag) printf("YES\n");
		//else printf("NO\n");

		fprintf(ofp, "Case #%d: ", caseNum);
		if (flag) fprintf(ofp, "YES\n");
		else fprintf(ofp, "NO\n");
	}

	return 0;
}