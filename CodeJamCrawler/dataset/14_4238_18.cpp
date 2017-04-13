#include<stdio.h>
#include<string.h>
int getmin(int a,int b,int c)
{
	if(a<b)
	{
		if(a<c)
			return a;
		else
			return c;
	}
	else
	{
		if(b<c)
			return b;
		else
			return c;
	}
}
int main()
{
	freopen("A-small.in", "r", stdin);
    freopen("A-small.txt", "w", stdout);
	int t,T,n,mat[101][101],l,u,d,i,j,len1,len2,f;
	char str1[101],str2[101];
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		f=1;
		scanf("%d",&n);
		scanf("%s%s",str1,str2);
		len1=strlen(str1);
		len2=strlen(str2);
		mat[0][0]=0;
		for(i=1;i<=len1;i++)
			mat[i][0]=-1;
		for(i=1;i<=len2;i++)
			mat[0][i]=-1;
		for(i=1;i<=len1;i++)
		{
			for(j=1;j<=len2;j++)
			{
				if(mat[i-1][j-1]==-1&&mat[i-1][j]==-1&&mat[i][j-1]==-1)
					mat[i][j]=-1;
				else if(str1[i-1]==str2[j-1])
				{
					if(mat[i][j-1]>=0)
						l=mat[i][j-1];
					else
						l=999;
					if(mat[i-1][j]>=0)
						u=mat[i-1][j];
					else
						u=999;
					if(mat[i-1][j-1]>=0)
						d=mat[i-1][j-1];
					else
						d=999;
					l++;
					u++;
					mat[i][j]=getmin(l,d,u);
				}
				else
					mat[i][j]=-1;
			}
		}
		//printf("%s\n%s\n",str1,str2);
		if(mat[len1][len2]==-1)
			printf("Case #%d: Fegla Won\n",t);
		else
			printf("Case #%d: %d\n",t,mat[len1][len2]);
	}
}
