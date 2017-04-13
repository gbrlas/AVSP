#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
int dd[20];
int main()
{
    int cas;
    scanf("%d",&cas);
    int sn=0;
    while(cas--)
    {
        memset(dd,0,sizeof(dd));
        int a1,a2,i,j,k;
        scanf("%d",&a1);
        for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
        {
            scanf("%d",&k);
            if(i==a1)
            dd[k]=1;
        }
        scanf("%d",&a2);
        int tot=0,cc=0;
        for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
        {
            scanf("%d",&k);
            if(i==a2)
            {
                if(dd[k]==1)
                {
                 tot++;
                 cc=k;
                }
            }
        }
        printf("Case #%d: ",++sn);
        if(tot==1)
         printf("%d\n",cc);
        else if(tot>1)
         printf("Bad magician!\n");
        else
         printf("Volunteer cheated!\n");
        
    }
    return 0;
}
