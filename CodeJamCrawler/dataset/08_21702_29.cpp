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

struct S{
  int x,y;
};

int a[3];
void norm(vector<S> &v){
  REP(i,3)a[i]=i;
  do{
    vector<S> w;w.resize(3);REP(i,3)w[i]=v[a[i]];
    for(int i=1;i<3;i++){w[i].x-=w[0].x;w[i].y-=w[0].y;}
    if (w[1].x*w[2].x+w[1].y*w[2].y==0 && w[1].x*w[2].y-w[1].y*w[2].x>0){
      v=w;
      return;
    }
  }while(next_permutation(a,a+3));
}

int main(){

  int _cases; scanf("%d",&_cases);
  for(int _case=1;_case<=_cases;_case++){
    printf("Case #%d:",_case);
    vector<S> v1,v2;
    REP(i,3){S s;scanf("%d%d",&s.x,&s.y);v1.push_back(s);}
    REP(i,3){S s;scanf("%d%d",&s.x,&s.y);v2.push_back(s);}
    //norm(v1);
//    vector<S> w;w.resize(3);REP(i,3)w[i]=v2[a[i]];
  //  v2=w;
    int dx=v2[0].x-v1[0].x;
    int dy=v2[0].y-v1[0].y;

    int ux=v1[1].x-v1[0].x;
    int uy=v1[1].y-v1[0].y;
    int vx=v1[2].x-v1[0].x;
    int vy=v1[2].y-v1[0].y;

    int wx=v2[1].x-v2[0].x;
    int wy=v2[1].y-v2[0].y;
    int zx=v2[2].x-v2[0].x;
    int zy=v2[2].y-v2[0].y;
    int px=ux-wx;
    int py=uy-wy;
    int qx=vx-zx;
    int qy=vy-zy;
    ld det=px*qy-qx*py;
    if(det==0){printf(" No Solution\n");continue;}

    ld y=(px*dy-py*dx)/det;
    ld x=(qy*dx-qx*dy)/(det);
    printf(" %.9Lf %.9Lf\n",v1[0].x+x*ux+y*vx,v1[0].y+x*uy+y*vy);
  }
  return 0;
}
