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

int tc;
int len,i,j,k;
char s[1000];

int main(){
   gets(s);
   sscanf(s,"%d ",&tc);
   for (int TC=1; TC<=tc; TC++){
      gets(s);
      len = strlen(s); 
      int flag = false;
      for (i = len-1; i >= 0; i--){
         for (j = s[i]+1; j <= '9'; j++){
            for (k = i+1; k < len; k++)
               if (s[k] == j){
                  flag = true;
                  s[k] = s[i];
                  s[i] = j;
                  break;
               }
            if (flag == true) break;
         }
         if (flag == true) break;
      }
      if (flag == true){
         sort(s+i+1,s+len);
         printf("Case #%d: %s\n",TC,s);
      }else{
         s[len++] = '0'; s[len] = 0;
         sort(s,s+len);
         for (i = 0; s[i] != 0; i++)
            if (s[i] != '0'){
               s[0] = s[i];
               s[i] = '0';
               break;
            }
         printf("Case #%d: %s\n",TC,s);
      }
   }
   return 0;
}

