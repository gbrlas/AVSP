#include<stdio.h>
#include<string.h>
int main()
{
	int r,sum,t1,t2,q,flag,test,i,j,n,m;
	char str[10000], s1[150][2000],s[150][2000],a[100][100],b[100][100];
	char *pch;
	freopen("a.in","r",stdin);
	freopen("out2.txt","w",stdout);
	
	scanf("%d",&test);
	for(q=0;q<test;q++)
	{
		sum=0;t1=t2=0;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	scanf("%s",s[i]);
	
	for(j=0;j<m;j++)
	scanf("%s",s1[j]);
	
	for(i=0;i<m;i++)
	 { flag=0;
	strcpy(str,"");		
		pch = strtok (s1[i],"/");
  while (pch != NULL)
  {
  	flag=0;
	  strcat(str,"/");
  	strcat(str,pch);
  		 for(j=0;j<n;j++)
	  if(strcmp(s[j],str)==0) {flag=1; break;}
	 if(flag==0){strcpy(s[n++],str); sum++;}
pch = strtok (NULL,"/");
//printf("%s\n",str);
  }
	 }
	 printf("Case #%d: %d\n",q+1,sum);
	}
}
