#include <stdio.h>
#include <malloc.h>

#define ORANGE 'O'
#define BLUE   'B'

int main() {
	FILE *large;
	FILE *large_out;

	int total_steps;		// RESPUESTA

	int btsO[100];		// botones naranja
	int currB = 0;	// posicion de la tarea a ejecutar
	int btsB[100];		// botones azul
	int currO = 0;

	int pblue = 0;   		// posicion actual azul
	int porange = 0;		// posicion actual naranja
	
	int pathLength;	// tamanio de la combinacion
	int *path;	// Combinacion de ejecucion

	int robot;		// robot que debe actuar en la posicion del CasePath...
	int currPos;	// actual posicion de ejecucion

	bool done_step;

	int testCases;
	int currTest = 0;

	large = fopen("large.in", "r");
	large_out = fopen("output", "w");

	fscanf(large, "%d", &testCases);

	while(currTest < testCases) {

		currB = 0;
		currO = 0;

		fscanf(large, "%d", &pathLength);
		path = (int *)malloc(sizeof(int) * testCases);

		int r = 0, bt = 0;
		for(int i = 0; i < pathLength; ++i) {
			fscanf(large, " %c %d", &r, &bt);
			path[i] = r;
			if(r == ORANGE) {
				btsO[currO] = bt;
				++currO;
			}
			else if (r == BLUE) {
				btsB[currB] = bt;
				++currB;
			}
		}

		total_steps = 0;
		currB = 0;
		currO = 0;
		currPos = 0;
		pblue = 1;
		porange = 1;

		while(currPos < pathLength) {
			robot = path[currPos];
			done_step = false;

			if(btsB[currB] == pblue) {
				if(robot == BLUE) {
					++currB;
					done_step = true;
				}
			}
			else if(btsB[currB] > pblue) {
				++pblue;
			} else {
				--pblue;
			}
		
			if(btsO[currO] == porange) {
				if(robot == ORANGE) {
					// PULSAR y pasar a siguiente boton en la ruta
					done_step = true;
					++currO;
				}
			}
			else if(btsO[currO] > porange) {
				++porange;
			} else {
				--porange;
			}

			if(done_step) ++currPos;

			++total_steps;
		}
		free(path);

		fprintf(large_out, "Case #%d: %d\n", currTest + 1, total_steps);
		currTest++;
	}

	fclose(large_out);
	fclose(large);
	return 0;
}
