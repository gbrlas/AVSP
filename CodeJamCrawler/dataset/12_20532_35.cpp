#include<stdio.h>
#include<string.h>
using namespace std;
int a[200],chk[200];
int main()
{
    int t,tc,N,S,P,k,mx,ans,i,L;

    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);

  scanf("%d",&t);
  tc=0;
  while(tc<t)
  {
      tc++;
      scanf("%d %d %d",&N,&S,&P);

      memset(chk,0,sizeof(chk));

      for(i=0;i<N;i++)
        scanf("%d",&a[i]);

       ans=0;
       L=3*P-2;
      for(i=0;i<N;i++)
      {
           if(a[i]>=L)
           {
             chk[i]=1;
             ans++;
           }
      }
        L-=2;

      for(i=0;i<N;i++)
      {
          if(S<1)
            break;
          if(chk[i]==0)
          {
              if(a[i]<3 && a[i]>=P)
              {
                  ans++;
                  S--;
              }

             if(a[i]>=L && a[i]>=3)
             {
                 ans++;
                 S--;
             }
          }

      }
      printf("Case #%d: %d\n",tc,ans);
  }
}
