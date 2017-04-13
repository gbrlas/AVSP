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

int i,j,tc,a,n,np,L;
char str[100000],s[1000];
int child[2][500],info[500];
double w[500],ans;
char att[500][12];
char name[5000][12];

int buildtree(){
   int cur = n++,j;
   if (str[i] == '(') i++;
   sscanf(str+i,"%lf",&w[cur]);
   for (;; i++)
      if (str[i] == ')') return cur;
      else if (str[i] >= 'a' && str[i] <= 'z') break;
   for (j = 0;str[i] != '('; i++)
      name[np][j++] = str[i];
   info[cur] = np;
   name[np][j] = 0; np++;
   i++;
   child[0][cur] = buildtree();
   i++;i++;
   child[1][cur] = buildtree();
   i++;
   return cur;
}

void process(){
   i = 0;
   bool flag = false;
   for (j = 0; str[j] != 0; j++){
      if (str[j] != ' ') str[i++] = str[j];
   }
   str[i] = 0;
}

void visit(int node){
   ans *= w[node];
   if (child[0][node] != -1){
      int flag = 0;
      for (i = 0; i < L; i++)
         if (strcmp(name[info[node]],att[i])==0){
            flag = 1; break;
         }
      visit(child[1-flag][node]);
   }
}

int main(){
   gets(s);
   sscanf(s,"%d ",&tc);
   for (int TC=1; TC<=tc; TC++){
      gets(s);
      sscanf(s,"%d ",&n);
      str[0] = 0;
      for (i = 0; i < n; i++){
         gets(s);
         strcat(str,s);
      }
      process();
      i = 1; 
      np = 0;
      n = 0;
      memset(child,-1,sizeof(child));
      memset(info,-1,sizeof(child));
      buildtree();
      gets(s); sscanf(s,"%d ",&a);
      printf("Case #%d:\n",TC);
      for (int i = 0; i < a; i++){
         gets(s);
         char *pch = strtok(s, " ");
         pch = strtok(0, " ");
         sscanf(pch,"%d",&L);
         for (j = 0; j < L; j++){
            pch = strtok(0, " ");
            strcpy(att[j],pch);
         }
         ans = 1.0;
         visit(0);
         printf("%.7lf\n",ans);
      }
   }
   return 0;
}

