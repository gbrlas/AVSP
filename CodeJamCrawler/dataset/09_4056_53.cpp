#include <stdio.h>
#include <string.h>

long n, len;
char line[1000];
char word[20] = "welcome to code jam";
long map[500][500];

long answer() {
  long k, l, a = 0, prev = 0;

  for (k = 0;k < len;k++) {
    if (line[k] == word[0]) {
      map[k][0] = 1;
    }else{
      map[k][0] = 0;
    }
  }
  for (l = 1;l < 20;l++) {
    prev = 0;
    for (k = 0;k < len;k++) {
      prev += map[k][l-1];

      if (line[k] == word[l]) {
        map[k][l] = prev;
      }else{
        map[k][l] = 0;
      }
    }
  }
  return prev;
}

int main() {
  long i,j,k;
  char c;
  scanf("%ld\n", &n);
  for (i=0;i<n;i++) {
    fgets(line, 1000, stdin);
    len = strlen(line);

    printf("Case #%ld: %04ld\n", i+1, answer());
  }
  return 0;
}
