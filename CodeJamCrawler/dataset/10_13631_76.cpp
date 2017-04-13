#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <stack>
#include <list>
#include <numeric>

#define pii pair<int,int>
#define FOR(i,n) for (int i = 1, _n = n; i <= _n; i++)
#define FOD(i,n) for (int i = n; i >= 0; i--)
#define MAXINT 1000000000

using namespace std;

int tc, n;
int A[1005], B[1005];

struct point{
   double x;
   double y;
   point (){}
   point (int a, int b){x = a; y = b;}
};

struct line{
   point p1;
   point p2;
   line (){}
   line (int a){
        p1 = point(0, A[a]);
        p2 = point(1, B[a]);
    }
};

double cross(point a, point b, point c){
   return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}

double dot(point a, point b, point c){
   return (b.x-a.x)*(c.x-a.x)+(b.y-a.y)*(c.y-a.y);
}

int dblcmp(double d){
   if (d > 0.000001)
      return 1;
   if (d < -0.000001)
      return -1;
   return 0;
}

int btwcmp(point a, point b, point c){
   return dblcmp(dot(a,b,c));
}

int intersect(line l1, line l2){
   double s1,s2,s3,s4;
   int d1,d2,d3,d4;
   s1 = cross(l1.p1,l1.p2,l2.p1);
   s2 = cross(l1.p1,l1.p2,l2.p2);
   s3 = cross(l2.p1,l2.p2,l1.p1);
   s4 = cross(l2.p1,l2.p2,l1.p2);
   d1 = dblcmp(s1); d2 = dblcmp(s2); d3 = dblcmp(s3); d4 = dblcmp(s4);
   if (d1*d2<0 && d3*d4<0){
      return 1;
   }
   if ((d1 == 0 && btwcmp(l2.p1,l1.p1,l1.p2)<=0) ||
      (d2 == 0 && btwcmp(l2.p2,l1.p1,l1.p2)<=0) ||
      (d3 == 0 && btwcmp(l1.p1,l2.p1,l2.p2)<=0) ||
      (d4 == 0 && btwcmp(l1.p2,l2.p1,l2.p2)<=0))
      return 1;
   return 0;
}


int main(){
    freopen("A-large.in","r",stdin);
    //freopen("input.txt","r",stdin);
    scanf("%d",&tc);
    for (int TC = 1; TC <= tc; TC++){
        int ans = 0;
        scanf("%d ",&n);
        for (int i = 0; i < n; i++){
            scanf("%d %d",&A[i], &B[i]);
        }
        for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++){
            if (intersect(line(i),line(j))) ans++;
        }
        printf("Case #%d: %d\n",TC,ans);
    }
    return 0;
}
