#include<stdio.h>
int main()
{
	int flag,i,j,n,p,me=0,i1,d,t;
	char s[7000][100],st[7000];
	freopen("a.in","r",stdin);
	freopen("b.txt","w",stdout);
	scanf("%d%d%d",&t,&n,&d);
	for(i=0;i<n;i++)
	
	scanf("%s",&s[i]);
 
	for(i1=0;i1<d;i1++)
	{
	scanf("%s",st);
	j=0;p=0; me=0;
	for(i=0;i<n;i++)
	{
	p=0; j=0;
	while(s[i][p]!='\0')
	{
	flag=0;
	if(st[j]=='(')
	   {
		 while(st[j]!=')')
		 {
		 	if(st[j]==s[i][p] && flag==0) { flag=1; j++; p++;}
		 	else j++;
		 }
		 j++;// printf("%c",st[j]);
	   }
   else if(s[i][p]==st[j]) { flag=1; j++; p++;}
	   if(flag==0) { break; }
	}
	if(flag==1) { me++; 	}
	}
	printf("Case #%d: %d\n",i1+1,me);
	}
}
