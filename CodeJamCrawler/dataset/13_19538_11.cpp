#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

#define Pi 3.1415926535897932384626433832795

typedef struct _data *Data;

typedef struct _data {
	double curPaint;
	double curRadius;

	int buffer;
} data;

int getOutput(Data d);
Data createData(void);

int main(int argc, char *argv[]) {
	int numCases, curCase;
	Data d = createData();

	d->buffer = scanf("%d\n", &numCases);
	for (curCase = 1; curCase <= numCases; curCase++) {
		d->buffer = scanf("%lf", &(d->curRadius));
		d->buffer = scanf("%lf", &(d->curPaint));
		printf("Case #%d: %d\n", curCase, getOutput(d));
	}
	return 0;
}

int getOutput(Data d) {
	//d->curRadius *= 10;
	double curRingRequiredPaint;
	double numRings = 0;
	while (d->curPaint > 0) {
		curRingRequiredPaint = (d->curRadius+1)*(d->curRadius+1)-d->curRadius*d->curRadius;
		//printf("%lf\n", curRingRequiredPaint);
		if (curRingRequiredPaint <= d->curPaint) {
			numRings++;
			d->curPaint -= curRingRequiredPaint;
			d->curRadius += 2;
		} else {
			break;
		}
	}
	return numRings;
}

Data createData(void) {
	Data d = malloc(sizeof(data));	
	
	return d;
}
