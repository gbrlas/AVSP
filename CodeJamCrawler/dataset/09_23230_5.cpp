#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

#define MAXN 100
#define eps 1e-8

int cmp(double a, double b=0.0){
  if (a < b - eps) return -1;
  if (a > b + eps) return 1;
  return 0;
}

struct point {
   double x,y;
   point(double x = 0, double y = 0): x(x), y(y) {}
   point operator +(point q){ return point(x + q.x, y + q.y); }
   point operator -(point q){ return point(x - q.x, y - q.y); }
   point operator *(double t){ return point(x * t, y * t); }
   point operator /(double t){ return point(x / t, y / t); }
   double operator *(point q){ return x * q.x + y * q.y; }
   double operator %(point q){ return x * q.y - y * q.x; }
   int cmp(point q) const {
     if (int t = ::cmp(x, q.x)) return t;
     return ::cmp(y, q.y);
   }
   bool operator ==(point q) const { return cmp(q) == 0; }
   bool operator !=(point q) const { return cmp(q) != 0; }
   bool operator < (point q) const { return cmp(q) < 0; }
};
typedef pair<point, double> circle;


circle pl[MAXN];
int n;
vector<circle>p;
double norma(point v){ return hypot(v.x, v.y); }

int ccw(point a, point b, point c){ /* b-a em relacao a c-a */
  return cmp((b-a)%(c-a)); /* ccw=1 ; cw=-1 ; colinear=0 */
  /* equivalente a cmp(triarea(a,b,c)), mas evita divisao */
}
bool in_circle(circle C, point p){
  return cmp(norma(p - C.first), C.second) <= 0;
}

point circumcenter(point p, point q, point r) {
  point a = p - r, b = q - r,
    c = point(a * (p + r) / 2, b * (q + r) / 2);
  return point(c % point(a.y, b.y),point(a.x, b.x) % c) / (a % b);
}
double dist(point a, point b){
  return sqrt((a.x - b.x)*(a.x - b.x)+(a.y - b.y)*(a.y - b.y));
}

double cover2(circle a, circle b){
  return (dist(a.first, b.first) + a.second + b.second)/2.0;
}

double cover3(){

  if (n == 1){
    return pl[0].second;
  }
  if (n == 2){
    return max(pl[0].second, pl[1].second);
  }
  if (n == 3){
    
    double best = INFINITY;
    best = min(best, max(cover2(pl[0], pl[1]), pl[2].second));
    best = min(best, max(cover2(pl[0], pl[2]), pl[1].second));
    best = min(best, max(cover2(pl[2], pl[1]), pl[0].second));
    return best;
  }
  return 0;
}

int main (){

  int t, cases = 1;
  scanf("%d", &t);
  while(t--){

    scanf("%d", &n);
    for(int i=0; i<n; i++){
      scanf("%lf %lf %lf", &pl[i].first.x, &pl[i].first.y, &pl[i].second);     
    }
    double ans = cover3();
    printf("Case #%d: %.6lf\n", cases++, ans);

  }
  
  return 0;
}
