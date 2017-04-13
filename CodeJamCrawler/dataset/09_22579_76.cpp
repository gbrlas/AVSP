#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
using namespace std;
int pos[1000][100];
int num[1000]={0};
const char s[]="welcome to code jam";
char str[555];
int len,l,cont[100];
int main()
{
	int i,t,j,id,p,len=strlen(s);
	freopen("A.in","r",stdin);
	freopen("fuck.out","w",stdout);
	memset(pos,-1,sizeof(pos));
	for(i=0;i<len;i++)
	{
		pos[s[i]][num[s[i]]++]=i;
	}
	scanf("%d",&t);
	getchar();
	for(i=0;i<t;i++)
	{
         gets(str);
         l=strlen(str);
		 memset(cont,0,sizeof(cont));
		 for(j=0;j<l;j++)
		 {
		     for(p=0;p<num[str[j]];p++)
		     {
		     	id=pos[str[j]][p];
		     	if(id)
		     	{
		     		cont[id]+=cont[id-1];
		     	    cont[id]%=10000;
		     	}
				 else
				 {
		     	    cont[id]++;
		            cont[id]%=10000;
				 }
			 }
		 }
		 printf("Case #%d: ",i+1);
		 printf("%04d\n",cont[len-1]);
	}
	return 0;
}
