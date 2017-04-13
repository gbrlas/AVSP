#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int f(void );
int a[200][200];
int main()
{
int i,j,x1,x2,y1,y2,fu,count,t1,tick,t,r,i1;
int b[200][200];

freopen("a.in","r",stdin);
freopen("out.txt","w",stdout);

scanf("%d",&tick);
for(t1=1;t1<=tick;t1++)
{
for(i=1;i<200;i++)
for(j=1;j<200;j++)
{
a[i][j]=0;
b[i][j]=0;
}

scanf("%d",&r);
for(i1=1;i1<=r;i1++)
{
scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
for(i=x1;i<=x2;i++)
for(j=y1;j<=y2;j++)
a[j][i]=1;

}

count=0;
fu=f();

for(i=1;i<200;i++)
for(j=1;j<200;j++)
b[i][j]=a[i][j];
while(fu==1)
{
count++;

for(i=1;i<110;i++)
for(j=1;j<110;j++)
if(a[i][j]==1)
{
if(i>1 && j>1)
if(b[i-1][j]==0 && b[i][j-1]==0)
a[i][j]=0;

if(i==1 && j>1 && b[i][j-1]==0) a[i][j]=0;
if(b[1][1]==1) a[1][1]=0;
if(j==1 && i>1 && b[i-1][j]==0) a[i][j]=0;

}
else
{
if(i>1 && j>1)
if(b[i-1][j]==1 && b[i][j-1]==1)
a[i][j]=1;
}

for(i=1;i<200;i++)
for(j=1;j<200;j++)
b[i][j]=a[i][j];

fu=f();
}
printf("Case #%d: %d\n",t1,count);
}
return 0;
}

int f(void)
{
int click=0,i,j;
for(i=1;i<200;i++)
for(j=1;j<200;j++)
if(a[i][j]==1)
click=1;

return click;
}

