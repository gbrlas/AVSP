#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXP = 1000100;
int plist[MAXP],g_p;
bool isprime[MAXP];
void sieve()
{
      memset(isprime, true, sizeof (isprime));
      int i, j, p = 0;
      for (i = 2; i * i < MAXP; i++)
            if (isprime[i])
            {
                  for (j = i * i; j < MAXP; j += i)
                        isprime[j] = false;
            }
      isprime[0] = isprime[1] = false;
      for (i = 2; i < MAXP; i++)
            if (isprime[i])plist[p++] = i;
      g_p=p;
}
int work(double n)
{
      if(n<=1)return 0;
      int i,sqrtn,mlim,res=0;
      for(i=2;i<60;i++)
      {
            sqrtn=pow((double)n+0.5,1.0/i);
            mlim = upper_bound(plist, plist + g_p, sqrtn) - plist;
            res+=mlim;
      }
      return res+1;
}
int main()
{
    int i,cas,tt;
    freopen("C-large.in","r",stdin);
    freopen("c_out2.txt","w",stdout);
   sieve();
    scanf("%d",&tt);
    for(cas=1;cas<=tt;cas++)
    {
        double n;
        scanf("%lf",&n);
        int res=work(n);
        printf("Case #%d: %d\n",cas,res);
    }
    return 0;
}
