#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<string>
#include<math.h>
#include<vector>
#include<map>
#include<iostream>
using namespace std;
double juli[2000],note[2000],ans=0;
int main()
{
 //   freopen("test.in","r",stdin);
   //  freopen("test.out","w",stdout);
    int kk,a,b,c,m,i,j,k,n,L,C,t,tt;
    scanf("%d",&kk);
    for(int pp=1; pp<=kk; pp++)
    {
        printf("Case #%d: ",pp);
        scanf("%d %d %d %d",&L,&t,&n,&c);
        for(i=0; i<c; i++)
            scanf("%lf",&juli[i]);
        j=0;
        ans=10000000000.0;
        for(i=0; i<n; i++)
        {
            // printf("%d  %d %lf\n",i,j,juli[j]);
            note[i]=juli[j];
            j++;
            if(j==c)
                j=0;
        }
        if(L==0)
        {
            ans=0;
            for(i=0; i<n; i++)
                ans+=2*note[i];
            printf("%.0lf\n",ans);
        }
        else if(L==1)
        {
            for(i=0; i<n; i++)
            {
                tt=0;
                for(j=0; j<n; j++)
                {
                    if(j!=i)
                        tt+=2*note[j];
                    else
                    {
                        if(tt>=t)
                            tt+=note[j];
                        else if(tt<t&&tt+2*note[j]>=t)
                            tt+=(t-tt)+(note[j]-(t-tt)/2);
                        else
                           tt+=2*note[j];
                    }
                }
                if(tt<=ans)
                    ans=tt;
            }
            printf("%.0lf\n",ans);
        }
        else if(L==2)
        {
            for(int i1=0; i1<n; i1++)
                for(int i2=i1+1; i2<n; i2++)
                {
                    tt=0;
                    for(j=0; j<n; j++)
                    {
                        if(j!=i1&&j!=i2)
                            tt+=2*note[j];
                        else
                        {
                            if(tt>=t)
                                tt+=note[j];
                            else if(tt<t&&tt+2*note[j]>=t)
                                tt+=(t-tt)+(note[j]-(t-tt)/2);
                            else
                           tt+=2*note[j];
                        }
                    }
                    if(tt<=ans)
                    {
                        ans=tt;
                    }
                }
            printf("%.0lf\n",ans);
        }
    }
}
