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

int f(int a,int b){
   if(a <= 0 || b <= 0)return 1;
   if(a == b)return 0;
   if(a%b == 0)return 1;
   if(b%a == 0) return 1;
   int x = a/b;
   int xx = b/a;
   if(x){
      if(f(a-x*b,b) == 0)return 1;
      if(x-1){
         if(f(a-(x-1)*b,b) == 0)return 1;
      }
   }
   if(xx){
      if(f(a,b-xx*a) == 0)return 1;
      if(xx-1){
         if(f(a,b-(xx-1)*a) == 0)return 1;
      }
   }
   return 0;
}

int main(){
   int T,A,AA,B,BB;
   cin>>T;
   FOR(t,T){
      cin >> A >> AA >> B >> BB;
      int count = 0;
      REP(i,A,AA+1){
         REP(j,B,BB+1){
            if(f(i,j))count++;
         }
      }
      printf("Case #%d: %d\n",t+1,count);
   }
   return 0;
}
