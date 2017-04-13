#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
int n;
int main(){
  int i,j;
  double k,t,c,f,x,r,s;
   freopen ("B-small-attempt0.in","r",stdin);
   freopen ("b.out","w",stdout);
    scanf("%d",&n);
    for( i = 1 ; i <= n ; i++ ){
      scanf("%lf%lf%lf",&c,&f,&x);
      r = k = x / 2;
      t = c / 2;
      s = 2;
      while( k <= r ){
        s += f;
        k =( x / s) + t;
        t = t + ( c / s );
        if( k < r )
          r = k;
      }
      printf("Case #%d: %.7lf\n",i,r);
    }
   fclose (stdout);
  return 0;
}
