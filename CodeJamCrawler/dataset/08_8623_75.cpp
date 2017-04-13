#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#define sq(x) ((x)*(x))
using namespace std;

const double PI = acos(-1.0);
double rFly, rRacquet, ring, band, space;

void read(){
  cin >> rFly >> rRacquet >> ring >> band >> space;
}

double f(double v, double y){
  double a = rRacquet-rFly-ring;
  return v*sqrt(sq(a)-sq(v))/2 + sq(a)/2*asin(v/a) - y*v;
}

double integral(double x1, double x2, double y){
  if(sq(x2)+sq(y)>sq(rRacquet-rFly-ring))
    x2 = sqrt(sq(rRacquet-rFly-ring)-sq(y));
  
  return f(x2,y)-f(x1,y);
}

void work(int cases){
  if(space<rFly*2 || rFly+ring>rRacquet){
    printf("Case #%d: %.6lf\n",cases,1.0);
    return;
  }

  double sum = 0;
  for(double X=band+rFly;X+rFly+ring<=rRacquet;X+=band*2+space)
    for(double Y=band+rFly;Y+rFly+ring<=rRacquet;Y+=band*2+space){
      if(sq(X)+sq(Y)>sq(rRacquet-rFly-ring)) break;
      double x1 = X, y1 = Y;
      double x2 = X+space-rFly*2;

      sum += integral(x1,x2,y1);
      
      y1 += space-rFly*2;
      
      if(sq(x1)+sq(y1)<=sq(rRacquet-rFly-ring))
        sum -= integral(x1,x2,y1);
    }
  sum *= 4;

  printf("Case #%d: %.6lf\n",cases,1-sum/(rRacquet*rRacquet*PI));
}

int main(){
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }

  return 0;
}
