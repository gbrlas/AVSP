#include <stdio.h>

void solve() {
  int a, ra[4], b, rb[4];
  char dummy[100];

  scanf("%d\n", &a);
  for (int i = 1; i != a; i++) {
    fgets(dummy, sizeof(dummy), stdin);
  }
  scanf("%d %d %d %d\n", &ra[0], &ra[1], &ra[2], &ra[3]);
  for (int i = a+1; i <= 4; i++) {
    fgets(dummy, sizeof(dummy), stdin);
  }
  scanf("%d\n", &b);
  for (int i = 1; i != b; i++) {
    fgets(dummy, sizeof(dummy), stdin);
  }
  scanf("%d %d %d %d\n", &rb[0], &rb[1], &rb[2], &rb[3]);
  for (int i = b+1; i <= 4; i++) {
    fgets(dummy, sizeof(dummy), stdin);
  }

  int match=0;
  int matches=0;
  for (int i=0; i<4; i++) {
    for (int j=0; j<4; j++) {
      if (ra[i] == rb[j]) {
	match=ra[i];
	matches++;
      }
    }
  }
  if (matches == 1) {
    printf("%d\n", match);
  } else if (matches > 1) {
    printf("Bad magician!\n");
  } else {
    printf("Volunteer cheated!\n");
  }
}

int main() {
  int t;
  scanf("%d\n", &t);
  for (int i = 1; i <= t; i++) {
    printf("Case #%d: ", i);
    solve();
  }
}
