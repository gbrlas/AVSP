#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gi() {
  int a;
  scanf("%d\n", &a);
  return a;
}

int compchar(const void *a, const void *b) {
  char ca = *((char *) a);
  char cb = *((char *) b);
  return (ca < cb) ? -1 : (ca == cb ? 0 : 1);
}

int main() {
  int T = gi();
  int i, j;
  char buf[25];
  for (i = 0; i < T; i++) {
    fgets(buf, 23, stdin);
    for (j = 0; buf[j] != '\0' && buf[j] != '\n'; j++);
    if (buf[j] == '\n') buf[j] = '\0';
    do { 
      j--;
    } while (j > 0 && buf[j] <= buf[j - 1]);
    if (j == 0) {
      while (buf[j] != '\0') j++;
      buf[j] = '0';
      buf[j + 1] = '\0';
      qsort(buf, j + 1, sizeof (char), compchar);
      for (j = 0; buf[j]; j++) {
	if (buf[j] != '0') {
	  buf[0] = buf[j];
	  buf[j] = '0';
	  break;
	}
      }
    } else {
      char c;
      int k = j;
      int min = j;
      while (buf[k]) {
	if (buf[k] > buf[j - 1] && buf[k] < buf[min]) {
	  min = k;
	}
	k++;
      }
      c = buf[j - 1];
      buf[j - 1] = buf[min];
      buf[min] = c;
      qsort(buf + j, strlen(buf + j), sizeof (char), compchar);
    }
    printf("Case #%d: %s\n", i + 1, buf);
  }
  return 0;
}
