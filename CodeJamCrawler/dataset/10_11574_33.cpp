#include<stdio.h>
#include<math.h>

int main()
{
	FILE *fi = fopen("A-large.in","r");
	FILE *fo = fopen("output.out","w");
	int T,N,K,i;
	fscanf(fi,"%d",&T);
	for(i = 1 ; i <= T ; i++)
	{
		fscanf(fi,"%d %d",&N,&K);
		if((K + 1) % (int)pow(2,N)) fprintf(fo,"Case #%d: OFF\n",i);
		else fprintf(fo,"Case #%d: ON\n",i);
	}
	return 0;
}