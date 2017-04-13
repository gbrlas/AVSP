#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>

int main()
{
    int t,i,j,k,na,nb,r;
    int a[4][4];
    scanf("%d",&t);
    for(i=1;i<=t;++i)
    {
        na=nb=0;
        scanf("%d",&r);
        for(j=0;j<4;++j)
        {
            for(k=0;k<4;++k) scanf("%d",&a[j][k]);
        }
        for(j=0;j<4;++j)na|=(1<<a[r-1][j]);
        //printf("%d\n",na);
        scanf("%d",&r);
        for(j=0;j<4;++j)
        {
            for(k=0;k<4;++k) scanf("%d",&a[j][k]);
        }
        for(j=0;j<4;++j)nb|=(1<<a[r-1][j]);
        //printf("%d\n",na);
        nb = na&nb;
        na = 0;
        k=0;
        j = 0;
        while(nb>0)
        {
            if(nb&1)
            {
                ++na;
                j = k;
            }
            nb>>=1;
            ++k;
        }
        printf("Case #%d: ",i);
        if(na==0) printf("Volunteer cheated!\n");
        else if(na==1) printf("%d\n",j);
        else printf("Bad magician!\n");
    }
    return 0;
}
