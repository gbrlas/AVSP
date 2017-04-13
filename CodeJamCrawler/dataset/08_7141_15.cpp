#include<stdio.h>
#include<string.h>
#define MAX 1010

int sets[MAX];
int sz[MAX];
int primos[MAX];
int count;


int find(int a);

int eras(){
   memset(primos,1,sizeof(primos));
   for(int i = 2;i < MAX;i++){
      if(primos[i]){
         for(int j = i + i;j < MAX;j += i){
            primos[j] = 0;
         }
      }
   }
   return 1;
}

int UNION(int a,int b){
   int ra = find(a);
   int rb = find(b);
   if(ra == rb)return 0;
   if(sz[ra] < sz[rb]){
      sets[ra] = rb;
      sz[rb] += sz[ra];
   }
   else{
      sets[rb] = ra;
      sz[ra] += sz[rb];
   }
   return 1;
}

int find(int a){
   if(sets[a] != a)
      sets[a] = find(sets[a]);
   return sets[a];
}

int comun(int a,int b,int c){
   for(int i = c;(i <= a) && (i <= b);i++){
      if(primos[i]){
         if((a%i == 0) && (b%i == 0))return 1;
      }
   }
   return 0;
}

int main(){
   int test;
   int a,b,p;

   scanf("%d",&test);
   eras();
   for(int i = 0;i < test;i++){
      scanf("%d %d %d",&a,&b,&p);
      count = b - a + 1;

      for(int j = a;j <= b;j++)
         sets[j] = j,sz[j] = 1;

      for(int j = a;j <= b;j++){
         for(int k = j+1;k <= b;k++){
            if(comun(j,k,p)){
               if(UNION(j,k)){
                  count--;
               }
            }
         }
      }
      printf("Case #%d: %d\n",i+1,count);
   }
   return 0;
}
