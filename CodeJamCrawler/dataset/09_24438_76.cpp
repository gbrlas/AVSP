#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

int
match(const char *pattern, const char *target)
{
  const char *p = pattern;
  const char *t = target;
  const char *q;

  while (*p && *t) {
    if (*p == '(') {
      q = strchr(++p, ')');
      if (q == NULL) {
	fprintf(stderr, "missing ')': %s\n", pattern);
	return 0;
      }
      if (!memchr(p, *t, q - p)) return 0;
      p = q + 1;
      t++;
    } else if (isalpha(*p)) {
      if (*p++ != *t++) return 0;
    } else {
      fprintf(stderr, "unexpected char: %c in %s\n", *p, pattern);
      return 0;
    }
  }
  if (*p || *t) return 0;
  return 1;
}

static int
test_match()
{
  printf("%d = 1\n", match("(ab)(bc)(ca)", "abc"));
  printf("%d = 0\n", match("(ab)(bc)(ca)", "dac"));
  printf("%d = 1\n", match("(ab)(bc)(ca)", "bcc"));
  printf("%d = 0\n", match("(ab)(bc)(ca)", "bad"));
  printf("%d = 1\n", match("(ab)b(ca)", "abc"));
  printf("%d = 1\n", match("(abc)(abc)(cac)", "bca"));
  printf("%d = 0\n", match("(zyx)bc", "abc"));
  return 0;
}

int
count(const char *pattern, char **words, int n_words)
{
  int i;
  int n_matches = 0;
  for (i = 0; i < n_words; i++) {
    if (match(pattern, words[i])) {
      n_matches++;
    }
  }
  return n_matches;
}

int
main()
{
  int n_letters, n_words, n_cases;
  char **words;
  int i;
  char buffer[0x400];

  if (scanf("%d %d %d", &n_letters, &n_words, &n_cases) != 3) {
    fprintf(stderr, "invalid input");
    return 1;
  }
  words = malloc(sizeof(*words) * n_words);

  for (i = 0; i < n_words; i++) {
    scanf("%s", buffer);
    if (strlen(buffer) != n_letters) {
      fprintf(stderr, "wrong word: %s\n", buffer);
      return 0;
    }
    words[i] = malloc(n_letters);
    memcpy(words[i], buffer, n_letters);
  }

  for (i = 0; i < n_cases; i++) {
    scanf("%s", buffer);
    printf("Case #%d: %d\n", i + 1, count(buffer, words, n_words));
  }
  return 0;
}
