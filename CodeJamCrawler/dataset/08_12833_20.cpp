#include <iostream>
using namespace std;

int area (int a, int b, int c, int d, int e, int f) {

  return abs(a*d-c*b+c*f-e*d+e*b-a*f);
}

int main () {

  int C, c = 0, N, M, A;
  scanf("%d", &C);
  while (C--) {
    scanf("%d %d %d", &N, &M, &A);
    //printf("%d\n", A);
    bool ok = false;
    for (int i = 0; i <= N && !ok; ++i) {
      for (int j = 0; j <= M && !ok; ++j) {
	for (int k = 0; k <= N && !ok; ++k) {
	  int mi = 0;
	  int ma = M;
	  int t = (i == 0 ? 0 : k*j/i);
	  while (ma-mi > 1) {
	    int mid = (mi+ma)/2;
	    int a = area(0, 0, i, j, k, mid);
	    //printf("area(%d,%d,%d,%d,%d,%d) = %d\n", 0, 0, i, j, k, mid, a);
	    if (a == A) {
	      printf("Case #%d: %d %d %d %d %d %d\n", ++c, 0, 0, i, j, k, mid);
	      ok = true;
	      break;
	    }
	    if (a > A) {
	      if (mid > t)
		ma = mid;
	      else
		mi = mid;
	    }
	    else {
	      if (mid > t)
		mi = mid;
	      else
		ma = mid;
	    }
	  }
	  if (ok)
	    break;
	  if (A == area(0, 0, i, j, k, mi)) {
	    printf("Case #%d: %d %d %d %d %d %d\n", ++c, 0, 0, i, j, k, mi);
	    ok = true;
	    break;
	  }
	  if (A == area(0, 0, i, j, k, ma)) {
	    printf("Case #%d: %d %d %d %d %d %d\n", ++c, 0, 0, i, j, k, ma);
	    ok = true;
	    break;
	  }
	}
      }
    }
    if (!ok)
      printf("Case #%d: IMPOSSIBLE\n", ++c);
  }
}
