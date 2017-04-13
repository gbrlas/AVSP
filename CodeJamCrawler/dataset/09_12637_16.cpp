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

int tc,n,i,j,k;
int A[50];
char str[1000];

int main(){
   scanf("%d ",&tc);
   for (int TC = 1; TC<=tc; TC++){
      scanf("%d ",&n);
      for (i = 0; i < n; i++){ 
         scanf("%s",str);
         A[i] = 0;
         for (j = n-1; j >= 0; j--){
            if (str[j] == '1'){
               A[i] = j+1;
               break;
            }
         }
      }
      int swap = 0;
      for (i = 0; i < n-1; i++){
         if (A[i] > i+1){
            for (j = i+1; j < n; j++){
               if (A[j] <= i+1){
                  for (k = j-1; k >= i; k--){
                     int tmp = A[k];
                     A[k] = A[k+1];
                     A[k+1] = tmp;
                     swap++;
                  }
                  break;
               }
            }
         }
      }
      printf("Case #%d: %d\n",TC,swap);
   }
   return 0;
}

