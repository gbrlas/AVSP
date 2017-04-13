
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

int main()
{
	freopen("a.txt","r",stdin);
	freopen("b.txt", "w", stdout);
	char ch[20]={"welcome to code jam"};
	//cout<<strlen(ch);
	
	char p[505];
	int i,j,k,len;
	int a[505][20];
	int n;
	scanf("%d",&n);
	getchar();
	for(int Case=1; Case<=n; Case++)
	{
		cin.getline(p,505);
		memset(a,0,sizeof(a));
		len=strlen(p);
		if(p[0]==ch[0]) a[0][0]=1;
		else a[0][0]=0;
		int sum;

		for(i=1; i<len ;i++)
		{
			if(ch[0]==p[i]) a[i][0]=1;
			else a[i][0]=0;

			for(j=1;j<=i&&j<19;j++)
			{
				sum=0;
				if(ch[j]==p[i])
				{
					for(k=0;k<i;k++)
					{
						sum+=a[k][j-1];
						sum%=10000;
					}
				}
				a[i][j]=sum;
			}
		}
/*
		for(i=0;i<len;i++){
			for(j=0;j<=i&&j<19;j++)
			{
				printf("%d ",a[i][j]); 
			}
			puts("");
		}
*/
		sum=0;
		for(i=18;i<len;i++)
		{
			sum+=a[i][18];
			sum%=10000;
		}
		printf("Case #%d: %04d\n",Case, sum);
	}
	return 0;
}