#include<stdio.h>

int main()
{
int i,j,k,t,c1,c2,ans,cnt=0;
int p1[4],p2[4],a[4][4];
scanf("%d", &t);
for(k=0;k<t;k++)
{
cnt =0;
scanf("%d",&c1);
for(i=0; i<4; i++)
for(j=0;j<4;j++)
{
scanf("%d",&a[i][j]);
if(c1 == i+1)
{
p1[j]=a[i][j];
}
}

scanf("%d",&c2);
for(i=0;i<4;i++)
for(j=0;j<4;j++)
{
scanf("%d",&a[i][j]);
if(c2 == i+1)
{
p2[j]=a[i][j];
}
}

for(i=0; i<4; i++)
{
    for ( j = 0 ; j < 4 ; j++ ){
if(p1[i] == p2[j])
{
cnt++;
ans=p1[i];
}
}
}
if(cnt == 1)
printf("Case #%d: %d\n",k+1,ans);
else
{
if(cnt > 1)
printf("Case #%d: Bad magician!\n",k+1);
else
printf("Case #%d: Volunteer cheated!\n",k+1);
} 
}
return 0;
}