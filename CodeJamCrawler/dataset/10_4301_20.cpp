#include<iostream.h>
#include<conio.h>
#include<stdio.h>
void main()
{
int a[2000];
int t,d=0,i,r,j,k,l,m,n;
unsigned long int s=0,c=0;
clrscr();
FILE *fr,*fw;
fr=fopen("a.txt","r");
fw=fopen("c.txt","w");
fscanf(fr,"%d",&t);
for(i=1;i<=t;i++)
{
s=0;
fscanf(fr,"%d",&r);
fscanf(fr,"%d",&k);
fscanf(fr,"%d",&n);
for(j=0;j<=n;j++)
a[j]=0;
for(j=1;j<=n;j++)
fscanf(fr,"%d",&a[j]);
for(j=1;j<=r;j++)
{
c=0;
d=0;
for(l=1;l<=n;l++)
{
if(c+a[l]>k)
break;
else
{
d=l;
c=c+a[l];
}
}
s=s+c;
for(l=1;l<=d;l++)
{
for(m=1;m<=n;m++)
a[m-1]=a[m];
a[n]=a[0];
}
}
cout<<i<<" "<<s<<" ";
fprintf(fw,"Case #%d: %u\n",i,s);

}
getch();
}








