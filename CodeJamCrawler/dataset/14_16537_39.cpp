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
    LL i,j,k,l,n,m,t,ans1,ans2;
    double a[100005];
    double b[100005];
    int arr[100005];
    double x,y,z,u,v,w;
    cin >> t;
    freopen("outputques4.txt","w",stdout);
    for(i=1;i<=t;i++) {
                      cin >> n;
                      
                      for(j=0;j<n;j++)
                      cin >> a[j];
                      
                      for(j=0;j<n;j++)
                      cin >> b[j];
                      
                      sort(a,a+n);
                      sort(b,b+n);
                      
                        
                      
                      k = 0;
                      l = n-1;
                      m = 0;
                      for(j = n-1; j>=0;j--) {
                            if(b[j]>a[l]) {
                                          m++;
                            }
                            else
                            {
                                k++;
                                l--;
                            }
                      }
                      
                      ans1 = k;
                      
                      k = 0;
                      l = 0;
                      for(j=0;j<=n;j++)
                      arr[j] = 0;
                      
                      
                      for(j=0;j<n;j++) {
                                       for(l=0;l<n;l++) {
                                                        if(arr[l] == 0 && a[j]<b[l]) {
                                                                  arr[l]= 1;
                                                                  k++;
                                                                  break;
                                                        }
                                       }
                      }
                      ans2 = n-k;
                      printf("Case #%lld: %lld %lld\n",i,ans1,ans2);
    }
    return 0;
}
