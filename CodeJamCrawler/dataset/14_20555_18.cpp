#include <stdio.h>

unsigned long long count_wins(unsigned A, unsigned B, unsigned K) {
  unsigned i,j;
  unsigned long long count = 0;
  for ( i = 0 ; i < A; i++) {
    for ( j = 0 ; j < B; j++) {
      if ((i & j) < K) {
	//printf("Counting A=%u, B=%u, K=%u\n",i,j,K);
	count++;
      }
    }
  }
  return count;
}

int main() {
  int num_cases, i;
  unsigned A, B, K;
  scanf("%d", &num_cases);
  for (i = 0; i < num_cases; ++i) {
    scanf("%u %u %u", &A, &B, &K);
    printf("Case #%d: %llu\n", i+1, count_wins(A,B,K));
  }
  return 0;
}
