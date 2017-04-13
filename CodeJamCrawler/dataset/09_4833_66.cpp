#include <stdio.h>

int l, d, n;

char words[5000][16];
int graph[15][26];

int main(void) {
  int i, j, k, count;

  scanf("%d %d %d\n", &l, &d, &n);

  for (i = 0; i < d; i++) {
    scanf("%s\n", words[i]);
  }

  for (i = 0; i < n; i++) {
    count = 0;
    for (j = 0; j < l; j++)
      for (k = 0; k < 26; k++)
	graph[j][k] = 0;

    for (j = 0; j < l; j++) {
      char c;
      scanf("%c", &c);
      if (c == '(') {
	while (scanf("%c", &c) && c != ')')
	  graph[j][c-'a'] = 1;
      } else {
	graph[j][c-'a'] = 1;
      }
      scanf("\n");
    }

    for (j = 0; j < d; j++) {
      int ok = 1;
      for (k = 0; k < l; k++)
	if (!graph[k][words[j][k]-'a']) {
	  ok = 0;
	  break;
	}
      if (ok) count++;
    }
    
    printf("Case #%d: %d\n", i+1, count);
  }

  return 0;
}
