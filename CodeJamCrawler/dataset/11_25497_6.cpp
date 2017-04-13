#include <stdio.h>
#include <algorithm>
using namespace std;

int main (){

  int t;
  scanf("%d", &t);
  for(int cases=1; cases<=t; cases++){
    int n, pd, pg;
    scanf("%d %d %d", &n, &pd, &pg);
  
    printf("Case #%d: ", cases);

    for(int d=1; d<=n; d++){
      if (d*pd % 100) continue;
      int wd = d*pd / 100;

      int g = d;
      int wg = wd, it = 0;
      while (it < n*1000){
	
	if (pg*g > wg*100){
	  wg++;
	  g++;
	}
	else if (pg*g < wg*100)
	  g++;
	else {
	  printf("Possible\n");
	  goto ok;
	}
	it++;
      }
    }
    printf("Broken\n");
  ok:;
  }
}
