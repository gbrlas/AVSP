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
#define MAXL 20
#define MAXN 10000
typedef long long ll;
const int inf = (1<<29);
struct node{
   double mult;
   char feature[MAXL];
   int dir;
   int esq;
};
int nnn;
struct node make_node(double mult,char feature[MAXL],int dir,int esq){
   struct node a;
   strcpy(a.feature,feature);
   a.mult = mult;
   a.dir = dir;
   a.esq = esq;
   return a;
}
string arv;
char buf[10000];
struct node mem[MAXN];
int pont;

int constroi_arvore(int ini,int fim){
   double mult;
   int ii;
   int esq = -1;
   int dir = -1;
   char buf[10000];
   buf[0] = '\0';

   sscanf(arv.c_str() + ini + 1,"%lf",&mult);
   for(int i = ini+1;i < fim;i++){
      if(arv[i] >= 'a' && arv[i] <= 'z'){
         ii = i;
         break;
      }
      else if(arv[i] == ')'){
         mem[pont] = make_node(mult,buf,esq,dir);
         return pont++;
      }
   }ii--;
   sscanf(arv.c_str() + ii,"%s",buf);
   int cont = 1;
   int i;
   for(i = ii;arv[i] != '(';i++);
   int j = i+1;
   while(cont > 0){
      if(arv[j] == ')')cont--;
      if(arv[j] == '(')cont++;
      j++;
   }
   esq = constroi_arvore(i,j);

   cont = 1;
   i;
   for(i = j;arv[i] != '(';i++);
   j = i+1;
   while(cont > 0){
      if(arv[j] == ')')cont--;
      if(arv[j] == '(')cont++;
      j++;
   }
   dir = constroi_arvore(i,j);

   mem[pont] = make_node(mult,buf,esq,dir);
   return pont++;
}
void imprime_arvore(int n,int altura){
   if(mem[n].esq != -1)imprime_arvore(mem[n].esq,altura+1);
   FOR(i,altura)printf("    ");
   printf("%lf %s\n",mem[n].mult,mem[n].feature);
   if(mem[n].dir != -1)imprime_arvore(mem[n].dir,altura+1);
}
char features[150][MAXL];
double resolve(int head,double p){
   p *= mem[head].mult;
   if(mem[head].esq == -1)return p;
   FOR(i,nnn){
      if(strcmp(mem[head].feature,features[i]) == 0){
         return resolve(mem[head].dir,p);
      }
   }
   return resolve(mem[head].esq,p);
}
int main(){
   int test;
   char lixo[10000];
   scanf("%d",&test);
   FOR(t,test){
      int lines;
      arv = "";
      pont = 0;
      scanf("%d\n",&lines);
      FOR(lll,lines){

         fgets(buf,10000,stdin);
         arv += buf;
      }
      int head = constroi_arvore(0,arv.size());
      //imprime_arvore(head,0);
      //printf("\n");
      scanf("%d",&lines);
      printf("Case #%d:\n",t+1);
      FOR(l,lines){
         scanf("%s %d",lixo,&nnn);
         FOR(i,nnn){
            scanf("%s",features[i]);
         }
         double resp = resolve(head,1.0);
         printf("%.7lf\n",resp);
      }
   }
   return 0;
}
