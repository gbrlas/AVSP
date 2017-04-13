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
    LL i,j,k,l,n,m,t;
    double a,b,c,d,f,x,tim,prod,besttime;
    freopen("outputques2.txt","w",stdout);
    
    cin >> t;
    for(i = 1; i<= t;i++) {
          besttime = 99999999.999;
          cin >> c >> f >> x;
          
          prod = 2.0;
          tim = 0.0;
          a = 0;
          k = 0;
          
          while(1) {
                     b = tim + (double)x/(double)prod;
                     if(besttime < b)
                     break;
                     besttime = b;
                     //cout << besttime << endl;
                     tim = tim + (c/(prod));
                     prod = prod + f;
          }
          printf("Case #%lld: %.7lf\n",i,besttime);
    }
    return 0;
}
