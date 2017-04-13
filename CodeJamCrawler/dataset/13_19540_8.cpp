#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

#define MAX_LENGTH 100

typedef struct _data *Data;

typedef struct _data {
	char *name;
	char **subStrings;
	int n;
	int nValue;	

	char *curString;
	int buffer;
} data;

int getOutput(Data d);
Data createData(void);

int main(int argc, char *argv[]) {
	int numCases, curCase;
	Data d = createData();

	d->buffer = scanf("%d\n", &numCases);
	for (curCase = 1; curCase <= numCases; curCase++) {
		d->nValue = 0;
		d->buffer = scanf("%s", d->name);
		d->buffer = scanf("%d", &(d->n));
		printf("Case #%d: %d\n", curCase, getOutput(d)); 
	}
	return 0;
}

int getOutput(Data d) 
{
	int stringLength = strlen(d->name);
	int x, y;
	for (x = 0; x < 26; x++) {
		for (y = 0; y < 26; y++) {
			d->subStrings[x][y] = 0;
		}
	}
	for (x = 0; x < stringLength; x++) {
		for (y = stringLength-1; y >= x; y--) {
			if (containsSub(d, x, y)) {
				//printf("%d %d\n", x, y);
				d->nValue++;
				d->subStrings[d->name[x]-'a'][d->name[y]-'a'] = 1;
			}
		}
	} 
	return d->nValue;
}

int containsSub(Data d, int lo, int hi)
{
	//if (d->subStrings[d->name[lo]-'a'][d->name[hi]-'a']) return FALSE;
	int curConsecutive = 0;
	int x;
	for (x = lo; x <= hi; x++) {
		if (d->name[x] != 'a' && d->name[x] != 'e' && d->name[x] != 'i' && d->name[x] != 'o' && d->name[x] != 'u') {
			curConsecutive++;
		}
		else curConsecutive = 0;
		if (curConsecutive == d->n) return TRUE;
	}
	return FALSE;
}

Data createData(void) 
{
	Data d = malloc(sizeof(data));	
	d->name = malloc(sizeof(char)*MAX_LENGTH);
	d->subStrings = malloc(sizeof(char*)*26);
	int x;
	for (x = 0; x < 26; x++) {
		d->subStrings[x] = malloc(sizeof(char)*26);
	}
	return d;
}

