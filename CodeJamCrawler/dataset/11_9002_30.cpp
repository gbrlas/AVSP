#include <cstdio>
#include <algorithm>
#include <functional>
#include <cmath>
using namespace std;

struct p_s{
  double px;
  double pl;
  double pu;
  double left_s;
  bool operator< (const p_s& b) const{
    return px<b.px;
  }
};

const double ILI=10000.0;
const double EPS=1e-8;

void handlecase(){
  int w,l,u,g;
  scanf("%d%d%d%d",&w,&l,&u,&g);
  p_s ps[200];
  for(int i=0;i<l;i++){
    scanf("%lf%lf",&ps[i].px,&ps[i].pl);
    ps[i].pu=ILI;
  }
  int pn=l;
  for(int i=0;i<u;i++){
    double x,y;
    scanf("%lf%lf",&x,&y);
    bool have=false;
    for(int j=0;j<l;j++){
      if(abs(ps[j].px-x)<EPS){
        ps[j].pu=y;
        have=true;
        break;
      }
    }
    if(!have){
      ps[pn].px=x;
      ps[pn].pu=y;
      ps[pn].pl=ILI;
      pn++;
    }
  }
  sort(ps,ps+pn);
  double sum_s=0.0;
  for(int i=1;i<pn;i++){
    if(ps[i].pl==ILI){
      int l=i-1;
      for(;ps[l].pl==ILI;l--);
      int r=i+1;
      for(;ps[r].pl==ILI;r++);
      ps[i].pl=ps[l].pl+(ps[i].px-ps[l].px)/(ps[r].px-ps[l].px)*(ps[r].pl-ps[l].pl);
    }
    if(ps[i].pu==ILI){
      int l=i-1;
      for(;ps[l].pu==ILI;l--);
      int r=i+1;
      for(;ps[r].pu==ILI;r++);
      ps[i].pu=ps[l].pu+(ps[i].px-ps[l].px)/(ps[r].px-ps[l].px)*(ps[r].pu-ps[l].pu);
    }
    ps[i].left_s=(ps[i].pu-ps[i].pl+ps[i-1].pu-ps[i-1].pl)*(ps[i].px-ps[i-1].px)/2.0;
                    //printf("%d: %lf %lf %lf %lf\n",i,ps[i].px,ps[i].pl,ps[i].pu,ps[i].left_s);
    sum_s+=ps[i].left_s;
  }
  double sin_s=sum_s/g;
  double acc_s=0.0;
  for(int i=1;i<pn;i++){
    double left_s=ps[i].left_s;
    while(acc_s+left_s>=sin_s){
      if((acc_s+left_s-sin_s)<EPS&&i==pn-1){
        break;
      }
      double need_s=sin_s-acc_s+(ps[i].left_s-left_s);
                      //printf("%lf %lf %lf %lf\n",acc_s,left_s,need_s,sin_s);
      double ea=(ps[i-1].pu-ps[i-1].pl-ps[i].pu+ps[i].pl)/2.0/(ps[i].px-ps[i-1].px);
      double eb=-(ps[i-1].pu-ps[i-1].pl);
      double ec=need_s;
                      //printf("%lf %lf %lf \n",ea,eb,ec);
      if(abs(ea)<EPS){
        double x=-ec/eb;
        printf("%.6lf\n",ps[i-1].px+x);
      } else {
        double delta=eb*eb-4*ea*ec;
        double x1=(-eb+sqrt(delta))/2.0/ea;
        double x2=(-eb-sqrt(delta))/2.0/ea;
                      //printf("%lf %lf\n",x1,x2);
        if(x1>=0&&x1<=ps[i].px-ps[i-1].px){
          printf("%.6lf\n",ps[i-1].px+x1);
        } else {
          printf("%.6lf\n",ps[i-1].px+x2);
        }
      }
      left_s-=sin_s-acc_s;
      acc_s=0.0;
    }
    acc_s+=left_s;
  }
}

int main(){
  freopen("E:\\A-large.in","r",stdin);
  freopen("E:\\A-large.out","w",stdout);
  int t;
  scanf("%d",&t);
  for(int i=1;i<=t;i++){
    printf("Case #%d:\n",i);
    handlecase();
  }
  return 0;
}
