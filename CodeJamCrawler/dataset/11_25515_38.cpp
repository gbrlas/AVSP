#include <iostream>
#include <iostream>
#include <iostream>

#include <stdio.h>

using namespace std;

#define MAXN 1234

struct point {
  double x, y;
  point(double _x=0.0, double _y=0.0) : x(_x), y(_y) {}; 
  point operator*(double c) { return point(x*c, y*c); }
  point operator/(double c) { return point(x/c, y/c); }
  point operator+(point q) { return point(x + q.x, y + q.y); }
  point operator-(point q) { return point(x - q.x, y - q.y); }
};

char b[MAXN][MAXN];
point pd[MAXN];
double w[MAXN];

int r, c, d;

#define eps 1e-6
int cmp(double a, double b){
  return a < b - eps ? -1 : a > b + eps ? 1 : 0; 
}

bool process2(int imin, int imax, int jmin, int jmax, point sum, double W){

  point target((imax + imin + 1)/2.0, (jmax + jmin + 1)/2.0);
  
  sum = sum - point(imin + 0.5, jmin + 0.5)*b[imin][jmin];
  sum = sum - point(imin + 0.5, jmax + 0.5)*b[imin][jmax];
  sum = sum - point(imax + 0.5, jmin + 0.5)*b[imax][jmin];
  sum = sum - point(imax + 0.5, jmax + 0.5)*b[imax][jmax];
  
  W -= b[imin][jmin];
  W -= b[imin][jmax];
  W -= b[imax][jmin];
  W -= b[imax][jmax];
  
  point center = sum / W;

  //printf("i[%d, %d] x j[%d, %d]\n", imin, imax, jmin, jmax);
  //printf("(%.9lf %.9lf) vs. (%.9lf, %.9lf)\n", center.x, center.y, target.x, target.y);  
  if (cmp(target.x, center.x)==0 && cmp(target.y, center.y)==0){
    return true;
  }
  return false;
}

bool process(int k, int imin, int imax){

  point sum(0, 0);
  double W = 0;
  // load k first cells
  for(int j=0; j<k; j++){
    sum = sum + pd[j];
    W += w[j];
  }

  //process
  if (process2(imin, imax, 0, k-1, sum, W))
    return true;

  for(int j=0; j+k<c; j++){
    sum = sum + pd[j+k];
    sum = sum - pd[j];
    W += w[j+k];
    W -= w[j];
    //process
    if (process2(imin, imax, j+1, j+k, sum, W))
      return true;
  }
  return false;
}

int main (){

  int T;
  scanf("%d", &T);
  for(int cases=1; cases<=T; cases++){
    scanf("%d %d %d", &r, &c, &d);

    for(int i=0; i<r; i++){
      char s[MAXN];
      scanf("%s", s);
      for(int j=0; j<c; j++)
	b[i][j] = s[j]-'0' + d;
    }

    int maxk = min(r, c), bestk;
    bool found = false;
    
    for(int k=maxk; k >= 3; k--){
      
      //load k first lines
      for(int i=0; i<c; i++){
	pd[i] = point(0, 0);
	w[i] = 0;
      }

      for(int i = 0; i < k; i++)
	for(int j=0; j<c; j++){
	  pd[j] = pd[j] + point(i + .5, j + .5)*b[i][j];
	  w[j] += b[i][j];
	}

      //process
      if (process(k, 0, k-1)){
	found = true;
	bestk = k;
	break;
      }

      for(int i = 0; i+k < r; i++){
	//load new line
	for(int j=0; j<c; j++){
	  pd[j] = pd[j] + point(i + k + .5, j + .5)*b[i+k][j];
	  w[j] += b[i+k][j];
	}
	//remove old line
	for(int j=0; j<c; j++){
	  pd[j] = pd[j] - point(i + .5, j + .5)*b[i][j];
	  w[j] -= b[i][j];
	}
	//process
	if (process(k, i+1, i+k)){
	  found = true;
	  bestk = k;
	  break;
	}
      }
      if (found) break;
    }
    if (found)
      printf("Case #%d: %d\n", cases, bestk);
    else
      printf("Case #%d: IMPOSSIBLE\n", cases);
}

}
