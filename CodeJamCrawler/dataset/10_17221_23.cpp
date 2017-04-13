#include<stdio.h>
int main()
{
  int red,blue,i,j,k,n,s2,test,count,flag=1,r,flag1,flag2;
  char s[100][100],s1[100][100],t;

freopen("A-large.in","r",stdin);
freopen("out.txt","w",stdout);
	scanf("%d",&test);
	for(s2=0;s2<test;s2++)
	{
	red=0; blue=0; flag=1;  flag1=flag2=0;
	for(i=0;i<100;i++)
	for(j=0;j<100;j++)
	s1[i][j]='0';
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
	scanf("%s",s[i]);
	
	for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
	   { s1[j][n-1-i]=s[i][j]; 
	  }// t=s[i][j]; s[i][j]=s[j][i]; s[j][i]=t; printf("%s\n",s[i]); }
   for(i=0;i<n;i++)
   s1[i][n]='\0';
/*   for(i=0;i<n;i++)
   {printf("%sdjf",s1[i]);
   printf("\n");}
  */ for(j=0;j<n;j++)
   {
   	flag=1;
   	for(i=n-1;i>=0;i--)
   	{
   		if(flag==1 && s1[i][j]=='.') { count=i; flag=0;}
   		if(flag==0 && s1[i][j]!='.') { t=s1[i][j]; s1[i][j]=s1[count][j]; s1[count][j]=t; count=count-1; }
   	}
   }
/*   for(i=0;i<n;i++)
 {  printf("%s",s1[i]);
   printf("\n");}
*/
for(i=0;i<n;i++)
for(j=0;j<n;j++)
{flag1=0; 
for(r=j;r<=k+j-1;r++)
  if(s1[i][r]!='R') { flag1=1; break;}
 if(flag1==0) red=1;
}
for(i=0;i<n;i++)
for(j=0;j<n;j++)

{flag1=0; 
for(r=j;r<=k+j-1;r++)
  if(s1[i][r]!='B') { flag1=1; break;}
 if(flag1==0) blue=1;
}
/*if(red==1&& blue==1) printf("Both");
else if(red==1) printf("Red");
else if(blue==1) printf("Blue");
else printf("neither");
*/
for(i=0;i<n;i++)
for(j=0;j<n;j++)
{flag1=0; 
for(r=i;r<=k+i-1;r++)
  if(s1[r][j]!='R') { flag1=1; break;}
 if(flag1==0) red=1;
}
for(i=0;i<n;i++)
for(j=0;j<n;j++)

{flag1=0; 
for(r=i;r<=k+i-1;r++)
  if(s1[r][j]!='B') { flag1=1; break;}
 if(flag1==0) blue=1;
}

for(i=0;i<n;i++)
for(j=0;j<n;j++)
{flag1=0; 
for(r=0;r<k;r++)
  if(s1[i+r][j+r]!='R') { flag1=1; break;}
 if(flag1==0) red=1;
}
for(i=0;i<n;i++)
for(j=0;j<n;j++)

{flag1=0; 
for(r=0;r<k;r++)
  if(s1[i+r][j+r]!='B') { flag1=1; break;}
 if(flag1==0) blue=1;
}

for(i=0;i<n;i++)
for(j=0;j<n;j++)
{flag1=0; 
for(r=0;r<k;r++)
  if(s1[i-r][j+r]!='R') { flag1=1; break;}
 if(flag1==0) red=1;
}
for(i=0;i<n;i++)
for(j=0;j<n;j++)

{flag1=0; 
for(r=0;r<k;r++)
  if(s1[i-r][j+r]!='B') { flag1=1; break;}
 if(flag1==0) blue=1;
}



if(red==1&& blue==1) printf("Case #%d: Both\n",s2+1);
else if(red==1) printf("Case #%d: Red\n",s2+1);
else if(blue==1) printf("Case #%d: Blue\n",s2+1);
else printf("Case #%d: Neither\n",s2+1);
}
}
