#include<stdio.h>
#include<string.h>

int main()
{
int i,j,k,n,ans,A[501];
char inp[501], B[20]="welcome to code jam";
scanf(" %d ",&n);

for(i=0;i<n;i++)
{
ans=0;
for(j=0;j<501;j++)A[j]=0;

gets(inp);

for(j=0;j<strlen(inp);j++)
{
	for(k=0;k<19;k++)
	{	
		if(B[k]==inp[j])
		{
			if(k==0)A[1]++;
			else if(k==18)ans+=A[18];
			else A[k+1]+=A[k];
			A[k+1]%=10000;
			ans%=10000;
		}
	}
}
ans%=10000;
printf("Case #%d: %04d\n",i+1,ans);
}
return 0;
}
