#include<stdio.h>
#include<stdlib.h>
int main(void)
{
int t,N,S,p,*ti,i,mx,cn=0,in;
scanf("%d",&t);
while(t--)
{
mx=0;
cn++;
scanf("%d %d %d",&N,&S,&p);
ti=malloc(N*sizeof(int));
for(i=0;i<N;i++)
    {
    scanf("%d",&in);
    ti[i]=in;
    if((p-1)*3<ti[i])
        mx++;
    else if(S>0 && ti[i]>=((p-1)*3-1))
        {
        if(t[i]!=0)
            {
            mx++;
            S--;
            }
        }
    }
printf("Case #%d: %d\n",cn,mx);
free(ti);
}
return 0;
}
