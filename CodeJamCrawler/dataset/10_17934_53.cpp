#include <stdio.h>

void main()
{
	int T,R,K,N,a[1000],x,y,i,j,tot,sum;
	FILE *ip,*op;
	ip=fopen("input.txt","r");
	op=fopen("output.txt","w");
	fscanf(ip,"%d",&T);
	for (i=0;i<T;i++)
	{
		tot=0;
		x=0;
		for (j=0;j<10;j++)
			a[j]=0;
		fscanf(ip,"%d %d %d",&R,&K,&N);//R:운행회수 K:정원 N:그룹수
		for (j=0;j<N;j++)
			fscanf(ip,"%d",&a[j]);
		for (j=0;j<R;j++)
		{
			sum=0;
			y=x;
			while(sum+a[x]<=K && (y!=x || sum==0))
			{
				sum+=a[x];
				x=(x+1)%N;
			}
			tot+=sum;
		}
		fprintf(op,"Case #%d: %d\n",i+1,tot);
	}
	fcloseall();
}