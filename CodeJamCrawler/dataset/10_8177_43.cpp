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
long long v[2000];
int ind[2000];
int pd[2000];
int vaux[2000];
long long vaux2[2000];
long long valores[2000];
int vaux3[2000];
long long vaux4[2000];

int T,R,N,K;
int vai(){
   long long soma = 0;
   int ult = 0;
   FOR(i,N){
      if(soma + v[i] > K)break;
      ult = i+1;
      soma += v[i];
   }
   REP(i,ult,N){
      vaux[i - ult] = ind[i];
      vaux2[i - ult] = v[i];
   }
   REP(i,0,ult){
      vaux[N - ult + i] = ind[i];
      vaux2[N - ult + i] = v[i];
   }
   FOR(i,N){
      ind[i] = vaux[i];
      v[i] = vaux2[i];
   }
   return soma;
}
int main(){
   cin >> T;
   FOR(t,T){
      cin >> R >> K >> N;
      FOR(i,N){
         cin >> v[i];
         ind[i] = i;
      }
      memset(pd,-1,sizeof(pd));
      int at = 0;
      long long acc = 0;
      long long acc2 = 0;
      int RR = R;
      FOR(i,N){
         vaux3[i] = ind[i];
         vaux4[i] = v[i];
      }
      while(RR--){
         acc2 += vai();
      }
      FOR(i,N){
         ind[i] = vaux3[i];
         v[i] = vaux4[i];
      }

      while(R){
         if(pd[ind[0]] == -1){
            pd[ind[0]] = at;
            acc += vai();
            valores[at] = acc;
            R--;
            at++;
         }
         else{
            long long tciclo = at - pd[ind[0]];
            long long vciclo = acc;
            if(ind[0] != 0) vciclo -= valores[pd[ind[0]]-1];
            acc += (R/tciclo) * vciclo;
            R %= tciclo;
            break;
         }
      }
      while(R--){
         acc += vai();
      }
      printf("Case #%d: ",t+1);
      printf("%lld %lld\n",acc,acc2);
   }
   return 0;
}
