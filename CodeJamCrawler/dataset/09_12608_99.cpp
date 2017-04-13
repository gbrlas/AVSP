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
#define MOD 10000

using namespace std;

char *match = "welcome to code jam";
int tc,i,j,len,dp[1000][20];
char str[10005];

int main(){
   gets(str);
   sscanf(str, "%d ",&tc);
   for (int TC = 1; TC <= tc; TC++){
      gets(str);
      memset(dp,0,sizeof(dp));
      dp[0][0] = (str[0] == 'w'? 1: 0);
      for (i = 1; str[i] != 0; i++){
         dp[i][0] = dp[i-1][0];
         if (str[i] == 'w') dp[i][0]++;
         dp[i][0] %= MOD;
      }
      len = strlen(str);
      for (i = 1; i < len; i++){
         for (j = 1; j <= 18; j++){
            dp[i][j] = dp[i-1][j];
            if (str[i] == match[j])
               dp[i][j] += dp[i-1][j-1];
            dp[i][j] %= MOD;
         }
      }
      printf("Case #%d: %04d\n",TC,dp[len-1][18]);
   }
   return 0;
}

