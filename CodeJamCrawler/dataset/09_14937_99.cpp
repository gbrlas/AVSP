#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;
template <class T> void out(T x, int n){  for(int i = 1; i <= n; ++i)  cout << x[i] << ' ';    cout << endl;    }
template <class T> void out(T x, int n, int m){  for(int i = 1; i <= n; ++i)    out(x[i], m);    cout << endl;    }
#define OUT(x) (cout << #x << " = " << x << endl)
#define  Set(a,b)  memset(a,b,sizeof(a))
#define  LL long long
#define  eps 1e-8
const int maxn = 1005,INF = 0x7fffffff;

int n,m;
char str[maxn],p[]="welcome to code jam";
int dp[maxn],flag[maxn];
void debug(int len)
{
    for(int i=0;i<len;i++)
        cout<<dp[i]<<" ";
    cout<<endl;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.out","w",stdout);
    int i,j,k,t,T,x,y,sum,index;
    cin>>T;
    getchar();
    for(t=1;t<=T;t++)
    {
            gets(str);
            Set(dp,0);Set(flag,0);
            int len=strlen(str),sum=0,f=1;
            for(i=0;i<=18;i++)
            {
                if(i==0)
                {
                    for(j=0;j<len;j++)
                        if(str[j]==p[i])  flag[j]=f,dp[j]=1;
                }
                else
                {

                   for(j=0;j<len;j++)
                        if(str[j]==p[i])
                        {
                            for(k=0;k<j;k++)
                                if(flag[k]==f) dp[j]=(dp[j]+dp[k]%10000)%10000;
                            if(dp[j])  flag[j]=f+1;
                            if(i==18) sum=(sum+dp[j]%10000)%10000;
                        }
                   for(j=0;j<len;j++)
                      if(flag[j]!=f+1)  dp[j]=0;
                   f++;
                }
//                debug(len);
            }
            printf("Case #%d: ",t);
            if(sum==0) puts("0000");
            else if(sum<10)  printf("000"),printf("%d\n",sum);
            else if(sum<100) printf("00"),printf("%d\n",sum);
            else if(sum<1000)printf("0"),printf("%d\n",sum);
            else  printf("%d\n",sum);
    }
    return 0;
}
