#include <stdio.h>
#include <iostream>

using namespace std;

typedef long long int i64;

struct Point {
  i64 x, y;
  Point (i64 x, i64 y): x(x), y(y) {};
  i64 operator% (Point a){ return x * a.y - y * a.x; }
};

i64 tri (Point a, Point b, Point c){
  return llabs(a % b + b % c + c % a);
}

int main (){

  i64 t, cases = 1, area, n, m;
  
  scanf("%lld",&t);
  
  while(t--){

    scanf("%lld %lld %lld", &n, &m, &area);

    printf("Case #%lld: ",cases++);

    for (i64 ix=0; ix<=n; ix++)
      for (i64 iy=0; iy<=m; iy++)
	for (i64 jx=0; jx<=n; jx++)
	  for (i64 jy=0; jy<=m; jy++){


	    if (area == tri(Point(0,0), Point(ix, iy), Point(jx, jy))){
	      printf("0 0 %lld %lld %lld %lld\n",ix,iy,jx,jy);
		goto saida;
	   }

	  }

    printf("IMPOSSIBLE\n");
  saida:;
    
  }
  
  return 0;
}
