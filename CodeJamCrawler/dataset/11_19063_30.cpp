#include<stdio.h>
#include<conio.h>
int dp(int set[],int start,int xor1,int xor2,int sum1,int sum2,int n);
int main()
{
    int t, n, i, start, xor1, xor2, sum1, sum2, set[1001], j, ans;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
           scanf("%d",&n);
           for(j=0;j<n;j++)
                  scanf("%d",&set[j]);
           start = xor1 = xor2 = sum1 = sum2 = 0;
           ans = dp(set,start,xor1,xor2,sum1,sum2,n);
           if(ans>1)
                  printf("Case #%d: %d\n",i+1,ans);
           else
                  printf("Case #%d: NO\n",i+1);
    }           

    return 0;
}
int dp(int set[],int start,int xor1,int xor2,int sum1,int sum2,int n)
{
        int res1, res2;
        if(start == n)
        {
              if((xor1 == xor2)&&(xor1!=0))
                     return (sum1>sum2?sum1:sum2);
              else
                     return (-1);
        }
        res1 = dp(set,start+1,xor1^set[start],xor2,sum1+set[start],sum2,n);
        res2 = dp(set,start+1,xor1,xor2^set[start],sum1,sum2+set[start],n);
        return(res1>res2?res1:res2);
}
        
