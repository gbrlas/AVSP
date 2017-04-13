#include <stdio.h>
#include <string.h>

typedef __int64 int64;

void print(int icases,int64 c)
{
	printf("Case #%d: %I64d\n",icases,c);
}

int64 roll[1010];
int rlen[1010];
int sz[1010];
int round;
int rsize;
int rn;

int main()
{
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);

	int cases,icases;
	int i,j,k;
	int64 ans;

	scanf("%d",&cases);
	icases=1;

	while(icases<=cases)
	{
	
		scanf("%d %d %d",&round,&rsize,&rn);
		for(i=0;i<rn;i++)
			scanf("%d",&sz[i]);

		for(i=0;i<rn;i++)
		{
			roll[i]=0;
			rlen[i]=0;
			for(j=0;j<rn;j++)
			{
				k=i+j;
				if(k>=rn)
					k=k-rn;
				if(roll[i]>int64(rsize-sz[k]))
					break;
				roll[i]=roll[i]+sz[k];
				rlen[i]=j+1;
			}
		}
		ans=0;
		k=0;
		for(i=1;i<=round;i++)
		{
			if(rlen[k]==0)
				break;
			ans=ans+roll[k];
			k=k+rlen[k];
			if(k>=rn)
				k=k-rn;
		}
		print(icases,ans);
		icases++;
	}

	return 0;

}