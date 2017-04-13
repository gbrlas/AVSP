#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

struct walkway{
  int b,e,w;
};

bool order_comp(const walkway &w1, const walkway &w2){
  return (w1.b<w2.b);
}

bool greedy_comp(const walkway &w1, const walkway &w2){
  return (w1.w<w2.w);
}

walkway n_walkway(int a,int b,int c){
  walkway w;
  w.b=a;w.e=b;w.w=c;
  return w;
}

vector<walkway> W;

int main(){
  int X,S,R,t,N,cases,b,e,w,c,;
  scanf("%d",&cases);
  for(int cas=1;cas<=cases;cas++){
    W.clear();
    scanf("%d%d%d%d%d",&X,&S,&R,&t,&N);
    for(int i=0;i<N;i++){
      scanf("%d%d%d",&b,&e,&w);
      W.push_back(n_walkway(b,e,w));
    }
    sort(W.begin(),W.end(),order_comp);
    c=0;
    for(int i=0;i<N;i++){
      if(W[i].b>c){
        W.push_back(n_walkway(c,W[i].b,0));
      }
      c=W[i].e;
    }
    if(c<X){
      W.push_back(n_walkway(c,X,0));
    }
    sort(W.begin(),W.end(),greedy_comp);
    double res=0,t1=t,t2,t3;
    for(int i=0;i<(int)W.size();i++){
      t2 = (W[i].e-W[i].b)/(W[i].w+R*1.0);
      if (t2>t1){
        res+=t1;
        //t1=0;
        t3=(W[i].e-W[i].b-t1*(W[i].w+R))/(W[i].w+S*1.0);
        t1=0;
        res+=t3;
      } else {
        res+=t2;
        t1-=t2;
      }
    }
    printf("Case #%d: %lf\n",cas,res);
  }
  return 0;
}
