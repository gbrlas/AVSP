#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
int i,j,k,m,n,p,l,a=1,num,temp,real,x,y,t,q,s,o,z;double v,u;char c[200],d[4],e[16],f[16],g[16],h[16],*r;
FILE *fp,*fp1;
fp1=fopen("speaking_output.txt","w");
if(fp1!=NULL)
{
fp=fopen("speaking.txt","r");
if(fp!=NULL)
{
fscanf(fp,"%d\n",&n);
printf("n = %d\n",n);
for(i=1;i<=n;i++)
{
printf("Case #%d: ",a);
fprintf(fp1,"Case #%d: ",a);
a++;
r=fgets(c,200,fp);
for(j=0;j<strlen(r);j++)
{
if(c[j]=='a')
c[j]='y';
else if(c[j]=='b')
c[j]='h';
else if(c[j]=='c')																																																																																							 
c[j]='e';
else if(c[j]=='d')
c[j]='s';
else if(c[j]=='e')
c[j]='o';
else if(c[j]=='f')
c[j]='c';
else if(c[j]=='g')
c[j]='v';
else if(c[j]=='h')
c[j]='x';
else if(c[j]=='i')
c[j]='d';
else if(c[j]=='j')
c[j]='u';
else if(c[j]=='k')
c[j]='i';
else if(c[j]=='l')
c[j]='g';
else if(c[j]=='m')
c[j]='l';
else if(c[j]=='n')
c[j]='b';
else if(c[j]=='o')
c[j]='k';
else if(c[j]=='p')
c[j]='r';
else if(c[j]=='q')
c[j]='z';
else if(c[j]=='r')
c[j]='t';
else if(c[j]=='s')
c[j]='n';
else if(c[j]=='t')
c[j]='w';
else if(c[j]=='u')
c[j]='j';
else if(c[j]=='v')
c[j]='p';
else if(c[j]=='w')
c[j]='f';
else if(c[j]=='x')
c[j]='m';
else if(c[j]=='y')
c[j]='a';
else if(c[j]=='z')
c[j]='q';
else if(c[j]==' ')
c[j]=' ';
else 
continue;
printf("%c",c[j]);
fprintf(fp1,"%c",c[j]);

}
printf("\n");
fprintf(fp1,"\n");
}
fclose(fp);
}

fclose(fp1);

}
return 0;
}

