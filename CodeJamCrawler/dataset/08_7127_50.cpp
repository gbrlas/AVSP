#include<stdio.h>
#include<string.h>
#include<set>
#include<algorithm>
#define MAX 110
using namespace std;
struct inter{
   int saida,chegada;
};

bool operator<(struct inter a,struct inter b){
   if(a.saida != b.saida)
      return a.saida < b.saida;
   return a.chegada < b.chegada;
}

struct inter a[MAX];
struct inter b[MAX];
int na,nb;
int t;

int main(){
   int test;
   scanf("%d",&test);
   for(int te = 1;te <= test;te++){
      scanf("%d",&t);
      scanf("%d %d",&na,&nb);
      int hr,min;
      for(int i = 0;i < na;i++){
         scanf("%d%*c%d",&hr,&min);
         a[i].saida = hr*60 + min;
         scanf("%d%*c%d",&hr,&min);
         a[i].chegada = hr*60 + min;
      }
      for(int i = 0;i < nb;i++){
         scanf("%d%*c%d",&hr,&min);
         b[i].saida = hr*60 + min;
         scanf("%d%*c%d",&hr,&min);
         b[i].chegada = hr*60 + min;
      }
      sort(a,a+na);
      sort(b,b+nb);
      int pa,pb,ra,rb;
      multiset <int> ac,bc;

      for(pa = pb = ra = rb = 0;pa < na && pb < nb;){
         if(a[pa].saida < b[pb].saida){
            if(bc.empty()){
               ra++;
            }
            else{
               int temp = *bc.begin();
               if(temp + t <= a[pa].saida){
                  bc.erase(bc.begin());
               }
               else{
                  ra++;
               }
            }
            ac.insert(a[pa++].chegada);
         }
         else{
            if(ac.empty())rb++;
            else{
               int temp = *ac.begin();
               if(temp + t <= b[pb].saida){
                  ac.erase(ac.begin());
               }
               else{
                  rb++;
               }
            }
            bc.insert(b[pb++].chegada);
         }
      }
      while(pa < na){
         if(bc.empty())ra++;
         else{
            int temp = *bc.begin();
            if(temp + t <= a[pa].saida){
               bc.erase(bc.begin());
            }
            else{
               ra++;
            }
         }
         pa++;
      }
      while(pb < nb){
         if(ac.empty())rb++;
         else{
            int temp = *ac.begin();
            if(temp + t <= b[pb].saida){
               ac.erase(ac.begin());
            }
            else{
               rb++;
            }
         }
         pb++;
      }
      printf("Case #%d: %d %d\n",te,ra,rb);
   }
   return 0;
}
