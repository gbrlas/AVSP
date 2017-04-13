#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<string>
#include<math.h>
#include<vector>
#include<map>
#include<iostream>
using namespace std;
char p1[110][100];
double h1[110],h2[110],h3[110],m1,m2,ans[110],m3;
int l1[110],l2[110];
int main()
{
   // freopen("test.in","r",stdin);
   // freopen("test.out","w",stdout);
    int a,b,c,m,i,j,k,n,kk,k1,k2;
    scanf("%d",&kk);
    for(int pp=1; pp<=kk; pp++)
    {
        scanf("%d",&n);
        getchar();
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
                scanf("%c",&p1[i][j]);
            getchar();
        }
        printf("Case #%d:\n",pp);
        for(i=1; i<=n; i++)
        {
            k1=0;
            k2=0;
            for(j=1; j<=n; j++)
            {
                if(p1[i][j]!='.')
                {
                    k2++;
                    if(p1[i][j]=='1')
                        k1++;
                }
            }
            l1[i]=k1;
            l2[i]=k2;
            h1[i]=(double)k1/(double)k2;
        }
        for(i=1; i<=n; i++)
        {
            k1=0;
            m3=0;
            for(j=1; j<=n; j++)
                if(p1[i][j]!='.'&&j!=i)
                {
                    k1++;
                    m2=l2[j]-1;
                    m1=l1[j];
                    if(p1[i][j]=='0')
                        m1=m1-1;
                    m3+=((double)(m1)/(double)(m2));

                }
            m3=m3/(k1*1.0);
            h2[i]=m3;
        }
        for(i=1; i<=n; i++)
        {
            k1=0;
            m3=0;
            for(j=1; j<=n; j++)
                if(p1[i][j]!='.'&&j!=i)
                {
                    k1++;
                    m3+=h2[j];
                }
            m3=m3/(k1*1.0);
            h3[i]=m3;
        }
        for(i=1; i<=n; i++)
            ans[i]=0.25 * h1[i] + 0.50 * h2[i] + 0.25 * h3[i];
        for(i=1; i<=n; i++)
            printf("%.7lf\n",ans[i]);
    }
}
