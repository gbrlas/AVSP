#include<iostream>
using namespace std;

int main()
{
	int i,j,k,l,n,m,t,kk,tt=0,a[555][25];
	char ch[555],cc[]="welcome to code jam";
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&t); gets(ch);
	kk=strlen(cc);
	while(t--)
	{
		gets(ch);
		n=strlen(ch);
		for(i=0;i<=n;i++)for(j=0;j<=kk;j++)a[i][j]=0;
		a[0][0]=1;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=kk;j++)
				if(ch[i-1] == cc[j-1]){
					for(k=0;k<i;k++){
						a[i][j]=(a[i][j]+a[k][j-1])%10000;
					}
				}
		}
		k=0;
		for(i=1;i<=n;i++)k+=a[i][kk];
		tt++;
		printf("Case #%d: %04d\n",tt,k%10000);
	}
	return 0;
}