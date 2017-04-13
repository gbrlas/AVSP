#include <cstdio>

void go(int c) {
  int n, s, p; scanf("%d %d %d", &n, &s, &p);
  int mm = 0;
  for (int i = 0; i < n; i++) {
    int a; scanf("%d", &a);
    int x, y;
    if (a == 0) {
      x = 0; y = 0;
    } else if (a == 1) {
      x = 1; y = 1;
    } else if (a >= 28) {
      x = 10; y = 10;
    } else if (a % 3 == 0) {
      x = a/3; y = a/3+1;
    } else if (a % 3 == 1) {
      x = a/3+1; y = a/3+1;
    } else {
      x = a/3+1; y = a/3+2;
    }
    if (x >= p) {
      mm++; 
    } else {
      if (y >= p && s > 0) {
        mm++;
        s--;
      }
    }
  }
  printf("Case #%d: %d\n", c, mm);
}

int main() {
  int t; scanf("%d", &t);
  for (int i = 0; i < t; i++) go(i+1);
}
