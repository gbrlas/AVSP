#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int pk,k;
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A.out.txt","w",stdout);
	scanf("%d",&pk);
	for(k=1;k<=pk;k++)
	{
		int a[809],b[809];
		int n;
		scanf("%d",&n);
		int i,j;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++)
			scanf("%d",&b[i]);
		bool flag;
		do
		{
			flag=0;
			for(i=0;i<n;i++)
				for(j=i+1;j<n;j++)
					if(a[i]*b[i]+a[j]*b[j]>a[i]*b[j]+a[j]*b[i])
					{
						int tmp=a[i];
						a[i]=a[j];
						a[j]=tmp;
						flag=1;
					}
		}while(flag);
		int sum=0;
		for(i=0;i<n;i++)
			sum+=a[i]*b[i];
		printf("Case #%d: %d\n",k,sum);
	}
	return 0;
}