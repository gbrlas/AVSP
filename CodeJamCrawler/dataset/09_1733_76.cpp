#include <stdio.h>

int N;
char *goal = "welcome to code jam";
char line[500];

int find(char *line, char *goal) {
  int found = 0;
  if (!*goal) return 1;
  while (*line && *line != '\n') {
    if (*line == *goal) {
      found = (found + find(line + 1, goal + 1)) % 10000;
    }
    line++;    
  }
  return found;
}    
    
int main() {
  int i;
  scanf("%d\n", &N);
  for (i = 0; i < N; i++) {
    fgets(line, 500, stdin);
    printf("Case #%d: %.4d\n", i + 1, find(line, goal));
  }    
  return 0;
}
