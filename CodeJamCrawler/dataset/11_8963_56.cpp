#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

void handlecase(){
  int x,s,r,t,n;
  scanf("%d%d%d%d%d",&x,&s,&r,&t,&n);
  int sp_l[101];
  sp_l[0]=x;
  fill(sp_l+1,sp_l+101,0);
  for(int i=0;i<n;i++){
    int bi,ei,wi;
    scanf("%d%d%d",&bi,&ei,&wi);
    sp_l[wi]+=ei-bi;
    sp_l[0]-=ei-bi;
  }
  double time=0.0;
  double run_t_left=t;
  for(int i=0;i<=100;i++){
    if(run_t_left>0.0){
      double time_i=sp_l[i]/(double)(i+r);
      if(time_i<run_t_left){
        time+=time_i;
        run_t_left-=time_i;
      } else {
        time+=run_t_left;
        double run_dist=run_t_left*(i+r);
        run_t_left=0.0;
        time+=(sp_l[i]-run_dist)/(s+i);
      }
    } else {
      time+=sp_l[i]/(double)(s+i);
    }
  }
  printf("%.9lf\n",time);
}

int main(){
  freopen("E:\\A-small-attempt0.in","r",stdin);
  freopen("E:\\A-small-attempt0.out","w",stdout);
  int t;
  scanf("%d",&t);
  for(int i=1;i<=t;i++){
    printf("Case #%d: ",i);
    handlecase();
  }
  return 0;
}
