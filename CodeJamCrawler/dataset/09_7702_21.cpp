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
#define MAX 50
int vetor[MAX];
int n;

int bubble(){
   int count = 0;
   FOR(i,n){
      int _j;
      REP(j,i,n){
         if(vetor[j] <= i){_j = j;break;}
      }
      count += _j - i;
      int aux = vetor[_j];
      for(int j = _j;j > i;j--){
         vetor[j] = vetor[j-1];
      }
      vetor[i] = aux;
   }
   return count;
}

int main(){
   int test;
   scanf("%d",&test);
   FOR(t,test){
      scanf("%d",&n);
      FOR(i,n){
         vetor[i] = 0;
         char a[MAX];
         scanf("%s",a);
         FOR(j,n){
            if(a[j] == '1')vetor[i] = j;
         }
      }
      int resp = bubble();
      printf("Case #%d: %d\n",t+1,resp);
   }
   return 0;
}
