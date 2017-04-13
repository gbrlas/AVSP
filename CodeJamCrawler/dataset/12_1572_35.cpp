#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char line[1024];

#define MAX_N 100
int points[MAX_N];

static int
sol(int N, int S, int p)
{
  int i, res, amb;

  int min = p + (p - 2) + (p - 2);
  int max = p + (p - 1) + (p - 1);

  res = 0;
  amb = 0;

  for (i = 0; i < N; i++) {
    switch(p) {
      case 0:
        ++res;
        break;
      case 1:
        if (points[i] > 0)
          ++res;
        break;
      default:
        assert(min >= 0);
        if (max <= points[i])
          ++res;
        else if (min <= points[i] && S > 0) {
          --S;
          ++res;
        }
        break;
    }
  }

  return res;
}

int
main(int argc, char **argv)
{
  FILE *fp;
  int i, T;

  if (argc != 2)
    return 1;

  fp = fopen(argv[1], "r");
  if (!fp) {
    perror(argv[1]);
    return 1;
  }

  i = 0;
  fscanf(fp, "%d", &T);

  while (T--) {

    int j;
    int N, S, p;

    fscanf(fp, "%d %d %d", &N, &S, &p);
    for (j = 0; j < N; j++)
      fscanf(fp, "%d", &points[j]);

    printf("Case #%d: %d\n", ++i, sol(N, S, p));
  }
  if (ferror(fp)) {
    perror("fgets");
    return 1;
  }

  return 0;
}
