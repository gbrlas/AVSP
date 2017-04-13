#include <stdio.h>

void main()
{
	char p[30], s[30];
	int N,i,j,n,ok;
	long K,m;
	FILE *ip,*op;
	ip=fopen("input.txt","r");
	op=fopen("output.txt","w");
	fscanf(ip,"%d",&n);
	for (i=0;i<n;i++)
	{
		m=1;
		ok=0;
		fscanf(ip,"%d %d",&N,&K);
		for (j=0;j<N;j++)
			m*=2;
		if ((K+1)%m==0)
		{
			fprintf(op,"Case #%d: ON\n",i+1);
		}
		else
		{
			fprintf(op,"Case #%d: OFF\n",i+1);
		}
	}
	fcloseall();
}