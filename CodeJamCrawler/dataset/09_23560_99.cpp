#include <stdio.h>

#define WELCOME_LENGTH 19
char * welcome = "welcome to code jam";

int countWelcomes() {
	int counters[WELCOME_LENGTH], i, j;
	char input;
	
	for (i = 0; i < WELCOME_LENGTH; i++) {
		counters[i] = 0;
	}
	
	for(;;input = getchar()) {
		if (input == EOF || input == '\n') break;
		for (j = WELCOME_LENGTH-1; j >= 0; j--)	{
			if (welcome[j] == input) {
				counters[j] = (counters[j] + (j == 0 ? 1 : counters[j-1])) % 10000;
			}
		}
	}
	
	return counters[WELCOME_LENGTH-1];
}

int main() {
	int N = 0, i;
	
	scanf("%d", &N); getchar(); // Get rid of that newline
	for (i=1; i <= N; i++) {
		printf("Case #%d: %04d\n", i, countWelcomes());
	}
	
	return 0;
}