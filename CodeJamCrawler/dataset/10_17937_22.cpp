#include <stdio.h>

void main()
{
	int a[1000], b[1000],n,i,j,k,num,N;
	FILE *ip, *op;
	ip=fopen("input.txt","r");
	op=fopen("output.txt","w");
	fscanf(ip,"%d",&n);
	for (i=0;i<n;i++)
	{
		num=0;
		fscanf(ip,"%d",&N);
		for (j=0;j<N;j++)
			fscanf(ip,"%d %d",&a[j],&b[j]);
		for (j=0;j<N;j++)
		{
			for (k=j+1;k<N;k++)
			{
				if (a[j]<a[k] && b[k]<b[j])
					num++;
				if (a[k]<a[j] && b[j]<b[k])
					num++;
			}
		}
		fprintf(op,"Case #%d: %d\n",i+1,num);
	}
	fcloseall();
}