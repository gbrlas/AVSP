#include <stdio.h>
#include <map>
#include <string.h>

using namespace std;

int main(void) {

  int t; scanf("%d\n", &t);

  for (int i = 0; i < t; i++) {
    char s[63];
    scanf("%s\n", s);

    map<char, int> bmap;

    char s0 = s[0];
    bmap[s0] = 1;
    int l = strlen(s);

    int j;
    for (j = 1; j < l && s[j] == s0; j++);
    if (j < l) bmap[s[j]] = 0;

    int base = 2;
    for (int k = j+1; k < l; k++)
      if (bmap.find(s[k]) == bmap.end()) {
	bmap[s[k]] = base;
	base++;
      }

    int n = 0;
    for (int j = 0; j < l; j++) {
      n *= base;
      n += bmap[s[j]];
    }
    
    printf("Case #%d: %d\n", i+1, n);
  }

  return 0;
}
