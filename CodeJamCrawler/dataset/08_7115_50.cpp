#include<stdio.h>
#include<string.h>
using namespace std;
#define MAXS 110
#define MAXQ 1100
#define MAXL 110
#define INF (1<<30)

char dic[MAXS][MAXL];
int qs[MAXS];
int ordem[MAXQ];
int n,s,q,min;

int res(){
   int mem[MAXS];
   int tot = 0;
   int at = -1;
   for(int i = 0;i < s;i++)if(qs[i] == 0)return 0;
   
   memset(mem,0,sizeof(mem));
   for(int j = 0;j < q;j++){
      if(mem[ordem[j]] == 0){
         mem[ordem[j]] = 1;
         at = ordem[j];
      }
   }

   for(int i = 0;i < q;i++){
      if(ordem[i] == at){
         for(int j = 0;j < s ;j++)if(qs[j] == 0)return tot + 1;
         memset(mem,0,sizeof(mem));
         for(int j = i+1;j < q;j++){
            if(ordem[j] != ordem[i] && mem[ordem[j]] == 0){
               mem[ordem[j]] = 1;
               at = ordem[j];
            }
         }
         qs[ordem[i]]--;
         tot++;
      }
      else{
         qs[ordem[i]]--;
      }
      //printf("%s",dic[at]);
      //for(int j = 0;j < s;j++)printf("%d ",qs[j]);
      //printf("\n");
   }
   return tot;
}
void imprime(){
   printf("s\n");
   for(int i = 0;i < s;i++)printf("%s",dic[i]);
   printf("s\n");
   printf("o");
   for(int i = 0;i < q;i++)printf("%d",ordem[i]);
   printf("o\n");

}
int main(){
   int test = 1;
   char buffer[MAXL];
   scanf("%d",&n);
   while(n--){
      memset(qs,0,sizeof(qs));
      scanf("%d",&s);
      getchar();
      for(int i = 0;i < s;i++){
         fgets(dic[i],MAXL,stdin);
      }
      scanf("%d",&q);
      if(q == 0){
   //      imprime();
         printf("Case #%d: 0\n",test++);
         continue;
      }
      getchar();
      for(int i = 0;i < q;i++){
         fgets(buffer,MAXL,stdin);
         int j;
         for(j = 0;j < s;j++)
            if(strcmp(dic[j],buffer) == 0)
               break;

         qs[j]++;
         ordem[i] = j;
      }
     // imprime();
      min = res();
      printf("Case #%d: %d\n",test++,min);
   }
   return 0;
}
