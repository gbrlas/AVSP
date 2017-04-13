#include<iostream>
#include<cstdio>

using namespace std;

int main() {
  int T, i = 0;
  cin>>T;
  while(T--) {
    long double c, f, x;
    cin>>c>>f>>x;
    long double t = x/2, tprev = 0, r = 2;
    while(1) {
      tprev = t;
      r += f;
      t = t - x/(r - f) + c/(r - f) + x/r;
      if(t > tprev)
	break;
    }
    printf("Case #%d: %.7Lf\n", ++i, tprev);
  }
}
      
