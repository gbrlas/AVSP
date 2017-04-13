/* HellGeek */
/* Shiva Bhalla */
/* iit2012077 */


#include<stdio.h>
#include<vector>
#include<map>
#include<utility>
#include<algorithm>
#include<set>
#include<string>
#include<string.h>
#include<iostream>
#include<queue>
#include<stack>
#include<math.h>

#define LL long long
#define FIT(i,t) for(i=0;i<t;i++)
#define FIN(i,n) for(i=0;i<n;i++)
#define FJT(j,t) for(j=0;j<t;j++)
#define FJN(j,n) for(j=0;j<n;j++)
#define MAX2(a,b) a>b?a:b
#define MIN2(a,b) a>b?b:a
#define REP(i,a,b) for(i=a;i<=b;i++)

using namespace std;

int main()
{
int t,i,j,k,l,n;
int arr[5][5];
int arr1[5][5];
freopen("outputques1.txt","w",stdout);
cin>>t;
for(k = 1;k<=t;k++)
{
          cin>>n;
          for(i=1;i<=4;i++){
                           for(j=1;j<=4;j++){
                                            cin>>arr[i][j];
                           }
          }
                                            
          cin>>l;
          for(i=1;i<=4;i++){
                           for(j=1;j<=4;j++){
                                            cin>>arr1[i][j];
                           }
          }
          
          int it,flag = 0;
          
          for(i = 1; i <= 4 ; i++) {
                for(j = 1; j<= 4; j++) {
                      if(arr[n][i] == arr1[l][j]) {
                                   flag++;
                                   it = arr[n][i];
                                   break;
                      }
                }
          }
          
          if(flag == 0) {
                  printf("Case #%d: Volunteer cheated!\n",k);
          }
          else if(flag == 1) {
               printf("Case #%d: %d\n",k,it);
          }
          else
          printf("Case #%d: Bad magician!\n",k);
    }
    
    return 0;
}
          
                      
          
