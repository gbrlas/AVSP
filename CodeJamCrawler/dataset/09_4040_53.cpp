#include <stdio.h>

long l, d, n;
char array[10000][20];
char guess[20][10000];
char input[10000];
char string[10000];

long answer(long i) {
  long j = 0, a = 0, b = 0;
  string[i] = '\0';
  if (i == l) {
    for (j = 0;j < d;j++) {
      if (strncmp(string, array[j], l) == 0)
        return a + 1;
    }
    return a;
  }else if (i > 0){
    for (j=0;j<d;j++) {
      if (strncmp(string, array[j], i) == 0) {
        b = 1;
        break;
      }
    }
    if (!b) return 0;
  }
  j = 0;
  while (guess[i][j] != '\0') {
    string[i] = guess[i][j++];
    a += answer(i+1);
  }
  return a;
}

void process() {
  long i = 0;
  long c = 0;
  long j = 0;
  long k = 0;
  long a = 0;
  while (input[c] != '\0') {
    j = 0;
    if (input[c] == '(') {
      while (input[++c] != ')') {
        a = 0;
        for (k=0;k<d;k++) {
          if (input[c] == array[k][i]) {
             a = 1;
             break;
          }
        }
        if (a) guess[i][j++] = input[c];
      }
    }else{
      guess[i][j++] = input[c];
    }
    c++;
    guess[i++][j] = '\0';
  }
  guess[i][j] = '\0';
}

int main() {
  long i = 0;
  scanf("%ld %ld %ld", &l, &d, &n);
  for (i=0;i<d;i++) {
    scanf("%s", array[i]);
  }
  for (i=0;i<n;i++) {
    scanf("%s", input);
    process();
    printf("Case #%ld: %ld\n", i+1, answer(0));
  }
  return 0;
}
