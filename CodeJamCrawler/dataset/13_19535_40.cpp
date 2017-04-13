#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NUM_CHARACTERS 200

#define TRUE 1
#define FALSE 0

int isPalindrome(double number);
int getOutput(double min, double max);

int main(int argc, char *argv[]) {
	int numCases, curCase;
	double min, max;
	scanf("%d\n", &numCases);
	for (curCase = 1; curCase <= numCases; curCase++) {
		scanf("%lf", &min);
		scanf("%lf", &max);
		printf("Case #%d: %d\n", curCase, getOutput(min, max));
	}
	return 0;
}

int isPalindrome(double number) {
	char *num = malloc(sizeof(char)*MAX_NUM_CHARACTERS);
	sprintf(num, "%f", number);
	int i, len;
	len = strlen(num) - 7;
	for (i = 0; i < len/2; i++) {
		if (num[i] != num[len-i-1]) {
			free(num);
			return FALSE;
		}
	}
	free(num);
        return TRUE;
}

int getOutput(double min, double max) {
	double x = ceil(sqrt(min));
	int counter = 0;
	double square;
	while ((square = x*x) <= max) {
		if (isPalindrome(x)) {
			if (isPalindrome(square)) {
				counter++;
			}
		}
		x++;
	}
	return counter;
}

