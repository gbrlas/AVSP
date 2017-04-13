#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {

    char mappings[26];
    mappings[0] = 'y'; // a
    mappings[1] = 'h'; // b
    mappings[2] = 'e'; // c
    mappings[3] = 's'; // d
    mappings[4] = 'o';
    mappings[5] = 'c';
    mappings[6] = 'v';
    mappings[7] = 'x';
    mappings[8] = 'd';
    mappings[9] = 'u';
    mappings[10] = 'i';
    mappings[11] = 'g';
    mappings[12] = 'l';
    mappings[13] = 'b';
    mappings[14] = 'k';
    mappings[15] = 'r';
    mappings[16] = 'z';
    mappings[17] = 't';
    mappings[18] = 'n';
    mappings[19] = 'w';
    mappings[20] = 'j';
    mappings[21] = 'p';
    mappings[22] = 'f';
    mappings[23] = 'm';
    mappings[24] = 'a';
    mappings[25] = 'q';

    int dobreak = 0;
    
    int N;
    scanf("%d *[^\n]", &N);
    int i;
    for (i = 0; i < N; i++) {

	char line[LINE_MAX];
	// Check fgets succeeds
	if (fgets(line, LINE_MAX, stdin) != NULL) {

	    printf("Case #%d: ", i+1);
	    
	    int j;
	    for (j = 0; j < LINE_MAX; j++) {

		if (line[j] == ' ') {
		    printf(" ");
		}

		else if (line[j] == '\n') {
		    break;
		}

		else {
		    int x = line[j];
		    x -= 97;
		    printf("%c", mappings[x]);
		}
		
	    }
	    
	}

	printf("\n");
    }

    return 0;
}
