#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
  int tcase;
  scanf("%d", &tcase);
  for(int zz=0; zz<tcase; zz++) {
    ll n, m, A, ax, ay, bx, by;
    scanf("%Ld%Ld%Ld", &n, &m, &A);
    for(ax=1; ax<=n; ax++) for(ay=0; ay<=m; ay++)
			     for(bx=0; bx<=n; bx++) {
			       ll S = A +  ay*bx;
			       by = S / ax;
			       if(ax * by - ay * bx == A && by<=m) {
				 printf("Case #%d: %Ld %Ld %Ld %Ld %Ld %Ld\n", zz+1, 0LL, 0LL, ax, ay, bx, by);
				 goto end;
			       }
			     }
    printf("Case #%d: IMPOSSIBLE\n", zz+1);
  end: ;
  }
}
