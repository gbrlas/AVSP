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
char palavras[5010][20];
char buf[10000];
char letras[20][5000];
int qtd[5000];
int l,d,n;
int main(){
   int test = 1;
   scanf("%d %d %d",&l,&d,&n);
   FOR(i,d){
      scanf("%s",palavras[i]);
   }
   FOR(i,n){
      scanf("%s",buf);
      int j = 0;
      int at = 0;
      bool entrei = false;
      memset(qtd,0,sizeof(qtd));
      while(buf[j] != '\0'){
         if(buf[j] == '('){
            j++;
            entrei = true;
         }
         else if(buf[j] == ')'){
            j++;
            at++;
            entrei = false;
         }
         else{
            if(entrei)
               letras[at][qtd[at]++] = buf[j];
            else{
               letras[at][qtd[at]++] = buf[j];
               at++;
            }
            j++;
         }
      }
      int count = 0;
      FOR(j,d){
         int achei = 1;
         FOR(k,l){
            int acheiinterno = 0;
            FOR(q,qtd[k]){
               if(letras[k][q] == palavras[j][k]){
                  acheiinterno = 1;
                  break;
               }
            }
            if(!acheiinterno){
               achei = 0;
               break;
            }
         }
         if(achei)count++;
      }
      printf("Case #%d: %d\n",test++,count);
   }
   return 0;
}
