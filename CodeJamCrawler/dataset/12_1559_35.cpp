#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

const char *src = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
const char *dst = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";

#define MAP_SZ 26
static int map[MAP_SZ];

static void
build_map()
{
  int i;

  assert(strlen(src) == strlen(dst));

  for (i = 0; i < strlen(src); i++) {

    if (isspace(src[i])) {
      assert(isspace(dst[i]));
      continue;
    }

    if (map[dst[i] - 'a'] != 0)
      assert(map[dst[i] - 'a'] == src[i]);
    map[dst[i] - 'a'] = src[i];
  }

  map['z' - 'a'] = 'q';
  map['q' - 'a'] = 'z';

  /*for (i = 0; i < MAP_SZ; i++) {
    printf("%c: %c\n", i + 'a', map[i]);
  }*/
}

char line[1024];

int
main(int argc, char **argv)
{
  FILE *fp;
  int i, T;

  if (argc != 2)
    return 1;

  build_map();

  fp = fopen(argv[1], "r");
  if (!fp) {
    perror(argv[1]);
    return 1;
  }

  i = 0;
  fscanf(fp, "%d\n", &T);

  while (fgets(line, sizeof(line), fp)) {

    int j;

    for (j = 0; j < strlen(line); ++j) {
      if (isspace(line[j]))
        continue;
      assert(line[j] - 'a' < MAP_SZ);
      line[j] = map[line[j] - 'a'];
    }

    printf("Case #%d: %s", ++i, line); 
    assert(T-- > 0);
  }
  if (ferror(fp)) {
    perror("fgets");
    return 1;
  }

  return 0;
}
