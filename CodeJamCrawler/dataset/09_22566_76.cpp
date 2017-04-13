#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int l,d,n;
char str[26][11];
char p[1001];
int len;
bool used[26][1000];
char matrix[11][30];
int num[11],cont;
bool flag;
int ans[501];
int main(void)
{
	int i,j,s;
	freopen("A.in","r",stdin);
	freopen("fuck.out","w",stdout);
	int a,b;
    scanf("%d%d%d",&l,&d,&n);  
	for(i=0;i<d;i++)
		scanf("%s",str[i]);
	memset(ans,0,sizeof(ans));
	for(i=0;i<n;i++)
	{
		scanf("%s",p);
		len=strlen(p);
		memset(used,false,sizeof(used));
		memset(num,0,sizeof(num));
		cont=0;
		flag=false;
		for(j=0;j<len;j++)
		{
		     if(p[j]=='(')
			    flag=true;
			 if(p[j]==')')
			 {
			    flag=false;
			    matrix[cont][num[cont]]=0;
			    cont++;
	         }
			 if(flag&&p[j]!='('	&&p[j]!=')')
			 	  matrix[cont][num[cont]++]=p[j];
		     else if(flag==false&&p[j]!='('&&p[j]!=')')
			 {
			 	matrix[cont][num[cont]++]=p[j];
			    matrix[cont][num[cont]]=0;	
			    cont++;
			 }
		}
		for(j=0;j<l;j++)
        {
            for(s=0;s<num[j];s++)
				used[matrix[j][s]-'a'][j]=true;
        }
        for(j=0;j<d;j++)
        {
		  for(s=0;s<l;s++)
          {
          	  if(used[str[j][s]-'a'][s]==false)
          	     break;
          }
          if(s>=l)
            ans[i]++;
		}
	}
	for(i=0;i<n;i++)
	   printf("Case #%d: %d\n",i+1,ans[i]);
	return 0;
}
