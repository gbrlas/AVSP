#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
  int T;
  scanf("%d",&T);
  for(int cc = 1 ; cc <= T ; cc++){
    double rt = 2;
    double C,F,X;
    scanf("%lf %lf %lf",&C,&F,&X);
    double sol = X/rt;
    double ext = 0;
    while(ext < sol){
      ext += C/rt;
      rt += F;
      sol = min(sol,ext+X/rt);
    }
    printf("Case #%d: %.7lf\n",cc,sol);
  }
}
