#include <stdio.h>

long t, h, w;
long map[200][200];
char ans[200][200];
char c;

char water(long j, long k) {
  long jj = j, kk = k;
  long smallest = map[j][k];
  if (ans[j][k] != 0) return ans[j][k];

  if (j > 0 && map[j-1][k] < smallest ) {
    jj = j -1;
    kk = k;
    smallest = map[j-1][k];
  }
  
  if (k > 0 && map[j][k-1] < smallest) {
    kk = k -1;
    jj = j;
    smallest = map[j][k-1];
  }

  if (k < w-1 && map[j][k+1] < smallest) {
    kk = k +1;
    jj = j;
    smallest = map[j][k+1];
  }

  if (j < h-1 && map[j+1][k] < smallest) {
    jj = j +1;
    kk = k;
    smallest = map[j+1][k];
  }

  if (smallest == map[j][k]) {
    ans[j][k] = c++;
  }

  if (ans[jj][kk] == 0) ans[j][k] = water(jj,kk);
  else ans[j][k] = ans[jj][kk];
  return ans[j][k];
}

void print() {
long j, k;
for (j=0;j<h;j++) {
  for (k=0;k<w;k++) {
    if (k > 0) printf(" ");
    printf("%c", ans[j][k]);
  }
  printf("\n");
}
}

int main() {
  long i,j,k;
  scanf("%ld", &t);
  for (i=0;i<t;i++) {
    scanf("%ld %ld", &h, &w);
    for (j=0;j<h;j++) {
      for(k=0;k<w;k++) {
        scanf("%ld", &map[j][k]);
        ans[j][k] = 0;
      }
    }

    c = 'a';
    for (j=0;j<h;j++) {
      for (k=0;k<w;k++) {
        if (ans[j][k] == 0);
          water(j,k);
      }
    }

    printf("Case #%ld:\n", i+1);
    print();
  }
  return 0;
}
