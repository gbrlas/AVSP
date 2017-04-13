/**** Google Jam Alien Language program ****/

#include <stdio.h>
#define SIZE 10000

int l, 
    d,
    n,
    i,			/*loop counter*/
    j,			/*loop counter*/ 
    k,                  /*loop counter*/ 
    whileCounter, 	/*Counter inside do while*/
    tc,			/*Test Case Counter*/
    casex;		/*Output variable*/

char words[SIZE][SIZE] = {{0,0}};
char patners[SIZE] = {0};
char cases[5001] = {0};

int main( void ) {

	scanf("%d%d%d", &l, &d, &n);

	for(i=0; i<d; i++) {
		for(j=0; j<l; j++) {
			scanf(" %c", &words[i][j]); 
		}
	}

	tc = 1;

	while(n--) {
		for(j=0; j<d; j++) {
			cases[j] = 0;
		}

		for(j=0; j<l; j++) {
			scanf(" %c", &patners[j]);
			if(patners[j] == '(') {
				whileCounter = j;
				do {
					whileCounter++;
					scanf(" %c", &patners[whileCounter]);
					for(k=0; k<d; k++) {
						if(patners[whileCounter] == words[k][j]) {
							cases[k]++;
						}
					}
				} while (patners[whileCounter] != ')');	
			} else {
				for(k=0; k<d; k++) {
					if(patners[j] == words[k][j]) {
						cases[k]++;
					}
				}
			}
		}
		casex = 0;
		for(i=0; i<d; i++) {
			if(cases[i] == l)
				casex++;
		}
		printf("Case #%d: %d\n", tc++, casex);

	}

	return(0);
}
		        


	
		
	
				
		
