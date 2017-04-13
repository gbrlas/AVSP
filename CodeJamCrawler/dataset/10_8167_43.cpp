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
int on[100];
int energy[100];
int main(){
   int T,N,K;
   cin >> T;
   FOR(t,T){
      cin >> N >> K;
      memset(on,0,sizeof(on));
      memset(energy,0,sizeof(energy));
      energy[0] = 1;
      FOR(k,K){
         FOR(i,N){
            if(energy[i]) on[i] = 1-on[i];
            else break;
         }
         REP(i,1,N){
            if(on[i-1] && energy[i-1])energy[i] = 1;
            else if(energy[i]) energy[i] = 0;
            else break;
         }
      }


      printf("Case #%d: ",t+1);
      printf((on[N-1] && energy[N-1]) ? "ON\n" : "OFF\n");
   }
   return 0;
}
