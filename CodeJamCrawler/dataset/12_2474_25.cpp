#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<math.h>
int main()
{
int i,j,k,m,n,p,l,a=1,num,mod,rev=0,real,x,y,t,q,s,o,z,c[1000];double v,u;char temp1,temp,d[4],e[16],f[16],g[16],h[16],*r;
FILE *fp,*fp1;
fp1=fopen("recycled_output.txt","w");
if(fp1!=NULL)
{
fp=fopen("recycled.txt","r");
if(fp!=NULL)
{
fscanf(fp,"%d\n",&n);
printf("n = %d\n",n);
for(i=1;i<=n;i++)
{
/*for(t=0;t<1000;t++)
c[t]=t+1;*/
fscanf(fp,"%d",&m);
printf("m = %d\t",m);
fscanf(fp,"%d",&l);
printf("l = %d\n",l);
x=0;
k=log10(l)+1;
printf("k = %d\n",k);
for(j=m;j<l;j++)
{
sprintf(d,"%d",j);
for(p=1;p<k;p++)
{temp=d[0];
d[0]=d[k-1];
for(q=0;q<k-1;q++)
{
temp1=d[q+1];
d[q+1]=temp;
temp=temp1;
}
s=atoi(d);
/*printf("%d ",s);*/
if(s>j&&s<=l)
x++;
}
}

printf("Case #%d: %d\n",a,x);
fprintf(fp1,"Case #%d: %d\n",a,x);
a++;
}
fclose(fp);
}

fclose(fp1);

}
return 0;
}

