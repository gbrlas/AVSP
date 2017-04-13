#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int 
main(int argc, char **argv)
{
  FILE *input;
  int L, D, N;
  char words[5000][16];
  int test[5000];
  int line;
  int count;
  char c;
  int iter;
  int tally;

  memset(words, 0, sizeof(words));
  memset(test, 0, sizeof(test));

  if (argc < 2) {
    return(-1);
  }

  input = fopen(argv[1], "r");
  if (!input) {
    return(-2);
  }
  
  fscanf(input,"%d %d %d\n", &L, &D, &N);
  
  for(line = 0; line < D; line++) {
    memset(words[line], 0, (L + 1) * sizeof(char));
    fscanf(input, "%s\n", words[line]);
  }
  
  for(line = 0; line < N; line++) {
    for(iter = 0; iter < D; iter++) {
      test[iter] = 1;
    }
    count = 0;

    while('\n' != (c = fgetc(input))) {
      if(c == '(') {
	
	for(iter = 0; iter < D; iter++) {
	  test[iter] *= -1;
	}

	while(')' != (c = fgetc(input))) {
	  for(iter = 0; iter < D; iter++) {
	    if((words[iter][count] == c) && (test[iter])) {
	      test[iter] = 1;
	    }
	  }
	}

	for(iter = 0; iter < D; iter++) {
	  if(test[iter] != 1) {
	    test[iter] = 0;
	  }
	}
       
	count++;
      }
      else {
	for(iter = 0; iter < D; iter++) {
	  if(words[iter][count] != c) {
	    test[iter] = 0;
	  }
	}
	count++;
      }
    }

    tally = 0;
    for(iter = 0; iter < D; iter++) {
      if(test[iter] > 0) {
	tally++;
      }
    }
    printf("Case #%d: %d\n", line + 1, tally);
  }

  return 0;
}
