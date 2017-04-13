#include <stdio.h>
#include <math.h>

main()
{
	int TC, T = 0, N, i, j;
	int poso, posb, movs, libreso, libresb, boton, pasos;
	char robot[2];
	scanf("%d", &TC);
	while (T++ < TC) {
		scanf("%d", &N);
		poso = posb = 1;
		libreso = libresb = 0;
		movs = 0;
		for (i = 0; i < N; i++) {
			scanf("%s %d", robot, &boton);
			if (robot[0] == 'O') {
				pasos = abs(boton-poso);
				if (libreso > pasos)
					pasos = 0;
				else
					pasos = pasos - libreso;
				movs += pasos+1;
				libreso = 0;
				libresb += pasos+1;
				poso = boton;
			} else {
				pasos = abs(boton-posb);
				if (libresb > pasos)
					pasos = 0;
				else
					pasos = pasos-libresb;
				movs += pasos+1;
				libresb = 0;
				libreso += pasos+1;
				posb = boton;
			}
		}
		printf("Case #%d: %d\n", T, movs);
	}
	return 0;
}

