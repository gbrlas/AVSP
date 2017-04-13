#include <stdlib.h>
#include <stdio.h>

#define LL long long int

int possible(LL n, LL pd, LL pg) {
  LL d, w;
  w = pd;
  if(pd%2==0) w/=2;
  if(pd%4==0) w/=2;
  if(pd%5==0) w/=5;
  if(pd%25==0)w/=5;
  
  if(pd == 0) {
    if(pg == 100)
      return 0;
    else
      return 1;
  }
  
  d = (w * 100) / pd;
  //printf("d=%lld, w=%lld\n", d, w);
  
  if(d > n)
    return 0;
  
  if(pg == 0 && w == 0)      return 1;
  if(pg == 0 && w != 0)      return 0;
  if(pg == 100 && pd == 100) return 1;
  if(pg == 100 && pd != 100) return 0;
  
  return 1;
}

int main() {
	int ncases;
	scanf("%d", &ncases);
	for(int cas=1; cas <= ncases; cas++) {
	  LL n, pd, pg;
	  int answer;
	  scanf("%lld%lld%lld", &n, &pd, &pg);
	  answer = possible(n, pd, pg);
		printf("Case #%d: %s\n", cas, (answer?"Possible":"Broken"));
	}
	return 0;
}
