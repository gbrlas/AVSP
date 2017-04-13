#include <stdio.h>
#include <strings.h>

#define MOD 1000

int
count(const char *target, int ntarget, const char *s, int len) 
{
  int i, nmatch = 0;

  if (len < ntarget) return 0;
  if (ntarget == 0) return 1;
  
  for (i = 0; i <= len - ntarget; i++) {
    if (s[i] == target[0]) {
      nmatch += count(target + 1, ntarget - 1, s + i + 1, len - i - 1);
      nmatch %= MOD;
    }
  }
  return nmatch;
}

int
main(int argc, char **argv)
{
  const char *target = "welcome to code jam";
  int ntarget;
  int ncases, i;
  char buffer[0x400];
  int bufferlen;

  if (argc >= 2) {
    target = argv[1];
  }
  ntarget = strlen(target);

  scanf("%d\n", &ncases);
  for (i = 0; i < ncases; i++) {
    fgets(buffer, sizeof(buffer), stdin);
    bufferlen = strlen(buffer);
    if (buffer[bufferlen - 1] == '\n') {
      buffer[--bufferlen] = 0;
    }
    printf("Case #%d: %04d\n", i + 1, 
	   count(target, ntarget, buffer, bufferlen));
  }
  return 0;
}
  

