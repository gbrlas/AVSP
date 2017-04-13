#include <cstdio>

using namespace std;

int main()
{
    freopen ("B-small-attempt0.in","r",stdin);
    freopen ("Lawnmower.txt","w",stdout);
    int t,i,j,k,ai,aj,n,m;
    scanf("%d",&t);
    for (i=1;i<=t;i++)
    {
        int c=1;
        scanf("%d %d\n",&n,&m);
        char b[n][2*m];
        for(j=0;j<n;j++)
        {
           gets(b[j]);
        }
        for(j=0;j<n;j++)
        {
           if (c==0)
              break;
           for(k=0;k<2*m-1;k+=2)
           {
              if (c==0)
                break;
              if(b[j][k]=='1')
              {
                for (aj=0;aj<2*m-1;aj+=2)
                {
                   if (c==0)
                     break;
                   if(b[j][aj]!='1')
                   {
                      for (ai=0;ai<n;ai++)
                      {
                          if(b[ai][k]!='1')
                          {
                            printf("Case #%d: NO\n",i);
                            c=0;
                            break;
                          }
                       }
                    }
                }
              }
            }
        }
       if (c==1)
       printf("Case #%d: YES\n",i);
   }
    return 0;
}
