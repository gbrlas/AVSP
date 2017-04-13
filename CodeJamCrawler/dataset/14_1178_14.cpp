#include <cstdio>
#define eps 1e-8
double c,f,x;
int main()
{
    int T,cas=0;
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
     scanf("%lf%lf%lf",&c,&f,&x);
     double ans=1e15;
     for(int i=0;;++i)
     {
      double res=0,r=2;
      for(int j=0;j<i;++j)
      {
       res+=c/r;
       r+=f;
      }
      res+=x/r;
      if(res<ans+eps)ans=res;
      else break;
     }
     printf("Case #%d: ",++cas);
     printf("%f\n",ans);
    }
    return 0;
}
