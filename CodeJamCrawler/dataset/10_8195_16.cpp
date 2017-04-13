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
int v[5000];
int qt[5000];
vector<int> precos[5000];

int main(){
   int T,P;
   cin >> T;
   FOR(t,T){
      cin >> P;
      int M = 1<<P;
      FOR(i,M){
         cin >> v[i];
         qt[i] = 0;
         precos[i].clear();
      }

      int lin = 1<<P;
      lin /= 2;
      while(lin){
         int times = M/lin;
         int preco;
         FOR(i,lin){
            cin >> preco;
            REP(ii,i*times,i*times + times)precos[ii].PB(preco);
         }
         lin /= 2;
      }
      int nJogos = precos[0].size();
      //FOR(i,M){
        // cout << "time " << i << endl;
        // FOR(j,precos[i].size()) cout << precos[i][j] << " ";
        // cout << endl;
     // }
      int achei = 0;
      int count = 0;
      FOR(i,M){
         
         v[i] = nJogos - v[i];
         achei = max(achei,v[i]);
      }
      //cout << "PREFS" << endl;
      //FOR(i,M) cout << v[i] << endl;
      while(achei > 0){
         achei = 0;
         int im = 0;
         FOR(i,M) if(v[i] > v[im]) im = i;
         if(v[im] > 0)achei = 1;
         else break;

         count += v[im];
         int a = 0;
         int b = M;
         FOR(i,qt[im]){
            int meio = (a+b)/2;
            if(im < meio)b = meio;
            else a = meio;
         }
         while(v[im]){
            REP(i,a,b){
               v[i]--;
               qt[i]++;
            }
            int meio = (a+b)/2;
            if(im < meio)b = meio;
            else a = meio;
         }
      }
      printf("Case #%d: %d\n",t+1,count);

   }
   return 0;
}
