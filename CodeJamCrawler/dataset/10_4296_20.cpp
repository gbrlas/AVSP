#include<iostream.h>
#include<stdio.h>
#include<conio.h>
void main()
{
long int l,t,n,k,i,j,d,a[100][2];
FILE *fp,*fw;
clrscr();
fp=fopen("d.txt","r");
fw=fopen("e.txt","w");
fscanf(fp,"%ld",&t);
for(i=1;i<=t;i++)
{
fscanf(fp,"%ld",&n);
fscanf(fp,"%ld",&k);
for(j=1;j<=n;j++)
{
a[j][1]=0;
a[j][2]=0;
}
a[1][1]=1;
for(j=1;j<=k;j++)
{

if(i==29)
{
for(l=1;l<=n;l++)
cout<<"#"<<a[l][1]<<" "<<a[l][2];
printf("\n");
}
for(l=1;l<=n;l++)
{
if(a[l][1]==1)
a[l][2]=1-a[l][2];
}

for(l=1;l<=n;l++)
{
d=l;
a[l][1]=1;
if(a[l][2]==0)
{
break;
}
}

for(l=d+1;l<=n;l++)
a[l][1]=0;
}
if(a[n][1]==1&&a[n][2]==1)
fprintf(fw,"Case #%ld: ON\n",i);
else
fprintf(fw,"Case #%ld: OFF\n",i);
}
getch();
}