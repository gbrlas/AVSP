#include<stdio.h>
#include<string.h>

class STR
{
public:
char c[100];
int n;
};

int main()
{
FILE* fp;
int fun(FILE*);
int no_ip;
int i;
int ans;
fp=fopen("ip1","r");
fscanf(fp,"%d",&no_ip);
//printf("%d\n",no_ip);
for(i=0;i<no_ip;i++)
{
ans=fun(fp);
printf("Case #%d: %d\n",i+1,ans);
}





fclose(fp);

return 0;
}


int fun(FILE* fp)
{
int k,i;
int *series;
int len_series;
STR *s;
char st[100];
int no_switch=0;
int *flag;
int count;
int ai,j;
char dummy;
int store=0;
fscanf(fp,"%d",&k);
fscanf(fp,"%c",&dummy);
//printf("%d\n",k);
s=new STR[k];
for(i=0;i<k;i++)
{
fgets(s[i].c,100,fp);
s[i].n=i;
//printf("%s  \n",s[i].c);
}


fscanf(fp,"%d",&len_series);
fscanf(fp,"%c",&dummy);
flag=new int[len_series];
for(ai=0;ai<k;ai++)
{flag[ai]=0;}


count=0;
for(i=0;i<len_series;i++)
{
fgets(st,100,fp);
//str[strlen(str)-1]=0;
//printf("%s    \n   ",str);
for(j=0;j<k;j++)
{
if(strcmp(s[j].c,st)==0 && flag[j]!=1)
{count++;flag[j]=1;store=j;}
}
if(count==k)

{
no_switch++;
count=1;
for(ai=0;ai<k;ai++)
{flag[ai]=0;}
flag[store]=1;
//break;
}

for(ai=0;ai<100;ai++)
{st[ai]=0;}
}

//printf("%d\n",no_switch);












return no_switch ;

}
