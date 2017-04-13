#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include<cctype>
#include<cmath>
#include <sstream>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<string>

using namespace std;

#define PB(x) push_back(x)
#define MP(x,y) make_pair((x),(y))
#define SZ(a) (int((a).size()))
#define ALL(a) (a).begin(),(a).end()
#define REP(x,a,b) for(int x = (a);x < (b);x++)
#define FOR(x,n) REP(x,0,n)
#define FOREVER while(1)
#define WATCH(x) cout << #x << " = " << (x)

#ifdef DEBUG
#define D(X) X
#else
#define D(X)
#endif

typedef long long ll;
const int inf = (1<<29);
#define MAX 10
int x[MAX];
int y[MAX];
int raio[MAX];
int n;
double dist(int i,int j){
   return sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
}
double resolve(){
   if(n == 1)return raio[0];
   if(n == 2)return max(raio[0],raio[1]);
   if(n == 3){
      double a = max((dist(0,1) + raio[0] + raio[1])/2.0,double(raio[2]));
      double b = max((dist(1,2) + raio[1] + raio[2])/2.0,(double)raio[0]);
      double c = max((dist(2,0) + raio[2] + raio[0])/2.0,(double)raio[1]);
      return min(min(a,b),c);
   }
}

int main(){
   int test;
   scanf("%d",&test);
   FOR(t,test){
      scanf("%d",&n);
      FOR(i,n){
         scanf("%d %d %d",&x[i],&y[i],&raio[i]);
      }
      double resp = resolve();
      printf("Case #%d: %lf\n",t+1,resp);
   }
   return 0;
}
