#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>

#define EPS 1e-7
using namespace std;

char w[11][11];

int main(){
  int T,R,C,D,res;
  double cx,cy;
  scanf("%d",&T);
  for(int cas=1;cas<=T;cas++){
    res=-1;
    scanf("%d%d%d",&R,&C,&D);
    for(int i=0;i<R;i++){
        scanf("%s",w[i]);
    }
    //cx=(C-1)/2.0; cy=(R-1)/2.0;
    for(int sr=0;sr<R-2;sr++){
      for(int sc=0;sc<C-2;sc++){
        for(int er=sr+2,ec=sc+2;er<R && ec<C;er++,ec++){
          double sx=0,sy=0,sm=0;
          //printf("%d %d %d %d\n",sr,sc,er,ec);
          for(int i=sr;i<=er;i++){
            for(int j=sc;j<=ec;j++){
              if(i==sr && (j==sc || j==ec)) continue;
              if(i==er && (j==sc || j==ec)) continue;
              sy += ((D+(w[i][j]-'0'))*(i));
              sx += ((D+(w[i][j]-'0'))*(j));
              sm += (D+(w[i][j]-'0'));
            }
          }
          cy = sr + (er-sr)/2.0;
          cx = sc + (ec-sc)/2.0;
          sx /= sm;
          sy /= sm;
          //printf("%lf %lf %lf %lf\n",sx,sy,cx,cy);
          if( fabs(sx-cx)<EPS && fabs(sy-cy)<EPS){
            res=max((er-sr+1),res);
          }
        }
      }
    }
    if(res==-1){
      printf("Case #%d: IMPOSSIBLE\n",cas);
    } else{
      printf("Case #%d: %d\n",cas,res);
    }
  }
  return 0;
}
