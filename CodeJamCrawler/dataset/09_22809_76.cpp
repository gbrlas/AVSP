#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char t[] = "welcome to code jam";

#define L 19

int c[L] = { 0 };

#define BUFFER_SIZE      501
char buffer[BUFFER_SIZE] = { 0 };


int main ()
{
	int N = 0;
	scanf ("%d", &N);
	fgets (buffer, BUFFER_SIZE, stdin);
	
	for (int n = 0; n < N; n++) {
		for (int i = 0; i < L; i++) {
			c[i] = 0;
		}
		fgets (buffer, BUFFER_SIZE, stdin);
		for (int i = 0; buffer[i]; i++) {
			if (buffer[i] == 'w') {
				c[0]++;
				c[0] %= 10000;
			} else {
				for (int j = 1 ; j < L; j++) {
					if (buffer[i] == t[j]) {
						c[j] += c[j-1];
						c[j] %= 10000;
					}
				}
			}
		}
		char res[18] = { 0 };
		res[0] = '0' + c[18] / 1000;
		res[1] = '0' + (c[18] / 100) % 10;
		res[2] = '0' + (c[18] / 10) % 10;
		res[3] = '0' + c[18] % 10;
		printf ("Case #%d: %s\n", n+1, res);
	}
	return 0;
}