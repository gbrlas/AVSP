#include<stdio.h>
#include<string.h>
char des[101][102];
char giv[1001][102];
int hav[1001];
int was[1001];
void main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("test1.txt","w",stdout);
	int n,s,q;
	int i,j,sum,so,k;
	char ch;
	scanf("%d",&n);
	k=1;
	while(k<=n)
	{
		so=0;
		scanf("%d",&s);
		ch=getchar();
		for(i=0;i<s;i++)
			gets(des[i]);
		scanf("%d",&q);
		ch=getchar();
		memset(hav,0,sizeof(hav));
		memset(was,0,sizeof(was));
		for(i=0;i<q;i++)
		{
			gets(giv[i]);
			for(j=0;j<s;j++)
			{
				if(strcmp(giv[i],des[j])==0)
				{
					hav[i]=j;
					break;
				}
			}
		}
		i=0;
		sum=0;
		while(1)
		{
			if(i>=q)
				break;
			if(was[hav[i]]==0)
			{
				was[hav[i]]++;
				sum++;
				if(sum==s)
				{
					sum=1;
					so++;
					for(j=0;j<s;j++)
						was[j]=0;
					was[hav[i]]=1;
				}
			}
			i++;
		}
		printf("Case #%d: %d\n",k,so);
		k++;
	}
}

