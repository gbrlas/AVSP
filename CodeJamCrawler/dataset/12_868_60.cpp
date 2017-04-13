#include <cstdio>

//               "abcdefghijklmnopqrstuvwxyz";
char mapping[] = "ynficwlbkuomxsevzpdrjgthaq";

int main() {
  int inv[26];
  for (int i = 0; i < 26; i++) {
    inv[mapping[i]-'a'] = 'a'+i;
  }

  int t; scanf("%d ", &t);
  char ll[500];
  for (int i = 0; i < t; i++) {
    gets(ll);
    printf("Case #%d: ", i+1);
    for (int j = 0; ll[j]; j++) {
      if (ll[j] == ' ') printf(" ");
      else printf("%c", inv[ll[j]-'a']);
    }
    printf("\n");
  }
}
