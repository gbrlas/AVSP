#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include <utility>
#include <set>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

#define CLEAR(X) memset(X,0,sizeof(X))
#define REP(i,n) for(int i=0;i<(n);i++) 
template <class T> vector<T>parse(string s,const char d=' '){
  vector<T> v; string p; s+=d; int i=0; 
  while(i<(int)s.size())
    if (s[i] == d){stringstream u; u<<p; T t; u>>t; v.push_back(t); p=""; while(i<(int)s.size() && s[i]==d)i++;} else p+=s[i++];   
  return v;
} 

typedef long long ll;
typedef long double ld;

struct P{
  double x,y;
  P(double xx, double yy){
    x=xx;y=yy;
  }
  P(){x=y=0;}
};

typedef vector<P> LINE;

void cut(LINE &in, LINE &out, double x){
  out.clear();int n=in.size();
  REP(i,n){
    if(in[i].x<=x)out.push_back(in[i]);
    if(in[i].x<=x && i+1<n && in[i+1].x>x){
      double len = in[i+1].x - in[i].x;
      double over = x - in[i].x;
      P p(x, in[i].y + (over)*(in[i+1].y-in[i].y)/(len));
      out.push_back(p);
      break;
    }
  }
};

double area(LINE &l, LINE &U){
  vector<P> p;
  REP(i,(int)l.size())
    p.push_back(l[i]);
  for(int i=(int)U.size()-1;i>=0;i--)
    p.push_back(U[i]);
  p.push_back(l[0]);
  double sum = 0;
  REP(i,(int)p.size()-1){
    sum += p[i].x * p[i+1].y - p[i+1].x * p[i].y;
  }
  sum/=2.0;
  if(sum<0)return -sum;
  return sum;
};

int main(){
  int _cases; scanf("%d",&_cases);
  for(int _case=1;_case<=_cases;_case++){
    printf("Case #%d:",_case);
    LINE l,u;
    int W,L,U,G;
    scanf("%d%d%d%d",&W,&L,&U,&G);
    REP(i,L){
      int x,y;scanf("%d%d",&x,&y);
      l.push_back(P(x,y));
    }
    REP(i,U){
      int x,y;scanf("%d%d",&x,&y);
      u.push_back(P(x,y));
    }
//    cout<<area(l,u)<<endl;
    double A=area(l,u);
    double share=A/(double)G;
    printf("\n");
    double last = 0;
    REP(i,G-1){
      double le=last, ri=W;
      LINE nl, nu;
      double mid=0;
      REP(j,100){
        mid = (le+ri)/2.0;
        cut(l,nl,mid);
        cut(u,nu,mid);
        double na = area(nl,nu);
        if(na>share)ri=mid;else le=mid;
      };
      last = mid;
      LINE sl,su;
      sl.push_back(nl[nl.size()-1]);
      su.push_back(nu[nu.size()-1]);
      REP(i,(int)l.size()) if(l[i].x>last)sl.push_back(l[i]);
      REP(i,(int)u.size()) if(u[i].x>last)su.push_back(u[i]);
      l=sl;u=su;
      printf("%.15lf\n",last);
    }
  }
  return 0;
}
