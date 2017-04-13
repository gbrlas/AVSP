#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <set>
#include <queue>
#include <map>
#include <algorithm>

#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)
#define pii pair<int,int>

using namespace std;

struct nodeT{
   int end;
   nodeT *next[26];
};

int L,D,N,np,total;
char str[1005];
nodeT root, nodes[1000000];
vector <int> num[20];

void addWord(nodeT *p, char *word){
   for (int i = 0; i < L; i++){
      int id = word[i]-'a';
      if (p->next[id] == NULL){
         memset(&nodes[np],0,sizeof(nodeT));
         p->next[id] = &nodes[np++];
      }
      p = p->next[id];
      if (i == L-1) p->end = 1;
   }
}

void printtrie(nodeT *p, int depth){
   if (p->end == 1){
      total++;
      return;
   }
   for (int i = 0; i < num[depth].size(); i++){
      int u = num[depth][i];
      if (p->next[u] != NULL)
         printtrie(p->next[u],depth+1);
   }
}

int main(){
   scanf("%d %d %d ",&L,&D,&N);
   memset(&root,0,sizeof(root));
   np = 0;
   for (int i = 0; i < D; i++){
      scanf("%s ",str);
      addWord(&root,str);
   }
   for (int i = 1; i <= N; i++){
      total = 0;
      scanf("%s ",str);
      for (int j = 0; j <= L; j++) num[j].clear();
      int cnt = 0;
      for (int j = 0; str[j] != 0; j++){
         if (str[j] == '('){
            j++;
            while (str[j] != ')'){
               num[cnt].push_back(str[j]-'a');
               j++;
            }
            cnt++;
         }else
            num[cnt++].push_back(str[j]-'a');
      }
      printtrie(&root,0);
      printf("Case #%d: %d\n",i,total);
   }
   return 0;
}

