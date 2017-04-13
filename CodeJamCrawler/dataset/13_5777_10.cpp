#include<iostream.h>
#include<conio.h>
#include<stdio.h>


  int m=0;
void checksquare(int a)
{ m=0;
int sum=0,temp;
for(int i=1;i<=a;i++)
{if(a==i*i)
{temp=i;
while(temp>0)
{sum=sum*10+temp%10;
temp=temp/10;}
if(sum==i)
{m=1;}
return ;}}
	}





void main()
{FILE *fp ;
fp=fopen("hi","w");

int a,temp,sum=0,t,x[100][2];
cin>>a;
for(int s=0;s<a;s++)
{cin>>x[s][0]>>x[s][1];}

for(int i=0;i<a;i++)
{ t=0;


for(int j=x[i][0];j<=x[i][1];j++)
{sum=0,temp=j;
checksquare(j);
if(m==1)
{while(temp>0)
{sum=sum*10+temp%10;
temp=temp/10;} }

if(sum==j)
t++;  }

 cout<<"Case #"<<i+1<<":"<<t<<endl;

 fprintf(fp,"Case #%d: %d\n",i+1,t) ;

 }fclose(fp); }

