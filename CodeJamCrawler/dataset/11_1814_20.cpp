#include <stdio.h>

main()
{
	int T = 0, TC, N;
	int i, j, k, partidos[101], ganados[101];
	char puntos[101][101];
	double WP[101], OWP[101], OOWP[101], acum_WP, result;
	scanf("%d", &TC);
	while (T++ < TC) {
		scanf("%d", &N);
		for (i = 0; i < N; i++) {
			scanf("%s", puntos[i]);
			for (j = partidos[i] = ganados[i] = 0; j < N; j++)
				if (puntos[i][j] != '.') {
					partidos[i]++;
					if (puntos[i][j] == '1')
						ganados[i]++;
				}
			WP[i] = ((double)ganados[i])/partidos[i];
		}
		for (i = 0; i < N; i++) {
			for (j = acum_WP = 0; j < N; j++) {
				if (puntos[i][j] != '.') {
					if (puntos[i][j] == '0')
						result = ((double)ganados[j]-1)/(partidos[j]-1);
					else
						result = ((double)ganados[j])/(partidos[j]-1);
					acum_WP += result;
				}
			}
			OWP[i] = acum_WP/partidos[i];
		}
		for (i = 0; i < N; i++) {
			for (j = acum_WP = 0; j < N; j++) {
				if (puntos[i][j] != '.') {
					acum_WP += OWP[j];
				}
			}
			OOWP[i] = acum_WP/partidos[i];
		}
		printf("Case #%d:\n", T);
		for (i = 0; i < N; i++) {
			result = (0.25*WP[i]) + (0.50*OWP[i]) + (0.25*OOWP[i]);
			printf("%.12lf\n", result);
		}
	}
	return 0;
}

