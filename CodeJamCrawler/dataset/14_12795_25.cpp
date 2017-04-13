#include <stdio.h>
int main()
{
int s1[4][4], s2[4][4], i,j,k,T,t,a1,a2, res=0, k1[4], k2[4];
scanf("%d", &t);
for(T=1;T<=t;T++)
{
res=0;
scanf("%d", &a1);
for(i=0;i<4;i++)
for(j=0;j<4;j++)
scanf("%d", &s1[i][j]);
scanf("%d", &a2);
for(i=0;i<4;i++)
for(j=0;j<4;j++)
scanf("%d", &s2[i][j]);
for(i=0;i<4;i++)
k1[i]=s1[a1-1][i];
for(i=0;i<4;i++)
k2[i]=s2[a2-1][i];
for(i=0;i<4;i++)
for(j=0;j<4;j++)
if(k1[i]==k2[j])
{res++; k=k1[i];}
if(res==0)
printf("Case #%d: Volunteer cheated!\n",T);
else if(res==1)
printf("Case #%d: %d\n",T,k);
else
printf("Case #%d: Bad magician!\n",T);
}
return 0;
}
